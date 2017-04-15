#include "parameter.h"
int parse(NetParameter * netParameter)
{
	CHECK_EXPR_RET(strlen("VGG_ILSVRC_16_layer") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->name,"VGG_ILSVRC_16_layer");
	netParameter->input = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->input_size = 1;
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->input[0],"data");
	netParameter->input_dim = (INT32 *)malloc(sizeof(INT32)*4);
	netParameter->input_dim_size = 4;
	netParameter->input_dim[0] = 10;
	netParameter->input_dim[1] = 3;
	netParameter->input_dim[2] = 224;
	netParameter->input_dim[3] = 224;
	netParameter->layer = (LayerParameter *)malloc(sizeof(LayerParameter)*39);
	netParameter->layer_size = 39;
	netParameter->layer[0].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[0].bottom_size = 1;
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].bottom[0],"data");
	netParameter->layer[0].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[0].top_size = 1;
	CHECK_EXPR_RET(strlen("conv1_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].top[0],"conv1_1");
	CHECK_EXPR_RET(strlen("conv1_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].name,"conv1_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].type,"Convolution");

	//Give default values begin:
	netParameter->layer[0].convolution_param.bias_term = true;//default value
	netParameter->layer[0].convolution_param.pad_h = 0;//default value
	netParameter->layer[0].convolution_param.pad_w = 0;//default value
	netParameter->layer[0].convolution_param.group = 1;//default value
	netParameter->layer[0].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[0].convolution_param.axis = 1;//default value
	netParameter->layer[0].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[0].convolution_param.num_output = 64;
	netParameter->layer[0].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[0].convolution_param.pad_size = 1;
	netParameter->layer[0].convolution_param.pad[0] = 1;
	netParameter->layer[0].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[0].convolution_param.kernel_size_size = 1;
	netParameter->layer[0].convolution_param.kernel_size[0] = 3;
	netParameter->layer[1].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[1].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv1_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].bottom[0],"conv1_1");
	netParameter->layer[1].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[1].top_size = 1;
	CHECK_EXPR_RET(strlen("conv1_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].top[0],"conv1_1");
	CHECK_EXPR_RET(strlen("relu1_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].name,"relu1_1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].type,"ReLU");
	netParameter->layer[2].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[2].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv1_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].bottom[0],"conv1_1");
	netParameter->layer[2].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[2].top_size = 1;
	CHECK_EXPR_RET(strlen("conv1_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].top[0],"conv1_2");
	CHECK_EXPR_RET(strlen("conv1_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].name,"conv1_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].type,"Convolution");

	//Give default values begin:
	netParameter->layer[2].convolution_param.bias_term = true;//default value
	netParameter->layer[2].convolution_param.pad_h = 0;//default value
	netParameter->layer[2].convolution_param.pad_w = 0;//default value
	netParameter->layer[2].convolution_param.group = 1;//default value
	netParameter->layer[2].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[2].convolution_param.axis = 1;//default value
	netParameter->layer[2].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[2].convolution_param.num_output = 64;
	netParameter->layer[2].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[2].convolution_param.pad_size = 1;
	netParameter->layer[2].convolution_param.pad[0] = 1;
	netParameter->layer[2].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[2].convolution_param.kernel_size_size = 1;
	netParameter->layer[2].convolution_param.kernel_size[0] = 3;
	netParameter->layer[3].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[3].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv1_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].bottom[0],"conv1_2");
	netParameter->layer[3].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[3].top_size = 1;
	CHECK_EXPR_RET(strlen("conv1_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].top[0],"conv1_2");
	CHECK_EXPR_RET(strlen("relu1_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].name,"relu1_2");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].type,"ReLU");
	netParameter->layer[4].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[4].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv1_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].bottom[0],"conv1_2");
	netParameter->layer[4].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[4].top_size = 1;
	CHECK_EXPR_RET(strlen("pool1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].top[0],"pool1");
	CHECK_EXPR_RET(strlen("pool1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].name,"pool1");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].type,"Pooling");

	//Give default values begin:
	netParameter->layer[4].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[4].pooling_param.pad = 0;//default value
	netParameter->layer[4].pooling_param.pad_h = 0;//default value
	netParameter->layer[4].pooling_param.pad_w = 0;//default value
	netParameter->layer[4].pooling_param.stride = 1;//default value
	netParameter->layer[4].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[4].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[4].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[4].pooling_param.kernel_size = 2;
	netParameter->layer[4].pooling_param.stride = 2;
	netParameter->layer[5].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[5].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].bottom[0],"pool1");
	netParameter->layer[5].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[5].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].top[0],"conv2_1");
	CHECK_EXPR_RET(strlen("conv2_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].name,"conv2_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].type,"Convolution");

	//Give default values begin:
	netParameter->layer[5].convolution_param.bias_term = true;//default value
	netParameter->layer[5].convolution_param.pad_h = 0;//default value
	netParameter->layer[5].convolution_param.pad_w = 0;//default value
	netParameter->layer[5].convolution_param.group = 1;//default value
	netParameter->layer[5].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[5].convolution_param.axis = 1;//default value
	netParameter->layer[5].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[5].convolution_param.num_output = 128;
	netParameter->layer[5].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[5].convolution_param.pad_size = 1;
	netParameter->layer[5].convolution_param.pad[0] = 1;
	netParameter->layer[5].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[5].convolution_param.kernel_size_size = 1;
	netParameter->layer[5].convolution_param.kernel_size[0] = 3;
	netParameter->layer[6].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[6].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].bottom[0],"conv2_1");
	netParameter->layer[6].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[6].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].top[0],"conv2_1");
	CHECK_EXPR_RET(strlen("relu2_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].name,"relu2_1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].type,"ReLU");
	netParameter->layer[7].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[7].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].bottom[0],"conv2_1");
	netParameter->layer[7].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[7].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].top[0],"conv2_2");
	CHECK_EXPR_RET(strlen("conv2_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].name,"conv2_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].type,"Convolution");

	//Give default values begin:
	netParameter->layer[7].convolution_param.bias_term = true;//default value
	netParameter->layer[7].convolution_param.pad_h = 0;//default value
	netParameter->layer[7].convolution_param.pad_w = 0;//default value
	netParameter->layer[7].convolution_param.group = 1;//default value
	netParameter->layer[7].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[7].convolution_param.axis = 1;//default value
	netParameter->layer[7].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[7].convolution_param.num_output = 128;
	netParameter->layer[7].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[7].convolution_param.pad_size = 1;
	netParameter->layer[7].convolution_param.pad[0] = 1;
	netParameter->layer[7].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[7].convolution_param.kernel_size_size = 1;
	netParameter->layer[7].convolution_param.kernel_size[0] = 3;
	netParameter->layer[8].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[8].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].bottom[0],"conv2_2");
	netParameter->layer[8].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[8].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].top[0],"conv2_2");
	CHECK_EXPR_RET(strlen("relu2_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].name,"relu2_2");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].type,"ReLU");
	netParameter->layer[9].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[9].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].bottom[0],"conv2_2");
	netParameter->layer[9].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[9].top_size = 1;
	CHECK_EXPR_RET(strlen("pool2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].top[0],"pool2");
	CHECK_EXPR_RET(strlen("pool2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].name,"pool2");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].type,"Pooling");

	//Give default values begin:
	netParameter->layer[9].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[9].pooling_param.pad = 0;//default value
	netParameter->layer[9].pooling_param.pad_h = 0;//default value
	netParameter->layer[9].pooling_param.pad_w = 0;//default value
	netParameter->layer[9].pooling_param.stride = 1;//default value
	netParameter->layer[9].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[9].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[9].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[9].pooling_param.kernel_size = 2;
	netParameter->layer[9].pooling_param.stride = 2;
	netParameter->layer[10].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[10].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].bottom[0],"pool2");
	netParameter->layer[10].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[10].top_size = 1;
	CHECK_EXPR_RET(strlen("conv3_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].top[0],"conv3_1");
	CHECK_EXPR_RET(strlen("conv3_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].name,"conv3_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].type,"Convolution");

	//Give default values begin:
	netParameter->layer[10].convolution_param.bias_term = true;//default value
	netParameter->layer[10].convolution_param.pad_h = 0;//default value
	netParameter->layer[10].convolution_param.pad_w = 0;//default value
	netParameter->layer[10].convolution_param.group = 1;//default value
	netParameter->layer[10].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[10].convolution_param.axis = 1;//default value
	netParameter->layer[10].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[10].convolution_param.num_output = 256;
	netParameter->layer[10].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[10].convolution_param.pad_size = 1;
	netParameter->layer[10].convolution_param.pad[0] = 1;
	netParameter->layer[10].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[10].convolution_param.kernel_size_size = 1;
	netParameter->layer[10].convolution_param.kernel_size[0] = 3;
	netParameter->layer[11].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[11].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv3_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].bottom[0],"conv3_1");
	netParameter->layer[11].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[11].top_size = 1;
	CHECK_EXPR_RET(strlen("conv3_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].top[0],"conv3_1");
	CHECK_EXPR_RET(strlen("relu3_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].name,"relu3_1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].type,"ReLU");
	netParameter->layer[12].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[12].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv3_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].bottom[0],"conv3_1");
	netParameter->layer[12].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[12].top_size = 1;
	CHECK_EXPR_RET(strlen("conv3_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].top[0],"conv3_2");
	CHECK_EXPR_RET(strlen("conv3_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].name,"conv3_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].type,"Convolution");

	//Give default values begin:
	netParameter->layer[12].convolution_param.bias_term = true;//default value
	netParameter->layer[12].convolution_param.pad_h = 0;//default value
	netParameter->layer[12].convolution_param.pad_w = 0;//default value
	netParameter->layer[12].convolution_param.group = 1;//default value
	netParameter->layer[12].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[12].convolution_param.axis = 1;//default value
	netParameter->layer[12].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[12].convolution_param.num_output = 256;
	netParameter->layer[12].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[12].convolution_param.pad_size = 1;
	netParameter->layer[12].convolution_param.pad[0] = 1;
	netParameter->layer[12].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[12].convolution_param.kernel_size_size = 1;
	netParameter->layer[12].convolution_param.kernel_size[0] = 3;
	netParameter->layer[13].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[13].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv3_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].bottom[0],"conv3_2");
	netParameter->layer[13].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[13].top_size = 1;
	CHECK_EXPR_RET(strlen("conv3_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].top[0],"conv3_2");
	CHECK_EXPR_RET(strlen("relu3_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].name,"relu3_2");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].type,"ReLU");
	netParameter->layer[14].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[14].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv3_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].bottom[0],"conv3_2");
	netParameter->layer[14].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[14].top_size = 1;
	CHECK_EXPR_RET(strlen("conv3_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].top[0],"conv3_3");
	CHECK_EXPR_RET(strlen("conv3_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].name,"conv3_3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].type,"Convolution");

	//Give default values begin:
	netParameter->layer[14].convolution_param.bias_term = true;//default value
	netParameter->layer[14].convolution_param.pad_h = 0;//default value
	netParameter->layer[14].convolution_param.pad_w = 0;//default value
	netParameter->layer[14].convolution_param.group = 1;//default value
	netParameter->layer[14].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[14].convolution_param.axis = 1;//default value
	netParameter->layer[14].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[14].convolution_param.num_output = 256;
	netParameter->layer[14].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[14].convolution_param.pad_size = 1;
	netParameter->layer[14].convolution_param.pad[0] = 1;
	netParameter->layer[14].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[14].convolution_param.kernel_size_size = 1;
	netParameter->layer[14].convolution_param.kernel_size[0] = 3;
	netParameter->layer[15].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[15].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv3_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].bottom[0],"conv3_3");
	netParameter->layer[15].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[15].top_size = 1;
	CHECK_EXPR_RET(strlen("conv3_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].top[0],"conv3_3");
	CHECK_EXPR_RET(strlen("relu3_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].name,"relu3_3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].type,"ReLU");
	netParameter->layer[16].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[16].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv3_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[16].bottom[0],"conv3_3");
	netParameter->layer[16].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[16].top_size = 1;
	CHECK_EXPR_RET(strlen("pool3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[16].top[0],"pool3");
	CHECK_EXPR_RET(strlen("pool3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[16].name,"pool3");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[16].type,"Pooling");

	//Give default values begin:
	netParameter->layer[16].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[16].pooling_param.pad = 0;//default value
	netParameter->layer[16].pooling_param.pad_h = 0;//default value
	netParameter->layer[16].pooling_param.pad_w = 0;//default value
	netParameter->layer[16].pooling_param.stride = 1;//default value
	netParameter->layer[16].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[16].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[16].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[16].pooling_param.kernel_size = 2;
	netParameter->layer[16].pooling_param.stride = 2;
	netParameter->layer[17].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[17].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].bottom[0],"pool3");
	netParameter->layer[17].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[17].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].top[0],"conv4_1");
	CHECK_EXPR_RET(strlen("conv4_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].name,"conv4_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].type,"Convolution");

	//Give default values begin:
	netParameter->layer[17].convolution_param.bias_term = true;//default value
	netParameter->layer[17].convolution_param.pad_h = 0;//default value
	netParameter->layer[17].convolution_param.pad_w = 0;//default value
	netParameter->layer[17].convolution_param.group = 1;//default value
	netParameter->layer[17].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[17].convolution_param.axis = 1;//default value
	netParameter->layer[17].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[17].convolution_param.num_output = 512;
	netParameter->layer[17].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[17].convolution_param.pad_size = 1;
	netParameter->layer[17].convolution_param.pad[0] = 1;
	netParameter->layer[17].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[17].convolution_param.kernel_size_size = 1;
	netParameter->layer[17].convolution_param.kernel_size[0] = 3;
	netParameter->layer[18].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[18].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[18].bottom[0],"conv4_1");
	netParameter->layer[18].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[18].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[18].top[0],"conv4_1");
	CHECK_EXPR_RET(strlen("relu4_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[18].name,"relu4_1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[18].type,"ReLU");
	netParameter->layer[19].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[19].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].bottom[0],"conv4_1");
	netParameter->layer[19].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[19].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].top[0],"conv4_2");
	CHECK_EXPR_RET(strlen("conv4_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].name,"conv4_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].type,"Convolution");

	//Give default values begin:
	netParameter->layer[19].convolution_param.bias_term = true;//default value
	netParameter->layer[19].convolution_param.pad_h = 0;//default value
	netParameter->layer[19].convolution_param.pad_w = 0;//default value
	netParameter->layer[19].convolution_param.group = 1;//default value
	netParameter->layer[19].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[19].convolution_param.axis = 1;//default value
	netParameter->layer[19].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[19].convolution_param.num_output = 512;
	netParameter->layer[19].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[19].convolution_param.pad_size = 1;
	netParameter->layer[19].convolution_param.pad[0] = 1;
	netParameter->layer[19].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[19].convolution_param.kernel_size_size = 1;
	netParameter->layer[19].convolution_param.kernel_size[0] = 3;
	netParameter->layer[20].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[20].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[20].bottom[0],"conv4_2");
	netParameter->layer[20].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[20].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[20].top[0],"conv4_2");
	CHECK_EXPR_RET(strlen("relu4_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[20].name,"relu4_2");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[20].type,"ReLU");
	netParameter->layer[21].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[21].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].bottom[0],"conv4_2");
	netParameter->layer[21].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[21].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].top[0],"conv4_3");
	CHECK_EXPR_RET(strlen("conv4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].name,"conv4_3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].type,"Convolution");

	//Give default values begin:
	netParameter->layer[21].convolution_param.bias_term = true;//default value
	netParameter->layer[21].convolution_param.pad_h = 0;//default value
	netParameter->layer[21].convolution_param.pad_w = 0;//default value
	netParameter->layer[21].convolution_param.group = 1;//default value
	netParameter->layer[21].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[21].convolution_param.axis = 1;//default value
	netParameter->layer[21].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[21].convolution_param.num_output = 512;
	netParameter->layer[21].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[21].convolution_param.pad_size = 1;
	netParameter->layer[21].convolution_param.pad[0] = 1;
	netParameter->layer[21].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[21].convolution_param.kernel_size_size = 1;
	netParameter->layer[21].convolution_param.kernel_size[0] = 3;
	netParameter->layer[22].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[22].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].bottom[0],"conv4_3");
	netParameter->layer[22].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[22].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].top[0],"conv4_3");
	CHECK_EXPR_RET(strlen("relu4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].name,"relu4_3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].type,"ReLU");
	netParameter->layer[23].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[23].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[23].bottom[0],"conv4_3");
	netParameter->layer[23].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[23].top_size = 1;
	CHECK_EXPR_RET(strlen("pool4") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[23].top[0],"pool4");
	CHECK_EXPR_RET(strlen("pool4") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[23].name,"pool4");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[23].type,"Pooling");

	//Give default values begin:
	netParameter->layer[23].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[23].pooling_param.pad = 0;//default value
	netParameter->layer[23].pooling_param.pad_h = 0;//default value
	netParameter->layer[23].pooling_param.pad_w = 0;//default value
	netParameter->layer[23].pooling_param.stride = 1;//default value
	netParameter->layer[23].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[23].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[23].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[23].pooling_param.kernel_size = 2;
	netParameter->layer[23].pooling_param.stride = 2;
	netParameter->layer[24].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[24].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool4") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].bottom[0],"pool4");
	netParameter->layer[24].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[24].top_size = 1;
	CHECK_EXPR_RET(strlen("conv5_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].top[0],"conv5_1");
	CHECK_EXPR_RET(strlen("conv5_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].name,"conv5_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].type,"Convolution");

	//Give default values begin:
	netParameter->layer[24].convolution_param.bias_term = true;//default value
	netParameter->layer[24].convolution_param.pad_h = 0;//default value
	netParameter->layer[24].convolution_param.pad_w = 0;//default value
	netParameter->layer[24].convolution_param.group = 1;//default value
	netParameter->layer[24].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[24].convolution_param.axis = 1;//default value
	netParameter->layer[24].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[24].convolution_param.num_output = 512;
	netParameter->layer[24].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[24].convolution_param.pad_size = 1;
	netParameter->layer[24].convolution_param.pad[0] = 1;
	netParameter->layer[24].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[24].convolution_param.kernel_size_size = 1;
	netParameter->layer[24].convolution_param.kernel_size[0] = 3;
	netParameter->layer[25].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[25].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv5_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].bottom[0],"conv5_1");
	netParameter->layer[25].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[25].top_size = 1;
	CHECK_EXPR_RET(strlen("conv5_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].top[0],"conv5_1");
	CHECK_EXPR_RET(strlen("relu5_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].name,"relu5_1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].type,"ReLU");
	netParameter->layer[26].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[26].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv5_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].bottom[0],"conv5_1");
	netParameter->layer[26].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[26].top_size = 1;
	CHECK_EXPR_RET(strlen("conv5_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].top[0],"conv5_2");
	CHECK_EXPR_RET(strlen("conv5_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].name,"conv5_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].type,"Convolution");

	//Give default values begin:
	netParameter->layer[26].convolution_param.bias_term = true;//default value
	netParameter->layer[26].convolution_param.pad_h = 0;//default value
	netParameter->layer[26].convolution_param.pad_w = 0;//default value
	netParameter->layer[26].convolution_param.group = 1;//default value
	netParameter->layer[26].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[26].convolution_param.axis = 1;//default value
	netParameter->layer[26].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[26].convolution_param.num_output = 512;
	netParameter->layer[26].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[26].convolution_param.pad_size = 1;
	netParameter->layer[26].convolution_param.pad[0] = 1;
	netParameter->layer[26].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[26].convolution_param.kernel_size_size = 1;
	netParameter->layer[26].convolution_param.kernel_size[0] = 3;
	netParameter->layer[27].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[27].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv5_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].bottom[0],"conv5_2");
	netParameter->layer[27].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[27].top_size = 1;
	CHECK_EXPR_RET(strlen("conv5_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].top[0],"conv5_2");
	CHECK_EXPR_RET(strlen("relu5_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].name,"relu5_2");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].type,"ReLU");
	netParameter->layer[28].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[28].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv5_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].bottom[0],"conv5_2");
	netParameter->layer[28].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[28].top_size = 1;
	CHECK_EXPR_RET(strlen("conv5_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].top[0],"conv5_3");
	CHECK_EXPR_RET(strlen("conv5_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].name,"conv5_3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].type,"Convolution");

	//Give default values begin:
	netParameter->layer[28].convolution_param.bias_term = true;//default value
	netParameter->layer[28].convolution_param.pad_h = 0;//default value
	netParameter->layer[28].convolution_param.pad_w = 0;//default value
	netParameter->layer[28].convolution_param.group = 1;//default value
	netParameter->layer[28].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[28].convolution_param.axis = 1;//default value
	netParameter->layer[28].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[28].convolution_param.num_output = 512;
	netParameter->layer[28].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[28].convolution_param.pad_size = 1;
	netParameter->layer[28].convolution_param.pad[0] = 1;
	netParameter->layer[28].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[28].convolution_param.kernel_size_size = 1;
	netParameter->layer[28].convolution_param.kernel_size[0] = 3;
	netParameter->layer[29].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[29].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv5_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].bottom[0],"conv5_3");
	netParameter->layer[29].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[29].top_size = 1;
	CHECK_EXPR_RET(strlen("conv5_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].top[0],"conv5_3");
	CHECK_EXPR_RET(strlen("relu5_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].name,"relu5_3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].type,"ReLU");
	netParameter->layer[30].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[30].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv5_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[30].bottom[0],"conv5_3");
	netParameter->layer[30].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[30].top_size = 1;
	CHECK_EXPR_RET(strlen("pool5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[30].top[0],"pool5");
	CHECK_EXPR_RET(strlen("pool5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[30].name,"pool5");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[30].type,"Pooling");

	//Give default values begin:
	netParameter->layer[30].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[30].pooling_param.pad = 0;//default value
	netParameter->layer[30].pooling_param.pad_h = 0;//default value
	netParameter->layer[30].pooling_param.pad_w = 0;//default value
	netParameter->layer[30].pooling_param.stride = 1;//default value
	netParameter->layer[30].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[30].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[30].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[30].pooling_param.kernel_size = 2;
	netParameter->layer[30].pooling_param.stride = 2;
	netParameter->layer[31].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[31].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].bottom[0],"pool5");
	netParameter->layer[31].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[31].top_size = 1;
	CHECK_EXPR_RET(strlen("fc6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].top[0],"fc6");
	CHECK_EXPR_RET(strlen("fc6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].name,"fc6");
	CHECK_EXPR_RET(strlen("InnerProduct") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].type,"InnerProduct");

	//Give default values begin:
	netParameter->layer[31].inner_product_param.bias_term = true;//default value
	netParameter->layer[31].inner_product_param.axis = 1;//default value
	netParameter->layer[31].inner_product_param.transpose = false;//default value
	//Give default values end

	netParameter->layer[31].inner_product_param.num_output = 4096;
	netParameter->layer[32].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[32].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[32].bottom[0],"fc6");
	netParameter->layer[32].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[32].top_size = 1;
	CHECK_EXPR_RET(strlen("fc6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[32].top[0],"fc6");
	CHECK_EXPR_RET(strlen("relu6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[32].name,"relu6");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[32].type,"ReLU");
	netParameter->layer[33].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[33].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].bottom[0],"fc6");
	netParameter->layer[33].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[33].top_size = 1;
	CHECK_EXPR_RET(strlen("fc6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].top[0],"fc6");
	CHECK_EXPR_RET(strlen("drop6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].name,"drop6");
	CHECK_EXPR_RET(strlen("Dropout") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].type,"Dropout");

	//Give default values begin:
	netParameter->layer[33].dropout_param.dropout_ratio = 0.5;//default value
	//Give default values end

	netParameter->layer[33].dropout_param.dropout_ratio = 0.5;
	netParameter->layer[34].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[34].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[34].bottom[0],"fc6");
	netParameter->layer[34].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[34].top_size = 1;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[34].top[0],"fc7");
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[34].name,"fc7");
	CHECK_EXPR_RET(strlen("InnerProduct") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[34].type,"InnerProduct");

	//Give default values begin:
	netParameter->layer[34].inner_product_param.bias_term = true;//default value
	netParameter->layer[34].inner_product_param.axis = 1;//default value
	netParameter->layer[34].inner_product_param.transpose = false;//default value
	//Give default values end

	netParameter->layer[34].inner_product_param.num_output = 4096;
	netParameter->layer[35].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[35].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].bottom[0],"fc7");
	netParameter->layer[35].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[35].top_size = 1;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].top[0],"fc7");
	CHECK_EXPR_RET(strlen("relu7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].name,"relu7");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].type,"ReLU");
	netParameter->layer[36].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[36].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].bottom[0],"fc7");
	netParameter->layer[36].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[36].top_size = 1;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].top[0],"fc7");
	CHECK_EXPR_RET(strlen("drop7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].name,"drop7");
	CHECK_EXPR_RET(strlen("Dropout") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].type,"Dropout");

	//Give default values begin:
	netParameter->layer[36].dropout_param.dropout_ratio = 0.5;//default value
	//Give default values end

	netParameter->layer[36].dropout_param.dropout_ratio = 0.5;
	netParameter->layer[37].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[37].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].bottom[0],"fc7");
	netParameter->layer[37].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[37].top_size = 1;
	CHECK_EXPR_RET(strlen("fc8") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].top[0],"fc8");
	CHECK_EXPR_RET(strlen("fc8") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].name,"fc8");
	CHECK_EXPR_RET(strlen("InnerProduct") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].type,"InnerProduct");

	//Give default values begin:
	netParameter->layer[37].inner_product_param.bias_term = true;//default value
	netParameter->layer[37].inner_product_param.axis = 1;//default value
	netParameter->layer[37].inner_product_param.transpose = false;//default value
	//Give default values end

	netParameter->layer[37].inner_product_param.num_output = 1000;
	netParameter->layer[38].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[38].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc8") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].bottom[0],"fc8");
	netParameter->layer[38].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[38].top_size = 1;
	CHECK_EXPR_RET(strlen("prob") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].top[0],"prob");
	CHECK_EXPR_RET(strlen("prob") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].name,"prob");
	CHECK_EXPR_RET(strlen("Softmax") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].type,"Softmax");
	return 0;

}
