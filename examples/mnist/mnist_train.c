#include "mnist_read_input.h"
#include "net.h"
#include "data_layer.h"
#include "functions.h"
#include "conv_layer.h"
#include "samp_layer.h"
#include "linear_layer.h"
#include "test_layer.h"
#include "output_layer.h"
#include "platform_comm.h"

#define TEST_BATCHES_DIM 1

#define TRAIN_X_FILE "data/mnist/train_x_28_28_1000.bin"
#define TRAIN_Y_FILE "data/mnist/train_y_10_1_1000.bin"
#define TEST_X_FILE  "data/mnist/test_x_28_28_500.bin"
#define TEST_Y_FILE  "data/mnist/test_y_10_500.bin"

static double *gTrainX = NULL; 
static double *gTrainY = NULL;
static double *gTestX = NULL; 
static double *gTestY = NULL;

static NET_s *pNetTrain = NULL;
static NET_s *pNetTest = NULL;
static NET_PARA_s netTrainPara;

static void print(float *data,SIZE_s *pSize)
{
	float (*ptr)[pSize->h][pSize->w] = (float (*)[pSize->h][pSize->w])data;	
	for (int n = 0;n < 2;n++) {
		for (int h = 0;h < pSize->h;h++) {
			for (int w = 0;w < pSize->w;w++) {
				printf("%f ",ptr[n][h][w]);
			}
			printf("\n");
		}
	}
	
}

