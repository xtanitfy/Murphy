#include "conv_layer.h"
#include "net.h"
#include "log.h"
#include "functions.h"


int ConvLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer);
int ConvLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer);
int ConvLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer);
#if defined(CONV_FAST)
int ConvLayerForwardFast(NET_PARA_s *pNetPara,LAYER_s *pLayer);
#endif

#if 0
int ConvLayer_register(NET_s *pNet,CONV_LAYER_PARA_s *pPara)
{
	CHECK_EXPR_RET(pPara == NULL,-1);

	LAYER_s *pLayer = (LAYER_s *)malloc(sizeof(LAYER_s));
	CHECK_EXPR_RET(pLayer == NULL,-1);
	memset(pLayer,'\0',sizeof(LAYER_s));
	
	CONV_LAYER_s *pConvLayer = (CONV_LAYER_s *)malloc(sizeof(CONV_LAYER_s));
	CHECK_EXPR_RET(pLayer == NULL,-1);
	memset(pConvLayer,'\0',sizeof(CONV_LAYER_s));
	memcpy(&pConvLayer->para,pPara,sizeof(CONV_LAYER_PARA_s));
	
	pLayer->type = LAYER_TYPE_CONV;
	pLayer->currLayer = pConvLayer;
	pLayer->init = ConvLayerInit;
	
	pLayer->backward = ConvLayerBackward;
#if defined(CONV_FAST)
	pLayer->forward = ConvLayerForwardFast;
#else
	pLayer->forward = ConvLayerForward;
#endif
	NET_addNames(pLayer,pPara->typeName,pPara->name,
					pPara->namePrev,pPara->nNamePrev);

	int ret = NET_Register(pNet,pLayer);
	CHECK_EXPR_RET(ret != 0,ret);
	
	return 0;
}
#endif


int ConvLayerInit(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	CHECK_EXPR_RET(pNetPara == NULL,-1);
	CHECK_EXPR_RET(pLayer == NULL,-1);
	
	CONV_LAYER_s *pConvLayer = (CONV_LAYER_s *)malloc(sizeof(CONV_LAYER_s));// = (CONV_LAYER_s *)pLayer->currLayer;
	CHECK_EXPR_RET(pConvLayer == NULL,-1);
	pLayer->currLayer = pConvLayer;

	CONV_LAYER_PARA_s *pPara = &pLayer->para->select.convLayer;

	int width =  (pLayer->pPrev[0]->pData->widthSize- pPara->kernelX)/pPara->strideX + 1;
	int height =  (pLayer->pPrev[0]->pData->heightSize- pPara->kernelY)/pPara->strideY + 1;
	pConvLayer->imgWidth = width;
	pConvLayer->imgheight = height;
	pConvLayer->imgSize = pConvLayer->imgWidth*pConvLayer->imgheight;

	CHECK_EXPR_RET(pLayer->pPrev[0]->pData == NULL,-1);
	NET_autoCreateBlob(pNetPara,pLayer->pPrev[0]->pData,&pLayer->pData,pPara->num,height,width,
						 pPara->kernelY,pPara->kernelX,&pLayer->k,&pLayer->b);
	#if 0
		BLOB_shapeLike(pLayer->pData,&pLayer->pDelta);
	#else
		BLOB_createAddPad(&pLayer->pDelta,pLayer->pData->numSize,
						pLayer->pData->channelSize,pLayer->pData->heightSize,
						pLayer->pData->widthSize,TRUE,pPara->kernelY-1,pPara->kernelX-1);
	#endif
	CHECK_EXPR_RET(pPara->weightInit == NULL,-1);
	pPara->weightInit(pLayer->k);

	CHECK_EXPR_RET(pPara->biasInit == NULL,-1);
	pPara->biasInit(pLayer->b);

	BLOB_shapeLike(pLayer->k,&pLayer->pDK);
	BLOB_shapeLike(pLayer->b,&pLayer->pDB);
	
	pLayer->strideX = pPara->strideX;
	pLayer->strideY = pPara->strideY;	

#if defined(CONV_FAST)
	/*暂时没有考虑stride*/
	BLOB_s *pK = pLayer->k;
	int kOutNum = pK->batches;
	int kInNum = pK->num;

	BLOB_s *pData = pLayer->pData;
	pConvLayer->matKWidth = kInNum * pK->width * pK->height * pK->channels;
	pConvLayer->matKHeight = kOutNum;
	
	/*展开a_in*/
	pConvLayer->matPrevAHeight = pConvLayer->matKWidth;
	pConvLayer->matPrevAWidth = pData->batches * pData->width * pData->height;

	pConvLayer->pMatPrevAData = (double *)malloc(sizeof(double) * \
					pConvLayer->matPrevAHeight * pConvLayer->matPrevAWidth);
	CHECK_EXPR_RET(pConvLayer->pMatPrevAData == NULL,-1);

	pConvLayer->pMatKRot180 = (double *)malloc(sizeof(double) * pLayer->k->size);
	CHECK_EXPR_RET(pConvLayer->pMatKRot180 == NULL,-1);
	
#endif

	
	return 0;
}

