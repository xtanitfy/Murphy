#include <stdio.h>
#include <stdlib.h>
#include "conv_layer.h"
#include "net.h"
#include "log.h"
#include "samp_layer.h"

int SampLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer);
int SampLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer);
int SampLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer);

#if 0
int SampLayer_register(NET_s *pNet,SAMP_LAYER_PARA_s *pPara)
{
	CHECK_EXPR_RET(pPara == NULL,-1);
	
	LAYER_s *pLayer = (LAYER_s *)malloc(sizeof(LAYER_s));
	CHECK_EXPR_RET(pLayer == NULL,-1);
	memset(pLayer,'\0',sizeof(LAYER_s));
	
	SAMP_LAYER_s *pSampLayer = (SAMP_LAYER_s *)malloc(sizeof(SAMP_LAYER_s));
	CHECK_EXPR_RET(pSampLayer == NULL,-1);
	memset(pSampLayer,'\0',sizeof(SAMP_LAYER_s));
	memcpy(&pSampLayer->para,pPara,sizeof(SAMP_LAYER_PARA_s));
	
	pLayer->type = LAYER_TYPE_SAMPLE;
	pLayer->currLayer = pSampLayer;
	pLayer->init = SampLayerInit;
	pLayer->forward = SampLayerForward;
	pLayer->backward = SampLayerBackward;
	pLayer->sampScale = pPara->stride;
	NET_addNames(pLayer,pPara->typeName,pPara->name,pPara->namePrev,pPara->nNamePrev);
	
	int ret = NET_Register(pNet,pLayer);
	CHECK_EXPR_RET(ret != 0,ret);
	
	return 0;
}
#endif

int SampLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	SAMP_LAYER_PARA_s *pPara = &pLayer->para->select.sampLayer;

	BLOB_s *pPrevBlob = pLayer->pPrev[0]->pData;
	CHECK_EXPR_RET(pPrevBlob->widthSize% pPara->stride != 0,-1);
	CHECK_EXPR_RET(pPrevBlob->heightSize% pPara->stride != 0,-1);

	int width =  pPrevBlob->widthSize/ pPara->stride;
	int height =  pPrevBlob->heightSize/ pPara->stride;

	int ret = BLOB_create(&pLayer->pData,pNetPara->batchsize,pPrevBlob->channelSize,\
			width,height,TRUE);
	CHECK_EXPR_RET(ret != 0,-1);
	
	ret = BLOB_shapeLike(pLayer->pData,&pLayer->pDelta);
	CHECK_EXPR_RET(ret != 0,-1);
	pLayer->sampScale = pPara->stride;

	return 0;
}

int SampLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	SAMP_LAYER_PARA_s *pPara = &pLayer->para->select.sampLayer;

	BLOB_s *pPrevBlob = pLayer->pPrev[0]->pData;
	int nx =  pPrevBlob->widthSize/ pPara->stride;
	int ny =  pPrevBlob->heightSize/ pPara->stride;

	BLOB_s *pData = pLayer->pData;
	BLOB_DATA_PTR(pData,ptrCurr);
	BLOB_DATA_PTR(pPrevBlob,ptrPrev);
	double scale = (double)1 / (pPara->stride * pPara->stride);
	int xStart = 0,yStart = 0;
	
	
	for (int i_batch = 0;i_batch < pData->numSize;i_batch++) {
		for (int i_out = 0;i_out < pData->channelSize;i_out++) {
			for (int y =0;y < ny;y++) {
				for (int x = 0;x < nx;x++) {
					yStart = y * pPara->stride;
					xStart = x * pPara->stride;
					ptrCurr[i_batch][i_out][y][x] = 0;
					for (int by = yStart; by < yStart + pPara->stride;by++) {
						for (int bx = xStart; bx < xStart + pPara->stride;bx++) {
							ptrCurr[i_batch][i_out][y][x] += \
									ptrPrev[i_batch][i_out][by][bx] * scale;
						}
					}
				}
			}
		}
	}
	
	return 0;
}


int SampLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	CHECK_EXPR_RET(pLayer == NULL,-1);

	/*此时delta已经被linear层所更新*/
	if (strcmp(pLayer->pNext[0]->para->typeName,"linear") == 0) {
		//LOG_writeBlobToTxtFile("sample1_delta.txt",pLayer->pDelta);		
	} else if (strcmp(pLayer->pNext[0]->para->typeName,"conv") == 0) {
		CHECK_EXPR_RET(pLayer->nNext <= 0,-1);
		BLOB_s *pDeltaNext = pLayer->pNext[0]->pDelta;
		CHECK_EXPR_RET(pDeltaNext == NULL,-1);
		BLOB_s *pDeltaCurr = pLayer->pDelta;
		CHECK_EXPR_RET(pDeltaCurr == NULL,-1);
		BLOB_s *pKNext = pLayer->pNext[0]->k;

		BLOB_DATA_PTR(pDeltaNext,ptrDeltaNext);
		BLOB_DATA_PTR(pDeltaCurr,ptrDeltaCurr);
		BLOB_DATA_PTR(pKNext,ptrKNext);

		int  blockMinY = 0;
		int  blockMinX = 0;
		double tmp = 0;
		int ky = 0;
		int kx = 0;
		
		int strideX = pLayer->pNext[0]->strideX;
		int strideY = pLayer->pNext[0]->strideY;
		/*[h,w]+pad[kh-1,kw-1] conv [kh,kw]-->[(h+(kh-1)*2-kh+1),(w+(kw-1)*2-kw+1)]-->[h+kh-1,w+kw-1]*/
 		
		for (int i_batch = 0;i_batch < pDeltaCurr->numSize;i_batch++) {
			for (int i_out = 0;i_out < pDeltaCurr->channelSize;i_out++) {
				for (int h = 0;h < pDeltaCurr->heightSize;h++) {
					for (int w = 0;w < pDeltaCurr->widthSize;w++) {
						tmp = 0;
						blockMinY = h * strideY;
						blockMinX = w * strideX;
						for (int i_outNext = 0;i_outNext < pDeltaNext->channelSize;i_outNext++) {
							for (int offsetY = blockMinY;offsetY < (blockMinY + pKNext->heightSize);offsetY++) {
								for (int offsetX = blockMinX;offsetX < (blockMinX + pKNext->widthSize);offsetX++) {	
									ky = offsetY - blockMinY;
									kx = offsetX - blockMinX;		
									tmp += ptrKNext[i_outNext][i_out][ky][kx] * \
											ptrDeltaNext[i_batch][i_outNext][offsetY][offsetX];
									
								}
							}
						}
						ptrDeltaCurr[i_batch][i_out][h][w] = tmp;
					}		
				}
				
			}
		}

		#if 0
		LOG_writeBlobToTxtFile("sample0_delta.txt",pDeltaCurr);	
		#endif
	}

	
	return 0;
}