/*测试网络需要拷贝已经训练好的模型的参数*/
int MnistBuildTrainNet(int batchSize,int h,int w)
{

#if 0
	DATA_LAYER_PARA_s inputPara;
	inputPara.hSize = h;
	inputPara.wSize = w;
	inputPara.channelSize = 1;
	strcpy(inputPara.typeName,"data");
	strcpy(inputPara.name,"data");
	int ret = DataLayer_register(pNetTrain,&inputPara);
	CHECK_EXPR_RET(ret != 0,ret);
#else
	LAYER_PARA_s para;
	para.select.dataLayer.hSize = h;
	para.select.dataLayer.wSize = w;
	para.select.dataLayer.channelSize = w;
	strcpy(para.typeName,"data");
	strcpy(para.name,"data");
	int ret = NET_addLayer(pNetTrain,&para);
	CHECK_EXPR_RET(ret != 0,ret);
#endif

#if 0
	CONV_LAYER_PARA_s convPara;
	memset(&convPara,0,sizeof(convPara));
	convPara.function = sigmoidExt;
	convPara.weightInit = weightInit;
	convPara.biasInit = biasInit;
	convPara.num = 6;
	convPara.kernelX = 5;
	convPara.kernelY = 5;
	convPara.strideX = 1;
	convPara.strideY = 1;
	strcpy(convPara.typeName,"conv");
	strcpy(convPara.name,"conv0");
	strcpy(convPara.namePrev[convPara.nNamePrev++],"data");
	ret = ConvLayer_register(pNetTrain,&convPara);
	CHECK_EXPR_RET(ret != 0,ret);
#else
	memset(&para,0,sizeof(para));
	para.select.convLayer.function = sigmoidExt;
	para.select.convLayer.weightInit = weightInit;
	para.select.convLayer.biasInit = biasInit;
	para.select.convLayer.num = 6;
	para.select.convLayer.kernelX = 5;
	para.select.convLayer.kernelY = 5;
	para.select.convLayer.strideX = 1;
	para.select.convLayer.strideY = 1;
	strcpy(para.typeName,"conv");
	strcpy(para.name,"conv0");
	strcpy(para.namePrev[para.nNamePrev++],"data");
	ret = NET_addLayer(pNetTrain,&para);
	CHECK_EXPR_RET(ret != 0,-1);
#endif

#if 0
	SAMP_LAYER_PARA_s sampPara;
	memset(&sampPara,0,sizeof(sampPara));
	sampPara.type = SAMP_TYPE_AVERAGE;
	sampPara.stride = 2;
	strcpy(sampPara.typeName,"samp");
	strcpy(sampPara.name,"samp0");
	strcpy(sampPara.namePrev[sampPara.nNamePrev++],"conv0");
	ret = SampLayer_register(pNetTrain,&sampPara);
	CHECK_EXPR_RET(ret != 0,ret);
#else
	memset(&para,0,sizeof(para));
	para.select.sampLayer.type = SAMP_TYPE_AVERAGE;
	para.select.sampLayer.stride = 2;
	strcpy(para.typeName,"samp");
	strcpy(para.name,"samp0");
	strcpy(para.namePrev[para.nNamePrev++],"conv0");
	ret = NET_addLayer(pNetTrain,&para);
	CHECK_EXPR_RET(ret != 0,ret);
#endif


#if 0
	CONV_LAYER_PARA_s convPara1;
	memset(&convPara1,0,sizeof(convPara1));
	convPara1.function = sigmoidExt;
	convPara1.weightInit = weightInit;
	convPara1.biasInit = biasInit;
	convPara1.num = 12;
	convPara1.kernelX = 5;
	convPara1.kernelY = 5;
	convPara1.strideX = 1;
	convPara1.strideY = 1;
	strcpy(convPara1.typeName,"conv");
	strcpy(convPara1.name,"conv1");
	strcpy(convPara1.namePrev[convPara1.nNamePrev++],"samp0");
	ret = ConvLayer_register(pNetTrain,&convPara1);
	CHECK_EXPR_RET(ret != 0,ret);
#else
	memset(&para,0,sizeof(para));
	para.select.convLayer.function = sigmoidExt;
	para.select.convLayer.weightInit = weightInit;
	para.select.convLayer.biasInit = biasInit;
	para.select.convLayer.num = 12;
	para.select.convLayer.kernelX = 5;
	para.select.convLayer.kernelY = 5;
	para.select.convLayer.strideX = 1;
	para.select.convLayer.strideY = 1;
	strcpy(para.typeName,"conv");
	strcpy(para.name,"conv1");
	strcpy(para.namePrev[para.nNamePrev++],"samp0");
	ret = NET_addLayer(pNetTrain,&para);
	CHECK_EXPR_RET(ret != 0,ret);
#endif

#if 0
	SAMP_LAYER_PARA_s sampPara1;
	memset(&sampPara1,0,sizeof(sampPara1));
	sampPara1.type = SAMP_TYPE_AVERAGE;
	sampPara1.stride = 2;
	strcpy(sampPara1.typeName,"samp");
	strcpy(sampPara1.name,"samp1");
	strcpy(sampPara1.namePrev[sampPara1.nNamePrev++],"conv1");
	ret = SampLayer_register(pNetTrain,&sampPara1);
	CHECK_EXPR_RET(ret != 0,ret);
#else
	memset(&para,0,sizeof(para));
	para.select.sampLayer.type = SAMP_TYPE_AVERAGE;
	para.select.sampLayer.stride = 2;
	strcpy(para.typeName,"samp");
	strcpy(para.name,"samp1");
	strcpy(para.namePrev[para.nNamePrev++],"conv1");
	ret = NET_addLayer(pNetTrain,&para);
	CHECK_EXPR_RET(ret != 0,ret);
#endif

#if 0
	LINEAR_LAYER_PARA_s linearPara;
	memset(&linearPara,0,sizeof(linearPara));
	strcpy(linearPara.typeName,"linear");
	strcpy(linearPara.name,"linear0");
	strcpy(linearPara.namePrev[linearPara.nNamePrev++],"samp1");
	LinearLayer_register(pNetTrain,&linearPara);
#else
	memset(&para,0,sizeof(para));
	strcpy(para.typeName,"linear");
	strcpy(para.name,"linear0");
	strcpy(para.namePrev[para.nNamePrev++],"samp1");
	ret = NET_addLayer(pNetTrain,&para);
	CHECK_EXPR_RET(ret != 0,ret);
#endif


#if 0	
	OUTPUT_LAYER_PARA_s outputPara;
	memset(&outputPara,0,sizeof(outputPara));
	strcpy(outputPara.typeName,"output");
	strcpy(outputPara.name,"output");
	strcpy(outputPara.namePrev[outputPara.nNamePrev++],"linear0");
	outputPara.num = 10;
	outputPara.function = sigmoidExt;
	outputPara.weightInit = Mnist_GetInitFw;
	outputPara.biasInit = biasInit;
	OutputLayer_register(pNetTrain,&outputPara);
#else
	memset(&para,0,sizeof(para));
	strcpy(para.typeName,"output");
	strcpy(para.name,"output");
	strcpy(para.namePrev[para.nNamePrev++],"linear0");
	para.select.outputLayer.num = 10;
	para.select.outputLayer.function = sigmoidExt;
	para.select.outputLayer.weightInit = Mnist_GetInitFw;
	para.select.outputLayer.biasInit = biasInit;
	ret = NET_addLayer(pNetTrain,&para);
	CHECK_EXPR_RET(ret != 0,ret);
#endif

	NET_printForward(pNetTrain);
	NET_printBackward(pNetTrain);

	return 0;
}