/*这里可以用conv的快速实现，譬如
	input:[h=28 w=28 n=12 batchSize=50]
	kernel:[kh=5 kw=5]
	计算的大矩阵为[(h-kh+1)*(w-kw+1)*n kh*kw batchSize] = [6912 25 50] 
				size = 8 640 000

	整合大矩阵的算法:
		for 1:channels
			for 1:batches
				for 1:inNum
					for 1:bigHeight
						for 1:bigWidth
						
	这里需要大矩阵的数据对原所有的神经元的所有的单位元素形成映射即:
			[bigHeight bigWidth]--(map)-->[imgHeightAll imgWidthAll]
*/

#if defined(CONV_FAST)
int ConvLayerForwardFast(LAYER_s *pLayer)
{
	
	CONV_LAYER_s *pConvLayer = (CONV_LAYER_s *)pLayer->currLayer;
	BLOB_s *pData = pLayer->pData;
	CONV_LAYER_PARA_s *pPara = &pConvLayer->para;

	BLOB_s *pPrevData = pLayer->pPrev[0]->pData;
	
	BLOB_DATA_PTR(pLayer->pData,ptrCurr);
	BLOB_DATA_PTR(pLayer->k,ptrK);
	BLOB_DATA_PTR(pPrevData,ptrPrevData);
	BLOB_DATA_PTR(pLayer->b,ptrB);

	int outNum = pLayer->k->batches;
	int inNum = pLayer->k->num;
	int kHeight = pLayer->k->height;
	int kWidth = pLayer->k->width;
	int kChannel = pLayer->k->channels;
	int dimK = kHeight * kWidth;

	//CalTimeStart();

	double (*ptrMatK)[outNum][pConvLayer->matKWidth] = \
				(double (*)[outNum][pConvLayer->matKWidth])pConvLayer->pMatKRot180;
	double (*pDim)[kHeight][kWidth] = NULL;
	int kSize = kHeight * kWidth; 
	/*展开权重 and rotate 180*/
	for (int ich = 0;ich < kChannel;ich++) {
		for (int iout = 0;iout < outNum;iout++) {
			int cnt = 0;
			for (int iin= 0;iin < inNum;iin++) {
				pDim = (double (*)[kHeight][kWidth])&ptrK[ich][iout][iin][0][0];
				for (int idim = kSize - 1;idim >= 0;idim--) {
					ptrMatK[ich][iout][cnt++]  = pDim[idim];
				}
			}
		}
	}
	

	int matPrevAHeight = pConvLayer->matPrevAHeight;
	int matPrevAWidth = pConvLayer->matPrevAWidth;
	int ah = pData->height;
	int aw = pData->width;
	int batches = (int)pData->batches;
	int kernelSize = kHeight * kWidth * kChannel;
	int hStride = pConvLayer->para.strideY;
	int wStride = pConvLayer->para.strideX;
	int i_b = 0,i_in = 0,i_h = 0,i_w = 0,ic = 0;
	int tmp = 0;
	int tmp1 = 0;
	int bx = 0,by = 0;
	int  aSize = aw * ah;
	int kDim = kWidth * kChannel;
	double (*ptrPrevMatA)[matPrevAWidth] = \
		(double (*)[matPrevAWidth])pConvLayer->pMatPrevAData;
	int runtimes=0;
#if 0
	/*have  some questions,will do if having free time*/
	for(int ih = 0;ih < matPrevAHeight;ih++) {
		for (int iw = 0;iw < matPrevAWidth;iw++) {
	
				i_b = iw / aSize;
				tmp = iw % aSize;
				by = tmp / aw;
				bx = tmp % aw;
				i_in = ih / kernelSize; 
				tmp1 = ih % kernelSize;
				i_h = bx * wStride + tmp1 / kDim;
				i_w = by * hStride + tmp1 % kDim; 
				
			for (int ic = 0;ic < kChannel;ic++) {
				ptrPrevMatA[ih][iw][ic] = ptrPrevData[i_b][i_in][i_h][i_w][ic];
				runtimes++;
			}
		}
	}
#else
	int blockMinX,blockMinY;
	int cntX = 0,cntY = 0;
	double (*ptrPrevMat)[matPrevAHeight][matPrevAWidth] = \
		(double (*)[[matPrevAHeight]][matPrevAWidth])pConvLayer->pMatPrevAData;
	int i_batch = 0,w = 0, h  = 0,i_channel = 0,offsetY = 0,offsetX;
	
	int wTmp = pPrevData->width - kWidth + 1;
	int hTmp = pPrevData->height - kHeight + 1;
	for (i_channel = 0;i_channel < kChannel;i_channel++) {
		for ( i_batch = 0;i_batch < batches;i_batch++) {
			for (w = 0;w < wTmp;w += wStride) {
				for (h = 0;h < hTmp;h += hStride) {
					cntX++;
					cntY = 0;
					for (i_in = 0;i_in < inNum;i_in++) {
						for (offsetY = h;offsetY < (h + kHeight);offsetY++) {
							for (offsetX = w;offsetX < (w + kWidth);offsetX++) {	
								ptrPrevMat[i_channel][cntY++][cntX] = ptrPrevData[i_channel][i_batch][i_in][offsetY][offsetX];
								runtimes++;
							}
						}
					}
				}
			}
		}
	}

#endif
	printf("Runtimes:%d\n",runtimes);

	int matKHeight = pConvLayer->matKHeight;
	int matKWidth = pConvLayer->matKWidth;
	int matAWidth = pConvLayer->matPrevAWidth;

	//CalTimeStart();
	//double (*ptrPrevMatA)[matAWidth][kChannel] = 
	//	(double (*)[matPrevAWidth][kChannel])pConvLayer->pMatPrevAData;
	double (*ptrMatk)[matKHeight][matKWidth] = \
					(double (*)[matKHeight][matKWidth])pConvLayer->pMatKRot180;
	double (*ptrCurrMatA)[matKWidth][matAWidth] = \
					(double (*)[matKWidth][matAWidth])pData->data;
	
	/*Matrix mutiply: K * A*/
	double sum = 0;
	for (int ic = 0;ic < kChannel;ic++) {
		for (int i = 0;i < matKHeight;i++) {
			for (int j = 0;j < matAWidth;j++) {
				sum = 0;
				for (int k = 0;k < matKWidth;k++) {
					sum  += ptrMatk[ic][i][k] * ptrCurrMatA[ic][k][j];
				}
				ptrCurrMatA[ic][i][j] = sum + ptrB[ic][0][matKHeight%outNum][0][0];
			}
		}
	}

	//CalTimeEnd("-------matrix muti");
	
	
	double *ptr  = pData->data;
	int outDim = pData->height * pData->width * pData->channels;

	CalTimeStart();
	printf("pData->size:%d\n",pData->size);
	for (int i = 0;i < pData->size; i++) {
		ptr[i]= pPara->function(ptr[i],FUNC_VALUE);
		//p[i][ic] = pPara->function(p[i][ic] + ptrB[0][(i/outDim)%outNum][0][0][ic],FUNC_VALUE);
	}
	CalTimeEnd("function");
	
	

	return 0;
}
#endif


int ConvLayerForward(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	CONV_LAYER_s *pConvLayer = (CONV_LAYER_s *)pLayer->currLayer;
	BLOB_s *pData = pLayer->pData;
	
	CONV_LAYER_PARA_s *pPara = &pLayer->para->select.convLayer;

	BLOB_s *pPrevData = pLayer->pPrev[0]->pData;
	
	BLOB_DATA_PTR(pLayer->pData,ptrCurr);
	BLOB_DATA_PTR(pLayer->k,ptrK);
	BLOB_DATA_PTR(pPrevData,ptrPrevData);
	BLOB_DATA_PTR(pLayer->b,ptrB);

	//CalTimeStart();
	int blockMinX = 0,blockMinY = 0;
	int ytmp = pPara->kernelY-1;
	int xtmp = pPara->kernelX-1;
	double tmp = 0;
	
	for (int i_batch = 0;i_batch < pData->numSize;i_batch++) {
		for (int i_out = 0;i_out < pData->channelSize;i_out++) {
			for (int h = 0;h < pConvLayer->imgheight;h++) {
				for (int w = 0;w < pConvLayer->imgWidth;w++) {
					tmp = 0;
					blockMinY = h*pPara->strideY;
					blockMinX = w*pPara->strideX;
					for (int i_in = 0;i_in < pPrevData->channelSize;i_in++) {
						for (int offsetY = blockMinY;offsetY < (blockMinY + pPara->kernelY);offsetY++) {
							for (int offsetX = blockMinX;offsetX < (blockMinX + pPara->kernelX);offsetX++) {	
								tmp += ptrK[i_out][i_in][ytmp-offsetY+blockMinY][xtmp-offsetX+blockMinX] * \
										ptrPrevData[i_batch][i_in][offsetY][offsetX];
								
							}
						}
					}	
					ptrCurr[i_batch][i_out][h][w]  = pPara->function(tmp + \
								ptrB[0][i_out][0][0],FUNC_VALUE);

				}
		
			}
			
		}
	}
	
	//CalTimeEnd("conv");

#if 0
	static int cnt = 0;
	cnt++;
	if (cnt == 1) {
		LOG_writeBlobToTxtFile("murphy_conv1.txt",pData);
		LOG_writeBlobToBinFile("murphy_conv1.bin",pData);
		LOG_compBinFile("murphy_conv1.bin","a1.bin",sizeof(BLOB_DATA_TYPE)*pData->size);
	}
#endif
	return 0;
}