int MnistTrainRun(SIZE_s *pTrainXSize,SIZE_s *pTrainYSize)
{
	int ret = -1;
	//int batchCnt = pTrainXSize->n / netTrainPara.batchsize;
	int batchCnt = 1;
	int xdim = netTrainPara.batchsize * pTrainXSize->h * pTrainXSize->w;
	int ydim = netTrainPara.batchsize * pTrainYSize->h * pTrainYSize->w;
	int testCnt = 0;

	for (int i = 0;i < batchCnt;i++){
		//CalTimeStart();
		printf("=======Batches:%d==========\n",i);
		NET_setInputData(pNetTrain,gTrainX + xdim * i,xdim);
		NET_setTableYData(pNetTrain,gTrainY + ydim * i,ydim);

		//CalTimeStart();
		ret = NET_Forward(pNetTrain);
		CHECK_EXPR_RET(ret != 0,-1);
		//CalTimeEnd("NET_Forward");
		
		//CalTimeStart();
		ret = NET_Backward(pNetTrain);
		CHECK_EXPR_RET(ret != 0,-1);
		//CalTimeEnd("NET_Backward");

		//CalTimeStart();
		ret = NET_Update(pNetTrain);
		CHECK_EXPR_RET(ret != 0,-1);
		//CalTimeEnd("NET_Update");

		double loss = NET_GetLoss(pNetTrain,"output");
		printf("Output loss:%lf\n",loss);
		//CalTimeEnd("all");

	}
	return 0;
}

int main(void)
{
	int ret = -1;

	/*获取样本数据*/
	SIZE_s trainXSize;
	ret = Mnist_GetData(TRAIN_X_FILE,&gTrainX,&trainXSize);
	CHECK_EXPR_RET(ret,-1);
	
	SIZE_s trainYSize;
	ret = Mnist_GetData(TRAIN_Y_FILE,&gTrainY,&trainYSize);
	CHECK_EXPR_RET(ret,-1);

	SIZE_s testXSize;
	ret = Mnist_GetData(TEST_X_FILE,&gTestX,&testXSize);
	CHECK_EXPR_RET(ret,-1);
	Mnist_PrintSize("testX",&testXSize);
	
	SIZE_s testYSize;
	ret = Mnist_GetData(TRAIN_Y_FILE,&gTestY,&testYSize);
	CHECK_EXPR_RET(ret,-1);
	Mnist_PrintSize("testY",&testYSize);
	
	//Mnist_dataNormalie(gTrainX,&trainXSize);

#if 0
	/*初始化管理器*/
	OPTS_s opts;
	opts.alpha = 1;
	opts.batchsize = 50;
	opts.numepochs = 1;
	opts.channels = 1;//sizeof(double);
	opts.loss_function = functionLoss1;
	opts.classifyNum = 10;
	ret = NET_init(&opts);
	CHECK_EXPR_RET(ret != 0,ret);
#else
	
	netTrainPara.alpha = 1;
	netTrainPara.batchsize = 50;
	netTrainPara.numepochs = 1;
	netTrainPara.channels = 1;//sizeof(double);
	netTrainPara.loss_function = functionLoss1;
	netTrainPara.classifyNum = 10;
	pNetTrain = NET_create(&netTrainPara);
#endif


	MnistBuildTrainNet(netTrainPara.batchsize,trainXSize.h,trainXSize.w);

	MnistTrainRun(&trainXSize,&trainYSize);


	/*这里需要重新构建测试网络，因为batches发生了变化*/
#if 0
	OPTS_s *pOPts = NET_GetOpts();
	pOPts->batchsize = testXSize.n;
	CHECK_EXPR_RET(inputPara.hSize != testXSize.h,-1);
	CHECK_EXPR_RET(inputPara.wSize != testXSize.w,-1);
	
	int testXAllSize = pOPts->batchsize * testXSize.h * testXSize.w;
	NET_setInputData(gTestX,testXAllSize);

	int testYAllSize = pOPts->batchsize * testYSize.h * testYSize.w;
	NET_setTableYData(gTestY,testYAllSize);

	ret = NET_test();
	CHECK_EXPR_RET(ret != 0,-1);
#endif
	return 0;
}