int ConvLayerBackward(NET_PARA_s *pNetPara,LAYER_s *pLayer)
{
	CHECK_EXPR_RET(pLayer == NULL,-1);
	CONV_LAYER_PARA_s *pPara = &pLayer->para->select.convLayer;
	//CONV_LAYER_s *pConvLayer = (CONV_LAYER_s *)pLayer->currLayer;
	
	BLOB_s *pDataCurr = pLayer->pData;
	BLOB_s *pDeltaCurr = pLayer->pDelta;
	CHECK_EXPR_RET(pDataCurr == NULL,-1);
	CHECK_EXPR_RET(pDeltaCurr == NULL,-1);

	CHECK_EXPR_RET(pLayer->nNext <= 0,-1);
	BLOB_s *pDeltaNext = pLayer->pNext[0]->pDelta;
	CHECK_EXPR_RET(pDeltaNext == NULL,-1);
	int sampScale = pLayer->pNext[0]->sampScale;
	int sampScaleSquare = pLayer->pNext[0]->sampScale * pLayer->pNext[0]->sampScale;

	BLOB_DATA_PTR(pDeltaCurr,ptrDeltaCurr);
	BLOB_DATA_PTR(pDeltaNext,ptrDeltaNext);
	BLOB_DATA_PTR(pDataCurr,ptrDataCurr);
	FUNC function = pPara->function;

	int padx = pDeltaCurr->padx;
	int pady = pDeltaCurr->pady;

	for (int i_batch = 0;i_batch < pDataCurr->numSize;i_batch++) {
		for (int i_out = 0;i_out < pDataCurr->channelSize;i_out++) {
			for (int h = 0;h < pDataCurr->heightSize;h++) {
				for (int w = 0;w < pDataCurr->widthSize;w++) {
					ptrDeltaCurr[i_batch][i_out][h+pady][w+padx] = \
						function(ptrDataCurr[i_batch][i_out][h][w],FUNC_DERIVA) *\
						ptrDeltaNext[i_batch][i_out][h/sampScale][w/sampScale]/sampScaleSquare;
				}
			}
		}
	}
	
	#if 0
	if (strcmp(pLayer->name,"conv1") == 0) {
		LOG_writeBlobToTxtFile("conv1_delta.txt",pDeltaCurr);
	} else if (strcmp(pLayer->name,"conv0") == 0) {
		LOG_writeBlobToTxtFile("conv0_delta.txt",pDeltaCurr);
	}
	#endif


	CHECK_EXPR_RET(pLayer->pDB == NULL,-1);
	BLOB_DATA_PTR(pLayer->pDB,ptrDB);
	
	/*计算权重和偏置增量*/
//	OPTS_s *pOpts = NET_GetOpts();
//	double alpha = pOpts->alpha;
	//CHECK_EXPR_RET(pLayer->b == NULL,-1);
	//BLOB_DATA_PTR(pLayer->b,ptrB);
	double sum = 0;
	
	for (int i_out = 0;i_out < pDataCurr->channelSize;i_out++) {
		sum = 0;
		for (int i_batch = 0;i_batch < pDataCurr->numSize;i_batch++) {
			for (int h = 0;h < pDataCurr->heightSize;h++) {
				for (int w = 0;w < pDataCurr->widthSize;w++) {
					sum += ptrDeltaCurr[i_batch][i_out][h+pady][w+padx];
				}
			}
		}
		ptrDB[0][i_out][0][0] = sum/pDataCurr->numSize;
	}	
	

#if 0
	if (strcmp(pLayer->name,"conv0") == 0) {
		LOG_writeBlobToTxtFile("conv0_db.txt",pLayer->pDB);
		
	} else if(strcmp(pLayer->name,"conv1") == 0) {
		LOG_writeBlobToTxtFile("conv1_db.txt",pLayer->pDB);
	}
#endif

	CHECK_EXPR_RET(pLayer->nPrev <= 0,-1);
	BLOB_s *pDataPrev = pLayer->pPrev[0]->pData;
	CHECK_EXPR_RET(pDataPrev == NULL,-1);

	BLOB_s *pDK = pLayer->pDK;
	CHECK_EXPR_RET(pDK == NULL,-1);
	BLOB_DATA_PTR(pDK,ptrDK);
	BLOB_DATA_PTR(pDataPrev,ptrDataPrev);

	int blockMinX = 0,blockMinY = 0;
	double tmp = 0;
	int ytmp = pDataPrev->heightSize-1;
	int xtmp = pDataPrev->widthSize-1;
	int y1tmp = pDataCurr->heightSize-1+pady;
	int x1tmp = pDataCurr->widthSize-1+padx;

	//CHECK_EXPR_RET(pLayer->k == NULL,-1);
	//BLOB_DATA_PTR(pLayer->k,ptrK);
	
	for (int i_out = 0;i_out < pDataCurr->channelSize;i_out++) {	
		for (int h = 0;h < pDK->heightSize;h++) {
			for (int w = 0;w < pDK->widthSize;w++) {
				for (int i_in = 0;i_in < pDataPrev->channelSize;i_in++) {
					blockMinY = h;
					blockMinX = w;
					tmp = 0;
					for (int i_batch = 0;i_batch < pDataCurr->numSize;i_batch++) {
						for (int offsetY = blockMinY;offsetY < (blockMinY + pDataCurr->heightSize);offsetY++) {
							for (int offsetX = blockMinX;offsetX < (blockMinX + pDataCurr->widthSize);offsetX++) {	
								tmp += ptrDataPrev[i_batch][i_in][ytmp-offsetY][xtmp-offsetX] * \
										ptrDeltaCurr[i_batch][i_out][y1tmp-offsetY+blockMinY][x1tmp-offsetX+blockMinX];
							}
						}
					}
					ptrDK[i_out][i_in][h][w] = tmp / pDataCurr->numSize;
				}
			}
		}
	}

	return 0;
}


