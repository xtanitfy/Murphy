#include "parameter.h"
int parse(NetParameter * netParameter)
{
	CHECK_EXPR_RET(strlen("GoogleNet") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->name,"GoogleNet");
	netParameter->layer = (LayerParameter *)malloc(sizeof(LayerParameter)*143);
	netParameter->layer_size = 143;
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].name,"data");
	CHECK_EXPR_RET(strlen("Input") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].type,"Input");
	netParameter->layer[0].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[0].top_size = 1;
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].top[0],"data");
	netParameter->layer[0].input_param.shape = (BlobShape *)malloc(sizeof(BlobShape)*1);
	netParameter->layer[0].input_param.shape_size = 1;
	netParameter->layer[0].input_param.shape[0].dim = (INT64 *)malloc(sizeof(INT64)*4);
	netParameter->layer[0].input_param.shape[0].dim_size = 4;
	netParameter->layer[0].input_param.shape[0].dim[0] = 10;
	netParameter->layer[0].input_param.shape[0].dim[1] = 3;
	netParameter->layer[0].input_param.shape[0].dim[2] = 224;
	netParameter->layer[0].input_param.shape[0].dim[3] = 224;
	CHECK_EXPR_RET(strlen("conv1/7x7_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].name,"conv1/7x7_s2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].type,"Convolution");
	netParameter->layer[1].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[1].bottom_size = 1;
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].bottom[0],"data");
	netParameter->layer[1].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[1].top_size = 1;
	CHECK_EXPR_RET(strlen("conv1/7x7_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].top[0],"conv1/7x7_s2");
	netParameter->layer[1].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[1].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[1].param[i].lr_mult = 1.0;//default value
		netParameter->layer[1].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[1].param[0].lr_mult = 1;
	netParameter->layer[1].param[0].decay_mult = 1;
	netParameter->layer[1].param[1].lr_mult = 2;
	netParameter->layer[1].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[1].convolution_param.bias_term = true;//default value
	netParameter->layer[1].convolution_param.pad_h = 0;//default value
	netParameter->layer[1].convolution_param.pad_w = 0;//default value
	netParameter->layer[1].convolution_param.group = 1;//default value
	netParameter->layer[1].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[1].convolution_param.axis = 1;//default value
	netParameter->layer[1].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[1].convolution_param.num_output = 64;
	netParameter->layer[1].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[1].convolution_param.pad_size = 1;
	netParameter->layer[1].convolution_param.pad[0] = 3;
	netParameter->layer[1].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[1].convolution_param.kernel_size_size = 1;
	netParameter->layer[1].convolution_param.kernel_size[0] = 7;
	netParameter->layer[1].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[1].convolution_param.stride_size = 1;
	netParameter->layer[1].convolution_param.stride[0] = 2;

	//Give default values begin:
	strcpy(netParameter->layer[1].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[1].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[1].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[1].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[1].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[1].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[1].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[1].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[1].convolution_param.weight_filler.std = 0.1;

	//Give default values begin:
	strcpy(netParameter->layer[1].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[1].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[1].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[1].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[1].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[1].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[1].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[1].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].convolution_param.bias_filler.type,"constant");
	netParameter->layer[1].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("conv1/relu_7x7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].name,"conv1/relu_7x7");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].type,"ReLU");
	netParameter->layer[2].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[2].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv1/7x7_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].bottom[0],"conv1/7x7_s2");
	netParameter->layer[2].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[2].top_size = 1;
	CHECK_EXPR_RET(strlen("conv1/7x7_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].top[0],"conv1/7x7_s2");
	CHECK_EXPR_RET(strlen("pool1/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].name,"pool1/3x3_s2");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].type,"Pooling");
	netParameter->layer[3].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[3].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv1/7x7_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].bottom[0],"conv1/7x7_s2");
	netParameter->layer[3].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[3].top_size = 1;
	CHECK_EXPR_RET(strlen("pool1/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].top[0],"pool1/3x3_s2");

	//Give default values begin:
	netParameter->layer[3].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[3].pooling_param.pad = 0;//default value
	netParameter->layer[3].pooling_param.pad_h = 0;//default value
	netParameter->layer[3].pooling_param.pad_w = 0;//default value
	netParameter->layer[3].pooling_param.stride = 1;//default value
	netParameter->layer[3].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[3].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[3].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[3].pooling_param.kernel_size = 3;
	netParameter->layer[3].pooling_param.stride = 2;
	CHECK_EXPR_RET(strlen("pool1/norm1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].name,"pool1/norm1");
	CHECK_EXPR_RET(strlen("LRN") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].type,"LRN");
	netParameter->layer[4].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[4].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool1/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].bottom[0],"pool1/3x3_s2");
	netParameter->layer[4].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[4].top_size = 1;
	CHECK_EXPR_RET(strlen("pool1/norm1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].top[0],"pool1/norm1");

	//Give default values begin:
	netParameter->layer[4].lrn_param.local_size = 5;//default value
	netParameter->layer[4].lrn_param.alpha = 1.;//default value
	netParameter->layer[4].lrn_param.beta = 0.75;//default value
	netParameter->layer[4].lrn_param.norm_region = LRNParameter_NormRegion_ACROSS_CHANNELS;//default value
	netParameter->layer[4].lrn_param.k = 1.;//default value
	netParameter->layer[4].lrn_param.engine = LRNParameter_Engine_DEFAULT;//default value
	//Give default values end

	netParameter->layer[4].lrn_param.local_size = 5;
	netParameter->layer[4].lrn_param.alpha = 0.0001;
	netParameter->layer[4].lrn_param.beta = 0.75;
	CHECK_EXPR_RET(strlen("conv2/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].name,"conv2/3x3_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].type,"Convolution");
	netParameter->layer[5].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[5].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool1/norm1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].bottom[0],"pool1/norm1");
	netParameter->layer[5].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[5].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].top[0],"conv2/3x3_reduce");
	netParameter->layer[5].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[5].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[5].param[i].lr_mult = 1.0;//default value
		netParameter->layer[5].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[5].param[0].lr_mult = 1;
	netParameter->layer[5].param[0].decay_mult = 1;
	netParameter->layer[5].param[1].lr_mult = 2;
	netParameter->layer[5].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[5].convolution_param.bias_term = true;//default value
	netParameter->layer[5].convolution_param.pad_h = 0;//default value
	netParameter->layer[5].convolution_param.pad_w = 0;//default value
	netParameter->layer[5].convolution_param.group = 1;//default value
	netParameter->layer[5].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[5].convolution_param.axis = 1;//default value
	netParameter->layer[5].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[5].convolution_param.num_output = 64;
	netParameter->layer[5].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[5].convolution_param.kernel_size_size = 1;
	netParameter->layer[5].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[5].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[5].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[5].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[5].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[5].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[5].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[5].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[5].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[5].convolution_param.weight_filler.std = 0.1;

	//Give default values begin:
	strcpy(netParameter->layer[5].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[5].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[5].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[5].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[5].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[5].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[5].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[5].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].convolution_param.bias_filler.type,"constant");
	netParameter->layer[5].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("conv2/relu_3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].name,"conv2/relu_3x3_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].type,"ReLU");
	netParameter->layer[6].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[6].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].bottom[0],"conv2/3x3_reduce");
	netParameter->layer[6].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[6].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].top[0],"conv2/3x3_reduce");
	CHECK_EXPR_RET(strlen("conv2/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].name,"conv2/3x3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].type,"Convolution");
	netParameter->layer[7].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[7].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].bottom[0],"conv2/3x3_reduce");
	netParameter->layer[7].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[7].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].top[0],"conv2/3x3");
	netParameter->layer[7].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[7].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[7].param[i].lr_mult = 1.0;//default value
		netParameter->layer[7].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[7].param[0].lr_mult = 1;
	netParameter->layer[7].param[0].decay_mult = 1;
	netParameter->layer[7].param[1].lr_mult = 2;
	netParameter->layer[7].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[7].convolution_param.bias_term = true;//default value
	netParameter->layer[7].convolution_param.pad_h = 0;//default value
	netParameter->layer[7].convolution_param.pad_w = 0;//default value
	netParameter->layer[7].convolution_param.group = 1;//default value
	netParameter->layer[7].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[7].convolution_param.axis = 1;//default value
	netParameter->layer[7].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[7].convolution_param.num_output = 192;
	netParameter->layer[7].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[7].convolution_param.pad_size = 1;
	netParameter->layer[7].convolution_param.pad[0] = 1;
	netParameter->layer[7].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[7].convolution_param.kernel_size_size = 1;
	netParameter->layer[7].convolution_param.kernel_size[0] = 3;

	//Give default values begin:
	strcpy(netParameter->layer[7].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[7].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[7].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[7].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[7].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[7].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[7].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[7].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[7].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[7].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[7].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[7].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[7].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[7].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[7].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[7].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[7].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].convolution_param.bias_filler.type,"constant");
	netParameter->layer[7].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("conv2/relu_3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].name,"conv2/relu_3x3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].type,"ReLU");
	netParameter->layer[8].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[8].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].bottom[0],"conv2/3x3");
	netParameter->layer[8].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[8].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].top[0],"conv2/3x3");
	CHECK_EXPR_RET(strlen("conv2/norm2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].name,"conv2/norm2");
	CHECK_EXPR_RET(strlen("LRN") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].type,"LRN");
	netParameter->layer[9].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[9].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].bottom[0],"conv2/3x3");
	netParameter->layer[9].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[9].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2/norm2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].top[0],"conv2/norm2");

	//Give default values begin:
	netParameter->layer[9].lrn_param.local_size = 5;//default value
	netParameter->layer[9].lrn_param.alpha = 1.;//default value
	netParameter->layer[9].lrn_param.beta = 0.75;//default value
	netParameter->layer[9].lrn_param.norm_region = LRNParameter_NormRegion_ACROSS_CHANNELS;//default value
	netParameter->layer[9].lrn_param.k = 1.;//default value
	netParameter->layer[9].lrn_param.engine = LRNParameter_Engine_DEFAULT;//default value
	//Give default values end

	netParameter->layer[9].lrn_param.local_size = 5;
	netParameter->layer[9].lrn_param.alpha = 0.0001;
	netParameter->layer[9].lrn_param.beta = 0.75;
	CHECK_EXPR_RET(strlen("pool2/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].name,"pool2/3x3_s2");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].type,"Pooling");
	netParameter->layer[10].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[10].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2/norm2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].bottom[0],"conv2/norm2");
	netParameter->layer[10].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[10].top_size = 1;
	CHECK_EXPR_RET(strlen("pool2/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].top[0],"pool2/3x3_s2");

	//Give default values begin:
	netParameter->layer[10].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[10].pooling_param.pad = 0;//default value
	netParameter->layer[10].pooling_param.pad_h = 0;//default value
	netParameter->layer[10].pooling_param.pad_w = 0;//default value
	netParameter->layer[10].pooling_param.stride = 1;//default value
	netParameter->layer[10].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[10].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[10].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[10].pooling_param.kernel_size = 3;
	netParameter->layer[10].pooling_param.stride = 2;
	CHECK_EXPR_RET(strlen("inception_3a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].name,"inception_3a/1x1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].type,"Convolution");
	netParameter->layer[11].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[11].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool2/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].bottom[0],"pool2/3x3_s2");
	netParameter->layer[11].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[11].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].top[0],"inception_3a/1x1");
	netParameter->layer[11].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[11].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[11].param[i].lr_mult = 1.0;//default value
		netParameter->layer[11].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[11].param[0].lr_mult = 1;
	netParameter->layer[11].param[0].decay_mult = 1;
	netParameter->layer[11].param[1].lr_mult = 2;
	netParameter->layer[11].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[11].convolution_param.bias_term = true;//default value
	netParameter->layer[11].convolution_param.pad_h = 0;//default value
	netParameter->layer[11].convolution_param.pad_w = 0;//default value
	netParameter->layer[11].convolution_param.group = 1;//default value
	netParameter->layer[11].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[11].convolution_param.axis = 1;//default value
	netParameter->layer[11].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[11].convolution_param.num_output = 64;
	netParameter->layer[11].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[11].convolution_param.kernel_size_size = 1;
	netParameter->layer[11].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[11].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[11].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[11].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[11].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[11].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[11].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[11].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[11].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[11].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[11].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[11].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[11].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[11].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[11].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[11].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[11].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[11].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].convolution_param.bias_filler.type,"constant");
	netParameter->layer[11].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_3a/relu_1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].name,"inception_3a/relu_1x1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].type,"ReLU");
	netParameter->layer[12].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[12].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].bottom[0],"inception_3a/1x1");
	netParameter->layer[12].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[12].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].top[0],"inception_3a/1x1");
	CHECK_EXPR_RET(strlen("inception_3a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].name,"inception_3a/3x3_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].type,"Convolution");
	netParameter->layer[13].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[13].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool2/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].bottom[0],"pool2/3x3_s2");
	netParameter->layer[13].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[13].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].top[0],"inception_3a/3x3_reduce");
	netParameter->layer[13].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[13].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[13].param[i].lr_mult = 1.0;//default value
		netParameter->layer[13].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[13].param[0].lr_mult = 1;
	netParameter->layer[13].param[0].decay_mult = 1;
	netParameter->layer[13].param[1].lr_mult = 2;
	netParameter->layer[13].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[13].convolution_param.bias_term = true;//default value
	netParameter->layer[13].convolution_param.pad_h = 0;//default value
	netParameter->layer[13].convolution_param.pad_w = 0;//default value
	netParameter->layer[13].convolution_param.group = 1;//default value
	netParameter->layer[13].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[13].convolution_param.axis = 1;//default value
	netParameter->layer[13].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[13].convolution_param.num_output = 96;
	netParameter->layer[13].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[13].convolution_param.kernel_size_size = 1;
	netParameter->layer[13].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[13].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[13].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[13].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[13].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[13].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[13].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[13].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[13].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[13].convolution_param.weight_filler.std = 0.09;

	//Give default values begin:
	strcpy(netParameter->layer[13].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[13].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[13].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[13].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[13].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[13].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[13].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[13].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].convolution_param.bias_filler.type,"constant");
	netParameter->layer[13].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_3a/relu_3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].name,"inception_3a/relu_3x3_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].type,"ReLU");
	netParameter->layer[14].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[14].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].bottom[0],"inception_3a/3x3_reduce");
	netParameter->layer[14].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[14].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].top[0],"inception_3a/3x3_reduce");
	CHECK_EXPR_RET(strlen("inception_3a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].name,"inception_3a/3x3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].type,"Convolution");
	netParameter->layer[15].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[15].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].bottom[0],"inception_3a/3x3_reduce");
	netParameter->layer[15].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[15].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].top[0],"inception_3a/3x3");
	netParameter->layer[15].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[15].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[15].param[i].lr_mult = 1.0;//default value
		netParameter->layer[15].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[15].param[0].lr_mult = 1;
	netParameter->layer[15].param[0].decay_mult = 1;
	netParameter->layer[15].param[1].lr_mult = 2;
	netParameter->layer[15].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[15].convolution_param.bias_term = true;//default value
	netParameter->layer[15].convolution_param.pad_h = 0;//default value
	netParameter->layer[15].convolution_param.pad_w = 0;//default value
	netParameter->layer[15].convolution_param.group = 1;//default value
	netParameter->layer[15].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[15].convolution_param.axis = 1;//default value
	netParameter->layer[15].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[15].convolution_param.num_output = 128;
	netParameter->layer[15].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[15].convolution_param.pad_size = 1;
	netParameter->layer[15].convolution_param.pad[0] = 1;
	netParameter->layer[15].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[15].convolution_param.kernel_size_size = 1;
	netParameter->layer[15].convolution_param.kernel_size[0] = 3;

	//Give default values begin:
	strcpy(netParameter->layer[15].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[15].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[15].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[15].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[15].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[15].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[15].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[15].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[15].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[15].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[15].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[15].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[15].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[15].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[15].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[15].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[15].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].convolution_param.bias_filler.type,"constant");
	netParameter->layer[15].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_3a/relu_3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[16].name,"inception_3a/relu_3x3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[16].type,"ReLU");
	netParameter->layer[16].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[16].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[16].bottom[0],"inception_3a/3x3");
	netParameter->layer[16].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[16].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[16].top[0],"inception_3a/3x3");
	CHECK_EXPR_RET(strlen("inception_3a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].name,"inception_3a/5x5_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].type,"Convolution");
	netParameter->layer[17].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[17].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool2/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].bottom[0],"pool2/3x3_s2");
	netParameter->layer[17].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[17].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].top[0],"inception_3a/5x5_reduce");
	netParameter->layer[17].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[17].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[17].param[i].lr_mult = 1.0;//default value
		netParameter->layer[17].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[17].param[0].lr_mult = 1;
	netParameter->layer[17].param[0].decay_mult = 1;
	netParameter->layer[17].param[1].lr_mult = 2;
	netParameter->layer[17].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[17].convolution_param.bias_term = true;//default value
	netParameter->layer[17].convolution_param.pad_h = 0;//default value
	netParameter->layer[17].convolution_param.pad_w = 0;//default value
	netParameter->layer[17].convolution_param.group = 1;//default value
	netParameter->layer[17].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[17].convolution_param.axis = 1;//default value
	netParameter->layer[17].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[17].convolution_param.num_output = 16;
	netParameter->layer[17].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[17].convolution_param.kernel_size_size = 1;
	netParameter->layer[17].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[17].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[17].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[17].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[17].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[17].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[17].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[17].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[17].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[17].convolution_param.weight_filler.std = 0.2;

	//Give default values begin:
	strcpy(netParameter->layer[17].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[17].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[17].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[17].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[17].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[17].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[17].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[17].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].convolution_param.bias_filler.type,"constant");
	netParameter->layer[17].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_3a/relu_5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[18].name,"inception_3a/relu_5x5_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[18].type,"ReLU");
	netParameter->layer[18].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[18].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[18].bottom[0],"inception_3a/5x5_reduce");
	netParameter->layer[18].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[18].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[18].top[0],"inception_3a/5x5_reduce");
	CHECK_EXPR_RET(strlen("inception_3a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].name,"inception_3a/5x5");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].type,"Convolution");
	netParameter->layer[19].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[19].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].bottom[0],"inception_3a/5x5_reduce");
	netParameter->layer[19].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[19].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].top[0],"inception_3a/5x5");
	netParameter->layer[19].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[19].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[19].param[i].lr_mult = 1.0;//default value
		netParameter->layer[19].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[19].param[0].lr_mult = 1;
	netParameter->layer[19].param[0].decay_mult = 1;
	netParameter->layer[19].param[1].lr_mult = 2;
	netParameter->layer[19].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[19].convolution_param.bias_term = true;//default value
	netParameter->layer[19].convolution_param.pad_h = 0;//default value
	netParameter->layer[19].convolution_param.pad_w = 0;//default value
	netParameter->layer[19].convolution_param.group = 1;//default value
	netParameter->layer[19].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[19].convolution_param.axis = 1;//default value
	netParameter->layer[19].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[19].convolution_param.num_output = 32;
	netParameter->layer[19].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[19].convolution_param.pad_size = 1;
	netParameter->layer[19].convolution_param.pad[0] = 2;
	netParameter->layer[19].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[19].convolution_param.kernel_size_size = 1;
	netParameter->layer[19].convolution_param.kernel_size[0] = 5;

	//Give default values begin:
	strcpy(netParameter->layer[19].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[19].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[19].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[19].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[19].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[19].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[19].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[19].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[19].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[19].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[19].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[19].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[19].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[19].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[19].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[19].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[19].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].convolution_param.bias_filler.type,"constant");
	netParameter->layer[19].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_3a/relu_5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[20].name,"inception_3a/relu_5x5");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[20].type,"ReLU");
	netParameter->layer[20].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[20].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[20].bottom[0],"inception_3a/5x5");
	netParameter->layer[20].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[20].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[20].top[0],"inception_3a/5x5");
	CHECK_EXPR_RET(strlen("inception_3a/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].name,"inception_3a/pool");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].type,"Pooling");
	netParameter->layer[21].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[21].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool2/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].bottom[0],"pool2/3x3_s2");
	netParameter->layer[21].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[21].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].top[0],"inception_3a/pool");

	//Give default values begin:
	netParameter->layer[21].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[21].pooling_param.pad = 0;//default value
	netParameter->layer[21].pooling_param.pad_h = 0;//default value
	netParameter->layer[21].pooling_param.pad_w = 0;//default value
	netParameter->layer[21].pooling_param.stride = 1;//default value
	netParameter->layer[21].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[21].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[21].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[21].pooling_param.kernel_size = 3;
	netParameter->layer[21].pooling_param.stride = 1;
	netParameter->layer[21].pooling_param.pad = 1;
	CHECK_EXPR_RET(strlen("inception_3a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].name,"inception_3a/pool_proj");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].type,"Convolution");
	netParameter->layer[22].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[22].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].bottom[0],"inception_3a/pool");
	netParameter->layer[22].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[22].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].top[0],"inception_3a/pool_proj");
	netParameter->layer[22].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[22].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[22].param[i].lr_mult = 1.0;//default value
		netParameter->layer[22].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[22].param[0].lr_mult = 1;
	netParameter->layer[22].param[0].decay_mult = 1;
	netParameter->layer[22].param[1].lr_mult = 2;
	netParameter->layer[22].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[22].convolution_param.bias_term = true;//default value
	netParameter->layer[22].convolution_param.pad_h = 0;//default value
	netParameter->layer[22].convolution_param.pad_w = 0;//default value
	netParameter->layer[22].convolution_param.group = 1;//default value
	netParameter->layer[22].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[22].convolution_param.axis = 1;//default value
	netParameter->layer[22].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[22].convolution_param.num_output = 32;
	netParameter->layer[22].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[22].convolution_param.kernel_size_size = 1;
	netParameter->layer[22].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[22].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[22].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[22].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[22].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[22].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[22].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[22].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[22].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[22].convolution_param.weight_filler.std = 0.1;

	//Give default values begin:
	strcpy(netParameter->layer[22].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[22].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[22].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[22].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[22].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[22].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[22].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[22].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].convolution_param.bias_filler.type,"constant");
	netParameter->layer[22].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_3a/relu_pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[23].name,"inception_3a/relu_pool_proj");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[23].type,"ReLU");
	netParameter->layer[23].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[23].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[23].bottom[0],"inception_3a/pool_proj");
	netParameter->layer[23].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[23].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[23].top[0],"inception_3a/pool_proj");
	CHECK_EXPR_RET(strlen("inception_3a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].name,"inception_3a/output");
	CHECK_EXPR_RET(strlen("Concat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].type,"Concat");
	netParameter->layer[24].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*4);
	netParameter->layer[24].bottom_size = 4;
	CHECK_EXPR_RET(strlen("inception_3a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].bottom[0],"inception_3a/1x1");
	CHECK_EXPR_RET(strlen("inception_3a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].bottom[1],"inception_3a/3x3");
	CHECK_EXPR_RET(strlen("inception_3a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].bottom[2],"inception_3a/5x5");
	CHECK_EXPR_RET(strlen("inception_3a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].bottom[3],"inception_3a/pool_proj");
	netParameter->layer[24].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[24].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].top[0],"inception_3a/output");
	CHECK_EXPR_RET(strlen("inception_3b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].name,"inception_3b/1x1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].type,"Convolution");
	netParameter->layer[25].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[25].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].bottom[0],"inception_3a/output");
	netParameter->layer[25].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[25].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].top[0],"inception_3b/1x1");
	netParameter->layer[25].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[25].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[25].param[i].lr_mult = 1.0;//default value
		netParameter->layer[25].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[25].param[0].lr_mult = 1;
	netParameter->layer[25].param[0].decay_mult = 1;
	netParameter->layer[25].param[1].lr_mult = 2;
	netParameter->layer[25].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[25].convolution_param.bias_term = true;//default value
	netParameter->layer[25].convolution_param.pad_h = 0;//default value
	netParameter->layer[25].convolution_param.pad_w = 0;//default value
	netParameter->layer[25].convolution_param.group = 1;//default value
	netParameter->layer[25].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[25].convolution_param.axis = 1;//default value
	netParameter->layer[25].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[25].convolution_param.num_output = 128;
	netParameter->layer[25].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[25].convolution_param.kernel_size_size = 1;
	netParameter->layer[25].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[25].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[25].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[25].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[25].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[25].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[25].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[25].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[25].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[25].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[25].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[25].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[25].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[25].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[25].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[25].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[25].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[25].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].convolution_param.bias_filler.type,"constant");
	netParameter->layer[25].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_3b/relu_1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].name,"inception_3b/relu_1x1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].type,"ReLU");
	netParameter->layer[26].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[26].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].bottom[0],"inception_3b/1x1");
	netParameter->layer[26].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[26].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].top[0],"inception_3b/1x1");
	CHECK_EXPR_RET(strlen("inception_3b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].name,"inception_3b/3x3_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].type,"Convolution");
	netParameter->layer[27].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[27].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].bottom[0],"inception_3a/output");
	netParameter->layer[27].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[27].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].top[0],"inception_3b/3x3_reduce");
	netParameter->layer[27].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[27].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[27].param[i].lr_mult = 1.0;//default value
		netParameter->layer[27].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[27].param[0].lr_mult = 1;
	netParameter->layer[27].param[0].decay_mult = 1;
	netParameter->layer[27].param[1].lr_mult = 2;
	netParameter->layer[27].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[27].convolution_param.bias_term = true;//default value
	netParameter->layer[27].convolution_param.pad_h = 0;//default value
	netParameter->layer[27].convolution_param.pad_w = 0;//default value
	netParameter->layer[27].convolution_param.group = 1;//default value
	netParameter->layer[27].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[27].convolution_param.axis = 1;//default value
	netParameter->layer[27].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[27].convolution_param.num_output = 128;
	netParameter->layer[27].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[27].convolution_param.kernel_size_size = 1;
	netParameter->layer[27].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[27].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[27].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[27].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[27].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[27].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[27].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[27].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[27].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[27].convolution_param.weight_filler.std = 0.09;

	//Give default values begin:
	strcpy(netParameter->layer[27].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[27].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[27].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[27].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[27].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[27].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[27].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[27].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].convolution_param.bias_filler.type,"constant");
	netParameter->layer[27].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_3b/relu_3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].name,"inception_3b/relu_3x3_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].type,"ReLU");
	netParameter->layer[28].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[28].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].bottom[0],"inception_3b/3x3_reduce");
	netParameter->layer[28].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[28].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].top[0],"inception_3b/3x3_reduce");
	CHECK_EXPR_RET(strlen("inception_3b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].name,"inception_3b/3x3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].type,"Convolution");
	netParameter->layer[29].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[29].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].bottom[0],"inception_3b/3x3_reduce");
	netParameter->layer[29].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[29].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].top[0],"inception_3b/3x3");
	netParameter->layer[29].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[29].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[29].param[i].lr_mult = 1.0;//default value
		netParameter->layer[29].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[29].param[0].lr_mult = 1;
	netParameter->layer[29].param[0].decay_mult = 1;
	netParameter->layer[29].param[1].lr_mult = 2;
	netParameter->layer[29].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[29].convolution_param.bias_term = true;//default value
	netParameter->layer[29].convolution_param.pad_h = 0;//default value
	netParameter->layer[29].convolution_param.pad_w = 0;//default value
	netParameter->layer[29].convolution_param.group = 1;//default value
	netParameter->layer[29].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[29].convolution_param.axis = 1;//default value
	netParameter->layer[29].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[29].convolution_param.num_output = 192;
	netParameter->layer[29].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[29].convolution_param.pad_size = 1;
	netParameter->layer[29].convolution_param.pad[0] = 1;
	netParameter->layer[29].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[29].convolution_param.kernel_size_size = 1;
	netParameter->layer[29].convolution_param.kernel_size[0] = 3;

	//Give default values begin:
	strcpy(netParameter->layer[29].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[29].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[29].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[29].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[29].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[29].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[29].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[29].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[29].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[29].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[29].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[29].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[29].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[29].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[29].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[29].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[29].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].convolution_param.bias_filler.type,"constant");
	netParameter->layer[29].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_3b/relu_3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[30].name,"inception_3b/relu_3x3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[30].type,"ReLU");
	netParameter->layer[30].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[30].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[30].bottom[0],"inception_3b/3x3");
	netParameter->layer[30].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[30].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[30].top[0],"inception_3b/3x3");
	CHECK_EXPR_RET(strlen("inception_3b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].name,"inception_3b/5x5_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].type,"Convolution");
	netParameter->layer[31].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[31].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].bottom[0],"inception_3a/output");
	netParameter->layer[31].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[31].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].top[0],"inception_3b/5x5_reduce");
	netParameter->layer[31].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[31].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[31].param[i].lr_mult = 1.0;//default value
		netParameter->layer[31].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[31].param[0].lr_mult = 1;
	netParameter->layer[31].param[0].decay_mult = 1;
	netParameter->layer[31].param[1].lr_mult = 2;
	netParameter->layer[31].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[31].convolution_param.bias_term = true;//default value
	netParameter->layer[31].convolution_param.pad_h = 0;//default value
	netParameter->layer[31].convolution_param.pad_w = 0;//default value
	netParameter->layer[31].convolution_param.group = 1;//default value
	netParameter->layer[31].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[31].convolution_param.axis = 1;//default value
	netParameter->layer[31].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[31].convolution_param.num_output = 32;
	netParameter->layer[31].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[31].convolution_param.kernel_size_size = 1;
	netParameter->layer[31].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[31].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[31].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[31].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[31].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[31].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[31].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[31].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[31].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[31].convolution_param.weight_filler.std = 0.2;

	//Give default values begin:
	strcpy(netParameter->layer[31].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[31].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[31].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[31].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[31].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[31].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[31].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[31].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].convolution_param.bias_filler.type,"constant");
	netParameter->layer[31].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_3b/relu_5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[32].name,"inception_3b/relu_5x5_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[32].type,"ReLU");
	netParameter->layer[32].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[32].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[32].bottom[0],"inception_3b/5x5_reduce");
	netParameter->layer[32].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[32].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[32].top[0],"inception_3b/5x5_reduce");
	CHECK_EXPR_RET(strlen("inception_3b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].name,"inception_3b/5x5");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].type,"Convolution");
	netParameter->layer[33].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[33].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].bottom[0],"inception_3b/5x5_reduce");
	netParameter->layer[33].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[33].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].top[0],"inception_3b/5x5");
	netParameter->layer[33].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[33].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[33].param[i].lr_mult = 1.0;//default value
		netParameter->layer[33].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[33].param[0].lr_mult = 1;
	netParameter->layer[33].param[0].decay_mult = 1;
	netParameter->layer[33].param[1].lr_mult = 2;
	netParameter->layer[33].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[33].convolution_param.bias_term = true;//default value
	netParameter->layer[33].convolution_param.pad_h = 0;//default value
	netParameter->layer[33].convolution_param.pad_w = 0;//default value
	netParameter->layer[33].convolution_param.group = 1;//default value
	netParameter->layer[33].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[33].convolution_param.axis = 1;//default value
	netParameter->layer[33].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[33].convolution_param.num_output = 96;
	netParameter->layer[33].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[33].convolution_param.pad_size = 1;
	netParameter->layer[33].convolution_param.pad[0] = 2;
	netParameter->layer[33].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[33].convolution_param.kernel_size_size = 1;
	netParameter->layer[33].convolution_param.kernel_size[0] = 5;

	//Give default values begin:
	strcpy(netParameter->layer[33].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[33].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[33].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[33].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[33].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[33].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[33].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[33].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[33].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[33].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[33].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[33].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[33].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[33].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[33].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[33].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[33].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].convolution_param.bias_filler.type,"constant");
	netParameter->layer[33].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_3b/relu_5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[34].name,"inception_3b/relu_5x5");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[34].type,"ReLU");
	netParameter->layer[34].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[34].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[34].bottom[0],"inception_3b/5x5");
	netParameter->layer[34].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[34].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[34].top[0],"inception_3b/5x5");
	CHECK_EXPR_RET(strlen("inception_3b/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].name,"inception_3b/pool");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].type,"Pooling");
	netParameter->layer[35].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[35].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].bottom[0],"inception_3a/output");
	netParameter->layer[35].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[35].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].top[0],"inception_3b/pool");

	//Give default values begin:
	netParameter->layer[35].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[35].pooling_param.pad = 0;//default value
	netParameter->layer[35].pooling_param.pad_h = 0;//default value
	netParameter->layer[35].pooling_param.pad_w = 0;//default value
	netParameter->layer[35].pooling_param.stride = 1;//default value
	netParameter->layer[35].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[35].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[35].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[35].pooling_param.kernel_size = 3;
	netParameter->layer[35].pooling_param.stride = 1;
	netParameter->layer[35].pooling_param.pad = 1;
	CHECK_EXPR_RET(strlen("inception_3b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].name,"inception_3b/pool_proj");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].type,"Convolution");
	netParameter->layer[36].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[36].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].bottom[0],"inception_3b/pool");
	netParameter->layer[36].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[36].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].top[0],"inception_3b/pool_proj");
	netParameter->layer[36].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[36].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[36].param[i].lr_mult = 1.0;//default value
		netParameter->layer[36].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[36].param[0].lr_mult = 1;
	netParameter->layer[36].param[0].decay_mult = 1;
	netParameter->layer[36].param[1].lr_mult = 2;
	netParameter->layer[36].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[36].convolution_param.bias_term = true;//default value
	netParameter->layer[36].convolution_param.pad_h = 0;//default value
	netParameter->layer[36].convolution_param.pad_w = 0;//default value
	netParameter->layer[36].convolution_param.group = 1;//default value
	netParameter->layer[36].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[36].convolution_param.axis = 1;//default value
	netParameter->layer[36].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[36].convolution_param.num_output = 64;
	netParameter->layer[36].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[36].convolution_param.kernel_size_size = 1;
	netParameter->layer[36].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[36].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[36].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[36].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[36].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[36].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[36].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[36].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[36].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[36].convolution_param.weight_filler.std = 0.1;

	//Give default values begin:
	strcpy(netParameter->layer[36].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[36].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[36].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[36].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[36].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[36].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[36].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[36].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].convolution_param.bias_filler.type,"constant");
	netParameter->layer[36].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_3b/relu_pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].name,"inception_3b/relu_pool_proj");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].type,"ReLU");
	netParameter->layer[37].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[37].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].bottom[0],"inception_3b/pool_proj");
	netParameter->layer[37].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[37].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].top[0],"inception_3b/pool_proj");
	CHECK_EXPR_RET(strlen("inception_3b/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].name,"inception_3b/output");
	CHECK_EXPR_RET(strlen("Concat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].type,"Concat");
	netParameter->layer[38].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*4);
	netParameter->layer[38].bottom_size = 4;
	CHECK_EXPR_RET(strlen("inception_3b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].bottom[0],"inception_3b/1x1");
	CHECK_EXPR_RET(strlen("inception_3b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].bottom[1],"inception_3b/3x3");
	CHECK_EXPR_RET(strlen("inception_3b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].bottom[2],"inception_3b/5x5");
	CHECK_EXPR_RET(strlen("inception_3b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].bottom[3],"inception_3b/pool_proj");
	netParameter->layer[38].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[38].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].top[0],"inception_3b/output");
	CHECK_EXPR_RET(strlen("pool3/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[39].name,"pool3/3x3_s2");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[39].type,"Pooling");
	netParameter->layer[39].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[39].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_3b/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[39].bottom[0],"inception_3b/output");
	netParameter->layer[39].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[39].top_size = 1;
	CHECK_EXPR_RET(strlen("pool3/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[39].top[0],"pool3/3x3_s2");

	//Give default values begin:
	netParameter->layer[39].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[39].pooling_param.pad = 0;//default value
	netParameter->layer[39].pooling_param.pad_h = 0;//default value
	netParameter->layer[39].pooling_param.pad_w = 0;//default value
	netParameter->layer[39].pooling_param.stride = 1;//default value
	netParameter->layer[39].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[39].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[39].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[39].pooling_param.kernel_size = 3;
	netParameter->layer[39].pooling_param.stride = 2;
	CHECK_EXPR_RET(strlen("inception_4a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[40].name,"inception_4a/1x1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[40].type,"Convolution");
	netParameter->layer[40].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[40].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool3/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[40].bottom[0],"pool3/3x3_s2");
	netParameter->layer[40].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[40].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[40].top[0],"inception_4a/1x1");
	netParameter->layer[40].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[40].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[40].param[i].lr_mult = 1.0;//default value
		netParameter->layer[40].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[40].param[0].lr_mult = 1;
	netParameter->layer[40].param[0].decay_mult = 1;
	netParameter->layer[40].param[1].lr_mult = 2;
	netParameter->layer[40].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[40].convolution_param.bias_term = true;//default value
	netParameter->layer[40].convolution_param.pad_h = 0;//default value
	netParameter->layer[40].convolution_param.pad_w = 0;//default value
	netParameter->layer[40].convolution_param.group = 1;//default value
	netParameter->layer[40].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[40].convolution_param.axis = 1;//default value
	netParameter->layer[40].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[40].convolution_param.num_output = 192;
	netParameter->layer[40].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[40].convolution_param.kernel_size_size = 1;
	netParameter->layer[40].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[40].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[40].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[40].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[40].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[40].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[40].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[40].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[40].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[40].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[40].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[40].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[40].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[40].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[40].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[40].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[40].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[40].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[40].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[40].convolution_param.bias_filler.type,"constant");
	netParameter->layer[40].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4a/relu_1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[41].name,"inception_4a/relu_1x1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[41].type,"ReLU");
	netParameter->layer[41].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[41].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[41].bottom[0],"inception_4a/1x1");
	netParameter->layer[41].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[41].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[41].top[0],"inception_4a/1x1");
	CHECK_EXPR_RET(strlen("inception_4a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[42].name,"inception_4a/3x3_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[42].type,"Convolution");
	netParameter->layer[42].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[42].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool3/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[42].bottom[0],"pool3/3x3_s2");
	netParameter->layer[42].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[42].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[42].top[0],"inception_4a/3x3_reduce");
	netParameter->layer[42].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[42].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[42].param[i].lr_mult = 1.0;//default value
		netParameter->layer[42].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[42].param[0].lr_mult = 1;
	netParameter->layer[42].param[0].decay_mult = 1;
	netParameter->layer[42].param[1].lr_mult = 2;
	netParameter->layer[42].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[42].convolution_param.bias_term = true;//default value
	netParameter->layer[42].convolution_param.pad_h = 0;//default value
	netParameter->layer[42].convolution_param.pad_w = 0;//default value
	netParameter->layer[42].convolution_param.group = 1;//default value
	netParameter->layer[42].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[42].convolution_param.axis = 1;//default value
	netParameter->layer[42].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[42].convolution_param.num_output = 96;
	netParameter->layer[42].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[42].convolution_param.kernel_size_size = 1;
	netParameter->layer[42].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[42].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[42].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[42].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[42].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[42].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[42].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[42].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[42].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[42].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[42].convolution_param.weight_filler.std = 0.09;

	//Give default values begin:
	strcpy(netParameter->layer[42].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[42].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[42].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[42].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[42].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[42].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[42].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[42].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[42].convolution_param.bias_filler.type,"constant");
	netParameter->layer[42].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4a/relu_3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[43].name,"inception_4a/relu_3x3_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[43].type,"ReLU");
	netParameter->layer[43].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[43].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[43].bottom[0],"inception_4a/3x3_reduce");
	netParameter->layer[43].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[43].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[43].top[0],"inception_4a/3x3_reduce");
	CHECK_EXPR_RET(strlen("inception_4a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[44].name,"inception_4a/3x3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[44].type,"Convolution");
	netParameter->layer[44].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[44].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[44].bottom[0],"inception_4a/3x3_reduce");
	netParameter->layer[44].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[44].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[44].top[0],"inception_4a/3x3");
	netParameter->layer[44].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[44].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[44].param[i].lr_mult = 1.0;//default value
		netParameter->layer[44].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[44].param[0].lr_mult = 1;
	netParameter->layer[44].param[0].decay_mult = 1;
	netParameter->layer[44].param[1].lr_mult = 2;
	netParameter->layer[44].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[44].convolution_param.bias_term = true;//default value
	netParameter->layer[44].convolution_param.pad_h = 0;//default value
	netParameter->layer[44].convolution_param.pad_w = 0;//default value
	netParameter->layer[44].convolution_param.group = 1;//default value
	netParameter->layer[44].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[44].convolution_param.axis = 1;//default value
	netParameter->layer[44].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[44].convolution_param.num_output = 208;
	netParameter->layer[44].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[44].convolution_param.pad_size = 1;
	netParameter->layer[44].convolution_param.pad[0] = 1;
	netParameter->layer[44].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[44].convolution_param.kernel_size_size = 1;
	netParameter->layer[44].convolution_param.kernel_size[0] = 3;

	//Give default values begin:
	strcpy(netParameter->layer[44].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[44].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[44].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[44].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[44].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[44].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[44].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[44].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[44].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[44].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[44].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[44].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[44].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[44].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[44].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[44].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[44].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[44].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[44].convolution_param.bias_filler.type,"constant");
	netParameter->layer[44].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4a/relu_3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[45].name,"inception_4a/relu_3x3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[45].type,"ReLU");
	netParameter->layer[45].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[45].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[45].bottom[0],"inception_4a/3x3");
	netParameter->layer[45].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[45].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[45].top[0],"inception_4a/3x3");
	CHECK_EXPR_RET(strlen("inception_4a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[46].name,"inception_4a/5x5_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[46].type,"Convolution");
	netParameter->layer[46].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[46].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool3/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[46].bottom[0],"pool3/3x3_s2");
	netParameter->layer[46].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[46].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[46].top[0],"inception_4a/5x5_reduce");
	netParameter->layer[46].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[46].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[46].param[i].lr_mult = 1.0;//default value
		netParameter->layer[46].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[46].param[0].lr_mult = 1;
	netParameter->layer[46].param[0].decay_mult = 1;
	netParameter->layer[46].param[1].lr_mult = 2;
	netParameter->layer[46].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[46].convolution_param.bias_term = true;//default value
	netParameter->layer[46].convolution_param.pad_h = 0;//default value
	netParameter->layer[46].convolution_param.pad_w = 0;//default value
	netParameter->layer[46].convolution_param.group = 1;//default value
	netParameter->layer[46].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[46].convolution_param.axis = 1;//default value
	netParameter->layer[46].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[46].convolution_param.num_output = 16;
	netParameter->layer[46].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[46].convolution_param.kernel_size_size = 1;
	netParameter->layer[46].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[46].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[46].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[46].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[46].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[46].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[46].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[46].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[46].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[46].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[46].convolution_param.weight_filler.std = 0.2;

	//Give default values begin:
	strcpy(netParameter->layer[46].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[46].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[46].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[46].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[46].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[46].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[46].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[46].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[46].convolution_param.bias_filler.type,"constant");
	netParameter->layer[46].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4a/relu_5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[47].name,"inception_4a/relu_5x5_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[47].type,"ReLU");
	netParameter->layer[47].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[47].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[47].bottom[0],"inception_4a/5x5_reduce");
	netParameter->layer[47].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[47].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[47].top[0],"inception_4a/5x5_reduce");
	CHECK_EXPR_RET(strlen("inception_4a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[48].name,"inception_4a/5x5");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[48].type,"Convolution");
	netParameter->layer[48].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[48].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[48].bottom[0],"inception_4a/5x5_reduce");
	netParameter->layer[48].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[48].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[48].top[0],"inception_4a/5x5");
	netParameter->layer[48].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[48].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[48].param[i].lr_mult = 1.0;//default value
		netParameter->layer[48].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[48].param[0].lr_mult = 1;
	netParameter->layer[48].param[0].decay_mult = 1;
	netParameter->layer[48].param[1].lr_mult = 2;
	netParameter->layer[48].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[48].convolution_param.bias_term = true;//default value
	netParameter->layer[48].convolution_param.pad_h = 0;//default value
	netParameter->layer[48].convolution_param.pad_w = 0;//default value
	netParameter->layer[48].convolution_param.group = 1;//default value
	netParameter->layer[48].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[48].convolution_param.axis = 1;//default value
	netParameter->layer[48].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[48].convolution_param.num_output = 48;
	netParameter->layer[48].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[48].convolution_param.pad_size = 1;
	netParameter->layer[48].convolution_param.pad[0] = 2;
	netParameter->layer[48].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[48].convolution_param.kernel_size_size = 1;
	netParameter->layer[48].convolution_param.kernel_size[0] = 5;

	//Give default values begin:
	strcpy(netParameter->layer[48].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[48].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[48].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[48].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[48].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[48].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[48].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[48].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[48].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[48].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[48].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[48].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[48].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[48].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[48].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[48].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[48].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[48].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[48].convolution_param.bias_filler.type,"constant");
	netParameter->layer[48].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4a/relu_5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[49].name,"inception_4a/relu_5x5");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[49].type,"ReLU");
	netParameter->layer[49].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[49].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[49].bottom[0],"inception_4a/5x5");
	netParameter->layer[49].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[49].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[49].top[0],"inception_4a/5x5");
	CHECK_EXPR_RET(strlen("inception_4a/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[50].name,"inception_4a/pool");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[50].type,"Pooling");
	netParameter->layer[50].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[50].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool3/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[50].bottom[0],"pool3/3x3_s2");
	netParameter->layer[50].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[50].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[50].top[0],"inception_4a/pool");

	//Give default values begin:
	netParameter->layer[50].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[50].pooling_param.pad = 0;//default value
	netParameter->layer[50].pooling_param.pad_h = 0;//default value
	netParameter->layer[50].pooling_param.pad_w = 0;//default value
	netParameter->layer[50].pooling_param.stride = 1;//default value
	netParameter->layer[50].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[50].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[50].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[50].pooling_param.kernel_size = 3;
	netParameter->layer[50].pooling_param.stride = 1;
	netParameter->layer[50].pooling_param.pad = 1;
	CHECK_EXPR_RET(strlen("inception_4a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[51].name,"inception_4a/pool_proj");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[51].type,"Convolution");
	netParameter->layer[51].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[51].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[51].bottom[0],"inception_4a/pool");
	netParameter->layer[51].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[51].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[51].top[0],"inception_4a/pool_proj");
	netParameter->layer[51].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[51].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[51].param[i].lr_mult = 1.0;//default value
		netParameter->layer[51].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[51].param[0].lr_mult = 1;
	netParameter->layer[51].param[0].decay_mult = 1;
	netParameter->layer[51].param[1].lr_mult = 2;
	netParameter->layer[51].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[51].convolution_param.bias_term = true;//default value
	netParameter->layer[51].convolution_param.pad_h = 0;//default value
	netParameter->layer[51].convolution_param.pad_w = 0;//default value
	netParameter->layer[51].convolution_param.group = 1;//default value
	netParameter->layer[51].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[51].convolution_param.axis = 1;//default value
	netParameter->layer[51].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[51].convolution_param.num_output = 64;
	netParameter->layer[51].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[51].convolution_param.kernel_size_size = 1;
	netParameter->layer[51].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[51].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[51].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[51].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[51].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[51].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[51].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[51].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[51].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[51].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[51].convolution_param.weight_filler.std = 0.1;

	//Give default values begin:
	strcpy(netParameter->layer[51].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[51].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[51].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[51].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[51].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[51].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[51].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[51].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[51].convolution_param.bias_filler.type,"constant");
	netParameter->layer[51].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4a/relu_pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[52].name,"inception_4a/relu_pool_proj");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[52].type,"ReLU");
	netParameter->layer[52].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[52].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[52].bottom[0],"inception_4a/pool_proj");
	netParameter->layer[52].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[52].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[52].top[0],"inception_4a/pool_proj");
	CHECK_EXPR_RET(strlen("inception_4a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[53].name,"inception_4a/output");
	CHECK_EXPR_RET(strlen("Concat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[53].type,"Concat");
	netParameter->layer[53].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*4);
	netParameter->layer[53].bottom_size = 4;
	CHECK_EXPR_RET(strlen("inception_4a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[53].bottom[0],"inception_4a/1x1");
	CHECK_EXPR_RET(strlen("inception_4a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[53].bottom[1],"inception_4a/3x3");
	CHECK_EXPR_RET(strlen("inception_4a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[53].bottom[2],"inception_4a/5x5");
	CHECK_EXPR_RET(strlen("inception_4a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[53].bottom[3],"inception_4a/pool_proj");
	netParameter->layer[53].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[53].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[53].top[0],"inception_4a/output");
	CHECK_EXPR_RET(strlen("inception_4b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[54].name,"inception_4b/1x1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[54].type,"Convolution");
	netParameter->layer[54].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[54].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[54].bottom[0],"inception_4a/output");
	netParameter->layer[54].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[54].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[54].top[0],"inception_4b/1x1");
	netParameter->layer[54].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[54].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[54].param[i].lr_mult = 1.0;//default value
		netParameter->layer[54].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[54].param[0].lr_mult = 1;
	netParameter->layer[54].param[0].decay_mult = 1;
	netParameter->layer[54].param[1].lr_mult = 2;
	netParameter->layer[54].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[54].convolution_param.bias_term = true;//default value
	netParameter->layer[54].convolution_param.pad_h = 0;//default value
	netParameter->layer[54].convolution_param.pad_w = 0;//default value
	netParameter->layer[54].convolution_param.group = 1;//default value
	netParameter->layer[54].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[54].convolution_param.axis = 1;//default value
	netParameter->layer[54].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[54].convolution_param.num_output = 160;
	netParameter->layer[54].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[54].convolution_param.kernel_size_size = 1;
	netParameter->layer[54].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[54].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[54].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[54].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[54].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[54].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[54].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[54].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[54].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[54].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[54].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[54].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[54].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[54].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[54].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[54].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[54].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[54].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[54].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[54].convolution_param.bias_filler.type,"constant");
	netParameter->layer[54].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4b/relu_1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[55].name,"inception_4b/relu_1x1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[55].type,"ReLU");
	netParameter->layer[55].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[55].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[55].bottom[0],"inception_4b/1x1");
	netParameter->layer[55].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[55].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[55].top[0],"inception_4b/1x1");
	CHECK_EXPR_RET(strlen("inception_4b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[56].name,"inception_4b/3x3_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[56].type,"Convolution");
	netParameter->layer[56].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[56].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[56].bottom[0],"inception_4a/output");
	netParameter->layer[56].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[56].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[56].top[0],"inception_4b/3x3_reduce");
	netParameter->layer[56].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[56].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[56].param[i].lr_mult = 1.0;//default value
		netParameter->layer[56].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[56].param[0].lr_mult = 1;
	netParameter->layer[56].param[0].decay_mult = 1;
	netParameter->layer[56].param[1].lr_mult = 2;
	netParameter->layer[56].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[56].convolution_param.bias_term = true;//default value
	netParameter->layer[56].convolution_param.pad_h = 0;//default value
	netParameter->layer[56].convolution_param.pad_w = 0;//default value
	netParameter->layer[56].convolution_param.group = 1;//default value
	netParameter->layer[56].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[56].convolution_param.axis = 1;//default value
	netParameter->layer[56].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[56].convolution_param.num_output = 112;
	netParameter->layer[56].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[56].convolution_param.kernel_size_size = 1;
	netParameter->layer[56].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[56].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[56].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[56].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[56].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[56].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[56].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[56].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[56].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[56].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[56].convolution_param.weight_filler.std = 0.09;

	//Give default values begin:
	strcpy(netParameter->layer[56].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[56].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[56].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[56].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[56].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[56].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[56].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[56].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[56].convolution_param.bias_filler.type,"constant");
	netParameter->layer[56].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4b/relu_3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[57].name,"inception_4b/relu_3x3_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[57].type,"ReLU");
	netParameter->layer[57].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[57].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[57].bottom[0],"inception_4b/3x3_reduce");
	netParameter->layer[57].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[57].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[57].top[0],"inception_4b/3x3_reduce");
	CHECK_EXPR_RET(strlen("inception_4b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[58].name,"inception_4b/3x3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[58].type,"Convolution");
	netParameter->layer[58].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[58].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[58].bottom[0],"inception_4b/3x3_reduce");
	netParameter->layer[58].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[58].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[58].top[0],"inception_4b/3x3");
	netParameter->layer[58].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[58].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[58].param[i].lr_mult = 1.0;//default value
		netParameter->layer[58].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[58].param[0].lr_mult = 1;
	netParameter->layer[58].param[0].decay_mult = 1;
	netParameter->layer[58].param[1].lr_mult = 2;
	netParameter->layer[58].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[58].convolution_param.bias_term = true;//default value
	netParameter->layer[58].convolution_param.pad_h = 0;//default value
	netParameter->layer[58].convolution_param.pad_w = 0;//default value
	netParameter->layer[58].convolution_param.group = 1;//default value
	netParameter->layer[58].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[58].convolution_param.axis = 1;//default value
	netParameter->layer[58].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[58].convolution_param.num_output = 224;
	netParameter->layer[58].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[58].convolution_param.pad_size = 1;
	netParameter->layer[58].convolution_param.pad[0] = 1;
	netParameter->layer[58].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[58].convolution_param.kernel_size_size = 1;
	netParameter->layer[58].convolution_param.kernel_size[0] = 3;

	//Give default values begin:
	strcpy(netParameter->layer[58].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[58].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[58].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[58].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[58].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[58].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[58].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[58].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[58].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[58].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[58].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[58].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[58].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[58].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[58].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[58].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[58].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[58].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[58].convolution_param.bias_filler.type,"constant");
	netParameter->layer[58].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4b/relu_3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[59].name,"inception_4b/relu_3x3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[59].type,"ReLU");
	netParameter->layer[59].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[59].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[59].bottom[0],"inception_4b/3x3");
	netParameter->layer[59].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[59].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[59].top[0],"inception_4b/3x3");
	CHECK_EXPR_RET(strlen("inception_4b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[60].name,"inception_4b/5x5_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[60].type,"Convolution");
	netParameter->layer[60].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[60].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[60].bottom[0],"inception_4a/output");
	netParameter->layer[60].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[60].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[60].top[0],"inception_4b/5x5_reduce");
	netParameter->layer[60].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[60].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[60].param[i].lr_mult = 1.0;//default value
		netParameter->layer[60].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[60].param[0].lr_mult = 1;
	netParameter->layer[60].param[0].decay_mult = 1;
	netParameter->layer[60].param[1].lr_mult = 2;
	netParameter->layer[60].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[60].convolution_param.bias_term = true;//default value
	netParameter->layer[60].convolution_param.pad_h = 0;//default value
	netParameter->layer[60].convolution_param.pad_w = 0;//default value
	netParameter->layer[60].convolution_param.group = 1;//default value
	netParameter->layer[60].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[60].convolution_param.axis = 1;//default value
	netParameter->layer[60].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[60].convolution_param.num_output = 24;
	netParameter->layer[60].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[60].convolution_param.kernel_size_size = 1;
	netParameter->layer[60].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[60].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[60].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[60].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[60].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[60].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[60].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[60].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[60].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[60].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[60].convolution_param.weight_filler.std = 0.2;

	//Give default values begin:
	strcpy(netParameter->layer[60].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[60].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[60].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[60].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[60].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[60].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[60].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[60].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[60].convolution_param.bias_filler.type,"constant");
	netParameter->layer[60].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4b/relu_5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[61].name,"inception_4b/relu_5x5_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[61].type,"ReLU");
	netParameter->layer[61].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[61].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[61].bottom[0],"inception_4b/5x5_reduce");
	netParameter->layer[61].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[61].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[61].top[0],"inception_4b/5x5_reduce");
	CHECK_EXPR_RET(strlen("inception_4b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[62].name,"inception_4b/5x5");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[62].type,"Convolution");
	netParameter->layer[62].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[62].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[62].bottom[0],"inception_4b/5x5_reduce");
	netParameter->layer[62].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[62].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[62].top[0],"inception_4b/5x5");
	netParameter->layer[62].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[62].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[62].param[i].lr_mult = 1.0;//default value
		netParameter->layer[62].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[62].param[0].lr_mult = 1;
	netParameter->layer[62].param[0].decay_mult = 1;
	netParameter->layer[62].param[1].lr_mult = 2;
	netParameter->layer[62].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[62].convolution_param.bias_term = true;//default value
	netParameter->layer[62].convolution_param.pad_h = 0;//default value
	netParameter->layer[62].convolution_param.pad_w = 0;//default value
	netParameter->layer[62].convolution_param.group = 1;//default value
	netParameter->layer[62].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[62].convolution_param.axis = 1;//default value
	netParameter->layer[62].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[62].convolution_param.num_output = 64;
	netParameter->layer[62].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[62].convolution_param.pad_size = 1;
	netParameter->layer[62].convolution_param.pad[0] = 2;
	netParameter->layer[62].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[62].convolution_param.kernel_size_size = 1;
	netParameter->layer[62].convolution_param.kernel_size[0] = 5;

	//Give default values begin:
	strcpy(netParameter->layer[62].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[62].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[62].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[62].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[62].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[62].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[62].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[62].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[62].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[62].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[62].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[62].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[62].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[62].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[62].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[62].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[62].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[62].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[62].convolution_param.bias_filler.type,"constant");
	netParameter->layer[62].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4b/relu_5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[63].name,"inception_4b/relu_5x5");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[63].type,"ReLU");
	netParameter->layer[63].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[63].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[63].bottom[0],"inception_4b/5x5");
	netParameter->layer[63].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[63].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[63].top[0],"inception_4b/5x5");
	CHECK_EXPR_RET(strlen("inception_4b/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[64].name,"inception_4b/pool");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[64].type,"Pooling");
	netParameter->layer[64].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[64].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[64].bottom[0],"inception_4a/output");
	netParameter->layer[64].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[64].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[64].top[0],"inception_4b/pool");

	//Give default values begin:
	netParameter->layer[64].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[64].pooling_param.pad = 0;//default value
	netParameter->layer[64].pooling_param.pad_h = 0;//default value
	netParameter->layer[64].pooling_param.pad_w = 0;//default value
	netParameter->layer[64].pooling_param.stride = 1;//default value
	netParameter->layer[64].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[64].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[64].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[64].pooling_param.kernel_size = 3;
	netParameter->layer[64].pooling_param.stride = 1;
	netParameter->layer[64].pooling_param.pad = 1;
	CHECK_EXPR_RET(strlen("inception_4b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[65].name,"inception_4b/pool_proj");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[65].type,"Convolution");
	netParameter->layer[65].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[65].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[65].bottom[0],"inception_4b/pool");
	netParameter->layer[65].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[65].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[65].top[0],"inception_4b/pool_proj");
	netParameter->layer[65].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[65].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[65].param[i].lr_mult = 1.0;//default value
		netParameter->layer[65].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[65].param[0].lr_mult = 1;
	netParameter->layer[65].param[0].decay_mult = 1;
	netParameter->layer[65].param[1].lr_mult = 2;
	netParameter->layer[65].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[65].convolution_param.bias_term = true;//default value
	netParameter->layer[65].convolution_param.pad_h = 0;//default value
	netParameter->layer[65].convolution_param.pad_w = 0;//default value
	netParameter->layer[65].convolution_param.group = 1;//default value
	netParameter->layer[65].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[65].convolution_param.axis = 1;//default value
	netParameter->layer[65].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[65].convolution_param.num_output = 64;
	netParameter->layer[65].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[65].convolution_param.kernel_size_size = 1;
	netParameter->layer[65].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[65].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[65].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[65].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[65].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[65].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[65].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[65].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[65].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[65].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[65].convolution_param.weight_filler.std = 0.1;

	//Give default values begin:
	strcpy(netParameter->layer[65].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[65].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[65].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[65].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[65].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[65].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[65].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[65].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[65].convolution_param.bias_filler.type,"constant");
	netParameter->layer[65].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4b/relu_pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[66].name,"inception_4b/relu_pool_proj");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[66].type,"ReLU");
	netParameter->layer[66].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[66].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[66].bottom[0],"inception_4b/pool_proj");
	netParameter->layer[66].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[66].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[66].top[0],"inception_4b/pool_proj");
	CHECK_EXPR_RET(strlen("inception_4b/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[67].name,"inception_4b/output");
	CHECK_EXPR_RET(strlen("Concat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[67].type,"Concat");
	netParameter->layer[67].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*4);
	netParameter->layer[67].bottom_size = 4;
	CHECK_EXPR_RET(strlen("inception_4b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[67].bottom[0],"inception_4b/1x1");
	CHECK_EXPR_RET(strlen("inception_4b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[67].bottom[1],"inception_4b/3x3");
	CHECK_EXPR_RET(strlen("inception_4b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[67].bottom[2],"inception_4b/5x5");
	CHECK_EXPR_RET(strlen("inception_4b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[67].bottom[3],"inception_4b/pool_proj");
	netParameter->layer[67].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[67].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[67].top[0],"inception_4b/output");
	CHECK_EXPR_RET(strlen("inception_4c/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[68].name,"inception_4c/1x1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[68].type,"Convolution");
	netParameter->layer[68].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[68].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[68].bottom[0],"inception_4b/output");
	netParameter->layer[68].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[68].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[68].top[0],"inception_4c/1x1");
	netParameter->layer[68].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[68].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[68].param[i].lr_mult = 1.0;//default value
		netParameter->layer[68].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[68].param[0].lr_mult = 1;
	netParameter->layer[68].param[0].decay_mult = 1;
	netParameter->layer[68].param[1].lr_mult = 2;
	netParameter->layer[68].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[68].convolution_param.bias_term = true;//default value
	netParameter->layer[68].convolution_param.pad_h = 0;//default value
	netParameter->layer[68].convolution_param.pad_w = 0;//default value
	netParameter->layer[68].convolution_param.group = 1;//default value
	netParameter->layer[68].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[68].convolution_param.axis = 1;//default value
	netParameter->layer[68].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[68].convolution_param.num_output = 128;
	netParameter->layer[68].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[68].convolution_param.kernel_size_size = 1;
	netParameter->layer[68].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[68].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[68].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[68].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[68].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[68].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[68].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[68].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[68].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[68].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[68].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[68].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[68].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[68].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[68].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[68].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[68].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[68].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[68].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[68].convolution_param.bias_filler.type,"constant");
	netParameter->layer[68].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4c/relu_1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[69].name,"inception_4c/relu_1x1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[69].type,"ReLU");
	netParameter->layer[69].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[69].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[69].bottom[0],"inception_4c/1x1");
	netParameter->layer[69].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[69].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[69].top[0],"inception_4c/1x1");
	CHECK_EXPR_RET(strlen("inception_4c/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[70].name,"inception_4c/3x3_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[70].type,"Convolution");
	netParameter->layer[70].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[70].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[70].bottom[0],"inception_4b/output");
	netParameter->layer[70].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[70].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[70].top[0],"inception_4c/3x3_reduce");
	netParameter->layer[70].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[70].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[70].param[i].lr_mult = 1.0;//default value
		netParameter->layer[70].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[70].param[0].lr_mult = 1;
	netParameter->layer[70].param[0].decay_mult = 1;
	netParameter->layer[70].param[1].lr_mult = 2;
	netParameter->layer[70].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[70].convolution_param.bias_term = true;//default value
	netParameter->layer[70].convolution_param.pad_h = 0;//default value
	netParameter->layer[70].convolution_param.pad_w = 0;//default value
	netParameter->layer[70].convolution_param.group = 1;//default value
	netParameter->layer[70].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[70].convolution_param.axis = 1;//default value
	netParameter->layer[70].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[70].convolution_param.num_output = 128;
	netParameter->layer[70].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[70].convolution_param.kernel_size_size = 1;
	netParameter->layer[70].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[70].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[70].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[70].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[70].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[70].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[70].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[70].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[70].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[70].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[70].convolution_param.weight_filler.std = 0.09;

	//Give default values begin:
	strcpy(netParameter->layer[70].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[70].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[70].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[70].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[70].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[70].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[70].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[70].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[70].convolution_param.bias_filler.type,"constant");
	netParameter->layer[70].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4c/relu_3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[71].name,"inception_4c/relu_3x3_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[71].type,"ReLU");
	netParameter->layer[71].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[71].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[71].bottom[0],"inception_4c/3x3_reduce");
	netParameter->layer[71].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[71].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[71].top[0],"inception_4c/3x3_reduce");
	CHECK_EXPR_RET(strlen("inception_4c/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[72].name,"inception_4c/3x3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[72].type,"Convolution");
	netParameter->layer[72].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[72].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[72].bottom[0],"inception_4c/3x3_reduce");
	netParameter->layer[72].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[72].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[72].top[0],"inception_4c/3x3");
	netParameter->layer[72].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[72].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[72].param[i].lr_mult = 1.0;//default value
		netParameter->layer[72].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[72].param[0].lr_mult = 1;
	netParameter->layer[72].param[0].decay_mult = 1;
	netParameter->layer[72].param[1].lr_mult = 2;
	netParameter->layer[72].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[72].convolution_param.bias_term = true;//default value
	netParameter->layer[72].convolution_param.pad_h = 0;//default value
	netParameter->layer[72].convolution_param.pad_w = 0;//default value
	netParameter->layer[72].convolution_param.group = 1;//default value
	netParameter->layer[72].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[72].convolution_param.axis = 1;//default value
	netParameter->layer[72].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[72].convolution_param.num_output = 256;
	netParameter->layer[72].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[72].convolution_param.pad_size = 1;
	netParameter->layer[72].convolution_param.pad[0] = 1;
	netParameter->layer[72].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[72].convolution_param.kernel_size_size = 1;
	netParameter->layer[72].convolution_param.kernel_size[0] = 3;

	//Give default values begin:
	strcpy(netParameter->layer[72].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[72].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[72].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[72].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[72].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[72].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[72].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[72].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[72].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[72].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[72].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[72].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[72].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[72].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[72].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[72].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[72].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[72].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[72].convolution_param.bias_filler.type,"constant");
	netParameter->layer[72].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4c/relu_3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[73].name,"inception_4c/relu_3x3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[73].type,"ReLU");
	netParameter->layer[73].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[73].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[73].bottom[0],"inception_4c/3x3");
	netParameter->layer[73].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[73].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[73].top[0],"inception_4c/3x3");
	CHECK_EXPR_RET(strlen("inception_4c/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[74].name,"inception_4c/5x5_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[74].type,"Convolution");
	netParameter->layer[74].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[74].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[74].bottom[0],"inception_4b/output");
	netParameter->layer[74].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[74].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[74].top[0],"inception_4c/5x5_reduce");
	netParameter->layer[74].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[74].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[74].param[i].lr_mult = 1.0;//default value
		netParameter->layer[74].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[74].param[0].lr_mult = 1;
	netParameter->layer[74].param[0].decay_mult = 1;
	netParameter->layer[74].param[1].lr_mult = 2;
	netParameter->layer[74].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[74].convolution_param.bias_term = true;//default value
	netParameter->layer[74].convolution_param.pad_h = 0;//default value
	netParameter->layer[74].convolution_param.pad_w = 0;//default value
	netParameter->layer[74].convolution_param.group = 1;//default value
	netParameter->layer[74].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[74].convolution_param.axis = 1;//default value
	netParameter->layer[74].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[74].convolution_param.num_output = 24;
	netParameter->layer[74].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[74].convolution_param.kernel_size_size = 1;
	netParameter->layer[74].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[74].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[74].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[74].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[74].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[74].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[74].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[74].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[74].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[74].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[74].convolution_param.weight_filler.std = 0.2;

	//Give default values begin:
	strcpy(netParameter->layer[74].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[74].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[74].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[74].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[74].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[74].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[74].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[74].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[74].convolution_param.bias_filler.type,"constant");
	netParameter->layer[74].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4c/relu_5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[75].name,"inception_4c/relu_5x5_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[75].type,"ReLU");
	netParameter->layer[75].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[75].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[75].bottom[0],"inception_4c/5x5_reduce");
	netParameter->layer[75].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[75].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[75].top[0],"inception_4c/5x5_reduce");
	CHECK_EXPR_RET(strlen("inception_4c/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[76].name,"inception_4c/5x5");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[76].type,"Convolution");
	netParameter->layer[76].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[76].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[76].bottom[0],"inception_4c/5x5_reduce");
	netParameter->layer[76].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[76].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[76].top[0],"inception_4c/5x5");
	netParameter->layer[76].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[76].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[76].param[i].lr_mult = 1.0;//default value
		netParameter->layer[76].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[76].param[0].lr_mult = 1;
	netParameter->layer[76].param[0].decay_mult = 1;
	netParameter->layer[76].param[1].lr_mult = 2;
	netParameter->layer[76].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[76].convolution_param.bias_term = true;//default value
	netParameter->layer[76].convolution_param.pad_h = 0;//default value
	netParameter->layer[76].convolution_param.pad_w = 0;//default value
	netParameter->layer[76].convolution_param.group = 1;//default value
	netParameter->layer[76].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[76].convolution_param.axis = 1;//default value
	netParameter->layer[76].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[76].convolution_param.num_output = 64;
	netParameter->layer[76].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[76].convolution_param.pad_size = 1;
	netParameter->layer[76].convolution_param.pad[0] = 2;
	netParameter->layer[76].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[76].convolution_param.kernel_size_size = 1;
	netParameter->layer[76].convolution_param.kernel_size[0] = 5;

	//Give default values begin:
	strcpy(netParameter->layer[76].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[76].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[76].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[76].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[76].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[76].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[76].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[76].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[76].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[76].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[76].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[76].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[76].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[76].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[76].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[76].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[76].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[76].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[76].convolution_param.bias_filler.type,"constant");
	netParameter->layer[76].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4c/relu_5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[77].name,"inception_4c/relu_5x5");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[77].type,"ReLU");
	netParameter->layer[77].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[77].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[77].bottom[0],"inception_4c/5x5");
	netParameter->layer[77].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[77].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[77].top[0],"inception_4c/5x5");
	CHECK_EXPR_RET(strlen("inception_4c/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[78].name,"inception_4c/pool");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[78].type,"Pooling");
	netParameter->layer[78].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[78].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4b/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[78].bottom[0],"inception_4b/output");
	netParameter->layer[78].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[78].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[78].top[0],"inception_4c/pool");

	//Give default values begin:
	netParameter->layer[78].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[78].pooling_param.pad = 0;//default value
	netParameter->layer[78].pooling_param.pad_h = 0;//default value
	netParameter->layer[78].pooling_param.pad_w = 0;//default value
	netParameter->layer[78].pooling_param.stride = 1;//default value
	netParameter->layer[78].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[78].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[78].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[78].pooling_param.kernel_size = 3;
	netParameter->layer[78].pooling_param.stride = 1;
	netParameter->layer[78].pooling_param.pad = 1;
	CHECK_EXPR_RET(strlen("inception_4c/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[79].name,"inception_4c/pool_proj");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[79].type,"Convolution");
	netParameter->layer[79].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[79].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[79].bottom[0],"inception_4c/pool");
	netParameter->layer[79].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[79].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[79].top[0],"inception_4c/pool_proj");
	netParameter->layer[79].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[79].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[79].param[i].lr_mult = 1.0;//default value
		netParameter->layer[79].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[79].param[0].lr_mult = 1;
	netParameter->layer[79].param[0].decay_mult = 1;
	netParameter->layer[79].param[1].lr_mult = 2;
	netParameter->layer[79].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[79].convolution_param.bias_term = true;//default value
	netParameter->layer[79].convolution_param.pad_h = 0;//default value
	netParameter->layer[79].convolution_param.pad_w = 0;//default value
	netParameter->layer[79].convolution_param.group = 1;//default value
	netParameter->layer[79].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[79].convolution_param.axis = 1;//default value
	netParameter->layer[79].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[79].convolution_param.num_output = 64;
	netParameter->layer[79].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[79].convolution_param.kernel_size_size = 1;
	netParameter->layer[79].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[79].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[79].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[79].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[79].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[79].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[79].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[79].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[79].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[79].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[79].convolution_param.weight_filler.std = 0.1;

	//Give default values begin:
	strcpy(netParameter->layer[79].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[79].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[79].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[79].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[79].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[79].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[79].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[79].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[79].convolution_param.bias_filler.type,"constant");
	netParameter->layer[79].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4c/relu_pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[80].name,"inception_4c/relu_pool_proj");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[80].type,"ReLU");
	netParameter->layer[80].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[80].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[80].bottom[0],"inception_4c/pool_proj");
	netParameter->layer[80].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[80].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[80].top[0],"inception_4c/pool_proj");
	CHECK_EXPR_RET(strlen("inception_4c/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[81].name,"inception_4c/output");
	CHECK_EXPR_RET(strlen("Concat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[81].type,"Concat");
	netParameter->layer[81].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*4);
	netParameter->layer[81].bottom_size = 4;
	CHECK_EXPR_RET(strlen("inception_4c/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[81].bottom[0],"inception_4c/1x1");
	CHECK_EXPR_RET(strlen("inception_4c/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[81].bottom[1],"inception_4c/3x3");
	CHECK_EXPR_RET(strlen("inception_4c/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[81].bottom[2],"inception_4c/5x5");
	CHECK_EXPR_RET(strlen("inception_4c/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[81].bottom[3],"inception_4c/pool_proj");
	netParameter->layer[81].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[81].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[81].top[0],"inception_4c/output");
	CHECK_EXPR_RET(strlen("inception_4d/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[82].name,"inception_4d/1x1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[82].type,"Convolution");
	netParameter->layer[82].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[82].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[82].bottom[0],"inception_4c/output");
	netParameter->layer[82].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[82].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[82].top[0],"inception_4d/1x1");
	netParameter->layer[82].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[82].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[82].param[i].lr_mult = 1.0;//default value
		netParameter->layer[82].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[82].param[0].lr_mult = 1;
	netParameter->layer[82].param[0].decay_mult = 1;
	netParameter->layer[82].param[1].lr_mult = 2;
	netParameter->layer[82].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[82].convolution_param.bias_term = true;//default value
	netParameter->layer[82].convolution_param.pad_h = 0;//default value
	netParameter->layer[82].convolution_param.pad_w = 0;//default value
	netParameter->layer[82].convolution_param.group = 1;//default value
	netParameter->layer[82].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[82].convolution_param.axis = 1;//default value
	netParameter->layer[82].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[82].convolution_param.num_output = 112;
	netParameter->layer[82].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[82].convolution_param.kernel_size_size = 1;
	netParameter->layer[82].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[82].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[82].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[82].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[82].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[82].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[82].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[82].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[82].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[82].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[82].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[82].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[82].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[82].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[82].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[82].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[82].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[82].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[82].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[82].convolution_param.bias_filler.type,"constant");
	netParameter->layer[82].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4d/relu_1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[83].name,"inception_4d/relu_1x1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[83].type,"ReLU");
	netParameter->layer[83].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[83].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[83].bottom[0],"inception_4d/1x1");
	netParameter->layer[83].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[83].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[83].top[0],"inception_4d/1x1");
	CHECK_EXPR_RET(strlen("inception_4d/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[84].name,"inception_4d/3x3_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[84].type,"Convolution");
	netParameter->layer[84].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[84].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[84].bottom[0],"inception_4c/output");
	netParameter->layer[84].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[84].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[84].top[0],"inception_4d/3x3_reduce");
	netParameter->layer[84].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[84].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[84].param[i].lr_mult = 1.0;//default value
		netParameter->layer[84].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[84].param[0].lr_mult = 1;
	netParameter->layer[84].param[0].decay_mult = 1;
	netParameter->layer[84].param[1].lr_mult = 2;
	netParameter->layer[84].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[84].convolution_param.bias_term = true;//default value
	netParameter->layer[84].convolution_param.pad_h = 0;//default value
	netParameter->layer[84].convolution_param.pad_w = 0;//default value
	netParameter->layer[84].convolution_param.group = 1;//default value
	netParameter->layer[84].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[84].convolution_param.axis = 1;//default value
	netParameter->layer[84].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[84].convolution_param.num_output = 144;
	netParameter->layer[84].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[84].convolution_param.kernel_size_size = 1;
	netParameter->layer[84].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[84].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[84].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[84].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[84].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[84].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[84].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[84].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[84].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[84].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[84].convolution_param.weight_filler.std = 0.09;

	//Give default values begin:
	strcpy(netParameter->layer[84].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[84].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[84].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[84].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[84].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[84].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[84].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[84].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[84].convolution_param.bias_filler.type,"constant");
	netParameter->layer[84].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4d/relu_3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[85].name,"inception_4d/relu_3x3_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[85].type,"ReLU");
	netParameter->layer[85].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[85].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[85].bottom[0],"inception_4d/3x3_reduce");
	netParameter->layer[85].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[85].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[85].top[0],"inception_4d/3x3_reduce");
	CHECK_EXPR_RET(strlen("inception_4d/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[86].name,"inception_4d/3x3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[86].type,"Convolution");
	netParameter->layer[86].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[86].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[86].bottom[0],"inception_4d/3x3_reduce");
	netParameter->layer[86].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[86].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[86].top[0],"inception_4d/3x3");
	netParameter->layer[86].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[86].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[86].param[i].lr_mult = 1.0;//default value
		netParameter->layer[86].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[86].param[0].lr_mult = 1;
	netParameter->layer[86].param[0].decay_mult = 1;
	netParameter->layer[86].param[1].lr_mult = 2;
	netParameter->layer[86].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[86].convolution_param.bias_term = true;//default value
	netParameter->layer[86].convolution_param.pad_h = 0;//default value
	netParameter->layer[86].convolution_param.pad_w = 0;//default value
	netParameter->layer[86].convolution_param.group = 1;//default value
	netParameter->layer[86].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[86].convolution_param.axis = 1;//default value
	netParameter->layer[86].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[86].convolution_param.num_output = 288;
	netParameter->layer[86].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[86].convolution_param.pad_size = 1;
	netParameter->layer[86].convolution_param.pad[0] = 1;
	netParameter->layer[86].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[86].convolution_param.kernel_size_size = 1;
	netParameter->layer[86].convolution_param.kernel_size[0] = 3;

	//Give default values begin:
	strcpy(netParameter->layer[86].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[86].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[86].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[86].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[86].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[86].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[86].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[86].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[86].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[86].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[86].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[86].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[86].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[86].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[86].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[86].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[86].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[86].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[86].convolution_param.bias_filler.type,"constant");
	netParameter->layer[86].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4d/relu_3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[87].name,"inception_4d/relu_3x3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[87].type,"ReLU");
	netParameter->layer[87].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[87].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[87].bottom[0],"inception_4d/3x3");
	netParameter->layer[87].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[87].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[87].top[0],"inception_4d/3x3");
	CHECK_EXPR_RET(strlen("inception_4d/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[88].name,"inception_4d/5x5_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[88].type,"Convolution");
	netParameter->layer[88].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[88].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[88].bottom[0],"inception_4c/output");
	netParameter->layer[88].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[88].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[88].top[0],"inception_4d/5x5_reduce");
	netParameter->layer[88].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[88].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[88].param[i].lr_mult = 1.0;//default value
		netParameter->layer[88].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[88].param[0].lr_mult = 1;
	netParameter->layer[88].param[0].decay_mult = 1;
	netParameter->layer[88].param[1].lr_mult = 2;
	netParameter->layer[88].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[88].convolution_param.bias_term = true;//default value
	netParameter->layer[88].convolution_param.pad_h = 0;//default value
	netParameter->layer[88].convolution_param.pad_w = 0;//default value
	netParameter->layer[88].convolution_param.group = 1;//default value
	netParameter->layer[88].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[88].convolution_param.axis = 1;//default value
	netParameter->layer[88].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[88].convolution_param.num_output = 32;
	netParameter->layer[88].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[88].convolution_param.kernel_size_size = 1;
	netParameter->layer[88].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[88].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[88].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[88].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[88].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[88].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[88].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[88].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[88].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[88].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[88].convolution_param.weight_filler.std = 0.2;

	//Give default values begin:
	strcpy(netParameter->layer[88].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[88].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[88].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[88].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[88].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[88].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[88].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[88].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[88].convolution_param.bias_filler.type,"constant");
	netParameter->layer[88].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4d/relu_5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[89].name,"inception_4d/relu_5x5_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[89].type,"ReLU");
	netParameter->layer[89].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[89].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[89].bottom[0],"inception_4d/5x5_reduce");
	netParameter->layer[89].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[89].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[89].top[0],"inception_4d/5x5_reduce");
	CHECK_EXPR_RET(strlen("inception_4d/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[90].name,"inception_4d/5x5");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[90].type,"Convolution");
	netParameter->layer[90].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[90].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[90].bottom[0],"inception_4d/5x5_reduce");
	netParameter->layer[90].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[90].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[90].top[0],"inception_4d/5x5");
	netParameter->layer[90].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[90].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[90].param[i].lr_mult = 1.0;//default value
		netParameter->layer[90].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[90].param[0].lr_mult = 1;
	netParameter->layer[90].param[0].decay_mult = 1;
	netParameter->layer[90].param[1].lr_mult = 2;
	netParameter->layer[90].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[90].convolution_param.bias_term = true;//default value
	netParameter->layer[90].convolution_param.pad_h = 0;//default value
	netParameter->layer[90].convolution_param.pad_w = 0;//default value
	netParameter->layer[90].convolution_param.group = 1;//default value
	netParameter->layer[90].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[90].convolution_param.axis = 1;//default value
	netParameter->layer[90].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[90].convolution_param.num_output = 64;
	netParameter->layer[90].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[90].convolution_param.pad_size = 1;
	netParameter->layer[90].convolution_param.pad[0] = 2;
	netParameter->layer[90].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[90].convolution_param.kernel_size_size = 1;
	netParameter->layer[90].convolution_param.kernel_size[0] = 5;

	//Give default values begin:
	strcpy(netParameter->layer[90].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[90].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[90].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[90].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[90].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[90].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[90].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[90].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[90].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[90].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[90].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[90].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[90].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[90].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[90].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[90].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[90].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[90].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[90].convolution_param.bias_filler.type,"constant");
	netParameter->layer[90].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4d/relu_5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].name,"inception_4d/relu_5x5");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].type,"ReLU");
	netParameter->layer[91].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[91].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].bottom[0],"inception_4d/5x5");
	netParameter->layer[91].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[91].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].top[0],"inception_4d/5x5");
	CHECK_EXPR_RET(strlen("inception_4d/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].name,"inception_4d/pool");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].type,"Pooling");
	netParameter->layer[92].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[92].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4c/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].bottom[0],"inception_4c/output");
	netParameter->layer[92].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[92].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].top[0],"inception_4d/pool");

	//Give default values begin:
	netParameter->layer[92].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[92].pooling_param.pad = 0;//default value
	netParameter->layer[92].pooling_param.pad_h = 0;//default value
	netParameter->layer[92].pooling_param.pad_w = 0;//default value
	netParameter->layer[92].pooling_param.stride = 1;//default value
	netParameter->layer[92].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[92].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[92].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[92].pooling_param.kernel_size = 3;
	netParameter->layer[92].pooling_param.stride = 1;
	netParameter->layer[92].pooling_param.pad = 1;
	CHECK_EXPR_RET(strlen("inception_4d/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].name,"inception_4d/pool_proj");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].type,"Convolution");
	netParameter->layer[93].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[93].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].bottom[0],"inception_4d/pool");
	netParameter->layer[93].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[93].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].top[0],"inception_4d/pool_proj");
	netParameter->layer[93].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[93].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[93].param[i].lr_mult = 1.0;//default value
		netParameter->layer[93].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[93].param[0].lr_mult = 1;
	netParameter->layer[93].param[0].decay_mult = 1;
	netParameter->layer[93].param[1].lr_mult = 2;
	netParameter->layer[93].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[93].convolution_param.bias_term = true;//default value
	netParameter->layer[93].convolution_param.pad_h = 0;//default value
	netParameter->layer[93].convolution_param.pad_w = 0;//default value
	netParameter->layer[93].convolution_param.group = 1;//default value
	netParameter->layer[93].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[93].convolution_param.axis = 1;//default value
	netParameter->layer[93].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[93].convolution_param.num_output = 64;
	netParameter->layer[93].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[93].convolution_param.kernel_size_size = 1;
	netParameter->layer[93].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[93].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[93].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[93].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[93].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[93].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[93].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[93].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[93].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[93].convolution_param.weight_filler.std = 0.1;

	//Give default values begin:
	strcpy(netParameter->layer[93].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[93].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[93].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[93].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[93].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[93].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[93].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[93].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].convolution_param.bias_filler.type,"constant");
	netParameter->layer[93].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4d/relu_pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[94].name,"inception_4d/relu_pool_proj");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[94].type,"ReLU");
	netParameter->layer[94].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[94].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[94].bottom[0],"inception_4d/pool_proj");
	netParameter->layer[94].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[94].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[94].top[0],"inception_4d/pool_proj");
	CHECK_EXPR_RET(strlen("inception_4d/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[95].name,"inception_4d/output");
	CHECK_EXPR_RET(strlen("Concat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[95].type,"Concat");
	netParameter->layer[95].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*4);
	netParameter->layer[95].bottom_size = 4;
	CHECK_EXPR_RET(strlen("inception_4d/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[95].bottom[0],"inception_4d/1x1");
	CHECK_EXPR_RET(strlen("inception_4d/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[95].bottom[1],"inception_4d/3x3");
	CHECK_EXPR_RET(strlen("inception_4d/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[95].bottom[2],"inception_4d/5x5");
	CHECK_EXPR_RET(strlen("inception_4d/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[95].bottom[3],"inception_4d/pool_proj");
	netParameter->layer[95].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[95].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[95].top[0],"inception_4d/output");
	CHECK_EXPR_RET(strlen("inception_4e/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[96].name,"inception_4e/1x1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[96].type,"Convolution");
	netParameter->layer[96].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[96].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[96].bottom[0],"inception_4d/output");
	netParameter->layer[96].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[96].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[96].top[0],"inception_4e/1x1");
	netParameter->layer[96].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[96].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[96].param[i].lr_mult = 1.0;//default value
		netParameter->layer[96].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[96].param[0].lr_mult = 1;
	netParameter->layer[96].param[0].decay_mult = 1;
	netParameter->layer[96].param[1].lr_mult = 2;
	netParameter->layer[96].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[96].convolution_param.bias_term = true;//default value
	netParameter->layer[96].convolution_param.pad_h = 0;//default value
	netParameter->layer[96].convolution_param.pad_w = 0;//default value
	netParameter->layer[96].convolution_param.group = 1;//default value
	netParameter->layer[96].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[96].convolution_param.axis = 1;//default value
	netParameter->layer[96].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[96].convolution_param.num_output = 256;
	netParameter->layer[96].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[96].convolution_param.kernel_size_size = 1;
	netParameter->layer[96].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[96].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[96].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[96].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[96].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[96].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[96].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[96].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[96].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[96].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[96].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[96].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[96].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[96].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[96].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[96].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[96].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[96].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[96].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[96].convolution_param.bias_filler.type,"constant");
	netParameter->layer[96].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4e/relu_1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].name,"inception_4e/relu_1x1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].type,"ReLU");
	netParameter->layer[97].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[97].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].bottom[0],"inception_4e/1x1");
	netParameter->layer[97].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[97].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].top[0],"inception_4e/1x1");
	CHECK_EXPR_RET(strlen("inception_4e/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[98].name,"inception_4e/3x3_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[98].type,"Convolution");
	netParameter->layer[98].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[98].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[98].bottom[0],"inception_4d/output");
	netParameter->layer[98].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[98].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[98].top[0],"inception_4e/3x3_reduce");
	netParameter->layer[98].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[98].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[98].param[i].lr_mult = 1.0;//default value
		netParameter->layer[98].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[98].param[0].lr_mult = 1;
	netParameter->layer[98].param[0].decay_mult = 1;
	netParameter->layer[98].param[1].lr_mult = 2;
	netParameter->layer[98].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[98].convolution_param.bias_term = true;//default value
	netParameter->layer[98].convolution_param.pad_h = 0;//default value
	netParameter->layer[98].convolution_param.pad_w = 0;//default value
	netParameter->layer[98].convolution_param.group = 1;//default value
	netParameter->layer[98].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[98].convolution_param.axis = 1;//default value
	netParameter->layer[98].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[98].convolution_param.num_output = 160;
	netParameter->layer[98].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[98].convolution_param.kernel_size_size = 1;
	netParameter->layer[98].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[98].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[98].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[98].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[98].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[98].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[98].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[98].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[98].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[98].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[98].convolution_param.weight_filler.std = 0.09;

	//Give default values begin:
	strcpy(netParameter->layer[98].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[98].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[98].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[98].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[98].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[98].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[98].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[98].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[98].convolution_param.bias_filler.type,"constant");
	netParameter->layer[98].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4e/relu_3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[99].name,"inception_4e/relu_3x3_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[99].type,"ReLU");
	netParameter->layer[99].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[99].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[99].bottom[0],"inception_4e/3x3_reduce");
	netParameter->layer[99].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[99].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[99].top[0],"inception_4e/3x3_reduce");
	CHECK_EXPR_RET(strlen("inception_4e/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[100].name,"inception_4e/3x3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[100].type,"Convolution");
	netParameter->layer[100].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[100].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[100].bottom[0],"inception_4e/3x3_reduce");
	netParameter->layer[100].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[100].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[100].top[0],"inception_4e/3x3");
	netParameter->layer[100].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[100].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[100].param[i].lr_mult = 1.0;//default value
		netParameter->layer[100].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[100].param[0].lr_mult = 1;
	netParameter->layer[100].param[0].decay_mult = 1;
	netParameter->layer[100].param[1].lr_mult = 2;
	netParameter->layer[100].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[100].convolution_param.bias_term = true;//default value
	netParameter->layer[100].convolution_param.pad_h = 0;//default value
	netParameter->layer[100].convolution_param.pad_w = 0;//default value
	netParameter->layer[100].convolution_param.group = 1;//default value
	netParameter->layer[100].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[100].convolution_param.axis = 1;//default value
	netParameter->layer[100].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[100].convolution_param.num_output = 320;
	netParameter->layer[100].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[100].convolution_param.pad_size = 1;
	netParameter->layer[100].convolution_param.pad[0] = 1;
	netParameter->layer[100].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[100].convolution_param.kernel_size_size = 1;
	netParameter->layer[100].convolution_param.kernel_size[0] = 3;

	//Give default values begin:
	strcpy(netParameter->layer[100].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[100].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[100].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[100].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[100].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[100].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[100].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[100].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[100].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[100].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[100].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[100].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[100].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[100].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[100].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[100].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[100].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[100].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[100].convolution_param.bias_filler.type,"constant");
	netParameter->layer[100].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4e/relu_3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[101].name,"inception_4e/relu_3x3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[101].type,"ReLU");
	netParameter->layer[101].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[101].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[101].bottom[0],"inception_4e/3x3");
	netParameter->layer[101].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[101].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[101].top[0],"inception_4e/3x3");
	CHECK_EXPR_RET(strlen("inception_4e/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[102].name,"inception_4e/5x5_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[102].type,"Convolution");
	netParameter->layer[102].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[102].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[102].bottom[0],"inception_4d/output");
	netParameter->layer[102].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[102].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[102].top[0],"inception_4e/5x5_reduce");
	netParameter->layer[102].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[102].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[102].param[i].lr_mult = 1.0;//default value
		netParameter->layer[102].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[102].param[0].lr_mult = 1;
	netParameter->layer[102].param[0].decay_mult = 1;
	netParameter->layer[102].param[1].lr_mult = 2;
	netParameter->layer[102].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[102].convolution_param.bias_term = true;//default value
	netParameter->layer[102].convolution_param.pad_h = 0;//default value
	netParameter->layer[102].convolution_param.pad_w = 0;//default value
	netParameter->layer[102].convolution_param.group = 1;//default value
	netParameter->layer[102].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[102].convolution_param.axis = 1;//default value
	netParameter->layer[102].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[102].convolution_param.num_output = 32;
	netParameter->layer[102].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[102].convolution_param.kernel_size_size = 1;
	netParameter->layer[102].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[102].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[102].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[102].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[102].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[102].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[102].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[102].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[102].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[102].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[102].convolution_param.weight_filler.std = 0.2;

	//Give default values begin:
	strcpy(netParameter->layer[102].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[102].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[102].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[102].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[102].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[102].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[102].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[102].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[102].convolution_param.bias_filler.type,"constant");
	netParameter->layer[102].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4e/relu_5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[103].name,"inception_4e/relu_5x5_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[103].type,"ReLU");
	netParameter->layer[103].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[103].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[103].bottom[0],"inception_4e/5x5_reduce");
	netParameter->layer[103].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[103].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[103].top[0],"inception_4e/5x5_reduce");
	CHECK_EXPR_RET(strlen("inception_4e/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[104].name,"inception_4e/5x5");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[104].type,"Convolution");
	netParameter->layer[104].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[104].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[104].bottom[0],"inception_4e/5x5_reduce");
	netParameter->layer[104].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[104].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[104].top[0],"inception_4e/5x5");
	netParameter->layer[104].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[104].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[104].param[i].lr_mult = 1.0;//default value
		netParameter->layer[104].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[104].param[0].lr_mult = 1;
	netParameter->layer[104].param[0].decay_mult = 1;
	netParameter->layer[104].param[1].lr_mult = 2;
	netParameter->layer[104].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[104].convolution_param.bias_term = true;//default value
	netParameter->layer[104].convolution_param.pad_h = 0;//default value
	netParameter->layer[104].convolution_param.pad_w = 0;//default value
	netParameter->layer[104].convolution_param.group = 1;//default value
	netParameter->layer[104].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[104].convolution_param.axis = 1;//default value
	netParameter->layer[104].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[104].convolution_param.num_output = 128;
	netParameter->layer[104].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[104].convolution_param.pad_size = 1;
	netParameter->layer[104].convolution_param.pad[0] = 2;
	netParameter->layer[104].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[104].convolution_param.kernel_size_size = 1;
	netParameter->layer[104].convolution_param.kernel_size[0] = 5;

	//Give default values begin:
	strcpy(netParameter->layer[104].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[104].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[104].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[104].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[104].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[104].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[104].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[104].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[104].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[104].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[104].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[104].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[104].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[104].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[104].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[104].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[104].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[104].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[104].convolution_param.bias_filler.type,"constant");
	netParameter->layer[104].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4e/relu_5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[105].name,"inception_4e/relu_5x5");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[105].type,"ReLU");
	netParameter->layer[105].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[105].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[105].bottom[0],"inception_4e/5x5");
	netParameter->layer[105].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[105].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[105].top[0],"inception_4e/5x5");
	CHECK_EXPR_RET(strlen("inception_4e/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[106].name,"inception_4e/pool");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[106].type,"Pooling");
	netParameter->layer[106].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[106].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4d/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[106].bottom[0],"inception_4d/output");
	netParameter->layer[106].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[106].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[106].top[0],"inception_4e/pool");

	//Give default values begin:
	netParameter->layer[106].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[106].pooling_param.pad = 0;//default value
	netParameter->layer[106].pooling_param.pad_h = 0;//default value
	netParameter->layer[106].pooling_param.pad_w = 0;//default value
	netParameter->layer[106].pooling_param.stride = 1;//default value
	netParameter->layer[106].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[106].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[106].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[106].pooling_param.kernel_size = 3;
	netParameter->layer[106].pooling_param.stride = 1;
	netParameter->layer[106].pooling_param.pad = 1;
	CHECK_EXPR_RET(strlen("inception_4e/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[107].name,"inception_4e/pool_proj");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[107].type,"Convolution");
	netParameter->layer[107].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[107].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[107].bottom[0],"inception_4e/pool");
	netParameter->layer[107].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[107].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[107].top[0],"inception_4e/pool_proj");
	netParameter->layer[107].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[107].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[107].param[i].lr_mult = 1.0;//default value
		netParameter->layer[107].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[107].param[0].lr_mult = 1;
	netParameter->layer[107].param[0].decay_mult = 1;
	netParameter->layer[107].param[1].lr_mult = 2;
	netParameter->layer[107].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[107].convolution_param.bias_term = true;//default value
	netParameter->layer[107].convolution_param.pad_h = 0;//default value
	netParameter->layer[107].convolution_param.pad_w = 0;//default value
	netParameter->layer[107].convolution_param.group = 1;//default value
	netParameter->layer[107].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[107].convolution_param.axis = 1;//default value
	netParameter->layer[107].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[107].convolution_param.num_output = 128;
	netParameter->layer[107].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[107].convolution_param.kernel_size_size = 1;
	netParameter->layer[107].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[107].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[107].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[107].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[107].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[107].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[107].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[107].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[107].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[107].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[107].convolution_param.weight_filler.std = 0.1;

	//Give default values begin:
	strcpy(netParameter->layer[107].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[107].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[107].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[107].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[107].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[107].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[107].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[107].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[107].convolution_param.bias_filler.type,"constant");
	netParameter->layer[107].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_4e/relu_pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[108].name,"inception_4e/relu_pool_proj");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[108].type,"ReLU");
	netParameter->layer[108].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[108].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[108].bottom[0],"inception_4e/pool_proj");
	netParameter->layer[108].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[108].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[108].top[0],"inception_4e/pool_proj");
	CHECK_EXPR_RET(strlen("inception_4e/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[109].name,"inception_4e/output");
	CHECK_EXPR_RET(strlen("Concat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[109].type,"Concat");
	netParameter->layer[109].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*4);
	netParameter->layer[109].bottom_size = 4;
	CHECK_EXPR_RET(strlen("inception_4e/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[109].bottom[0],"inception_4e/1x1");
	CHECK_EXPR_RET(strlen("inception_4e/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[109].bottom[1],"inception_4e/3x3");
	CHECK_EXPR_RET(strlen("inception_4e/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[109].bottom[2],"inception_4e/5x5");
	CHECK_EXPR_RET(strlen("inception_4e/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[109].bottom[3],"inception_4e/pool_proj");
	netParameter->layer[109].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[109].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[109].top[0],"inception_4e/output");
	CHECK_EXPR_RET(strlen("pool4/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[110].name,"pool4/3x3_s2");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[110].type,"Pooling");
	netParameter->layer[110].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[110].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_4e/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[110].bottom[0],"inception_4e/output");
	netParameter->layer[110].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[110].top_size = 1;
	CHECK_EXPR_RET(strlen("pool4/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[110].top[0],"pool4/3x3_s2");

	//Give default values begin:
	netParameter->layer[110].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[110].pooling_param.pad = 0;//default value
	netParameter->layer[110].pooling_param.pad_h = 0;//default value
	netParameter->layer[110].pooling_param.pad_w = 0;//default value
	netParameter->layer[110].pooling_param.stride = 1;//default value
	netParameter->layer[110].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[110].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[110].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[110].pooling_param.kernel_size = 3;
	netParameter->layer[110].pooling_param.stride = 2;
	CHECK_EXPR_RET(strlen("inception_5a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[111].name,"inception_5a/1x1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[111].type,"Convolution");
	netParameter->layer[111].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[111].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool4/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[111].bottom[0],"pool4/3x3_s2");
	netParameter->layer[111].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[111].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[111].top[0],"inception_5a/1x1");
	netParameter->layer[111].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[111].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[111].param[i].lr_mult = 1.0;//default value
		netParameter->layer[111].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[111].param[0].lr_mult = 1;
	netParameter->layer[111].param[0].decay_mult = 1;
	netParameter->layer[111].param[1].lr_mult = 2;
	netParameter->layer[111].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[111].convolution_param.bias_term = true;//default value
	netParameter->layer[111].convolution_param.pad_h = 0;//default value
	netParameter->layer[111].convolution_param.pad_w = 0;//default value
	netParameter->layer[111].convolution_param.group = 1;//default value
	netParameter->layer[111].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[111].convolution_param.axis = 1;//default value
	netParameter->layer[111].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[111].convolution_param.num_output = 256;
	netParameter->layer[111].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[111].convolution_param.kernel_size_size = 1;
	netParameter->layer[111].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[111].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[111].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[111].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[111].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[111].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[111].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[111].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[111].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[111].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[111].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[111].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[111].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[111].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[111].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[111].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[111].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[111].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[111].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[111].convolution_param.bias_filler.type,"constant");
	netParameter->layer[111].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_5a/relu_1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[112].name,"inception_5a/relu_1x1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[112].type,"ReLU");
	netParameter->layer[112].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[112].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[112].bottom[0],"inception_5a/1x1");
	netParameter->layer[112].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[112].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[112].top[0],"inception_5a/1x1");
	CHECK_EXPR_RET(strlen("inception_5a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[113].name,"inception_5a/3x3_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[113].type,"Convolution");
	netParameter->layer[113].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[113].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool4/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[113].bottom[0],"pool4/3x3_s2");
	netParameter->layer[113].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[113].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[113].top[0],"inception_5a/3x3_reduce");
	netParameter->layer[113].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[113].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[113].param[i].lr_mult = 1.0;//default value
		netParameter->layer[113].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[113].param[0].lr_mult = 1;
	netParameter->layer[113].param[0].decay_mult = 1;
	netParameter->layer[113].param[1].lr_mult = 2;
	netParameter->layer[113].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[113].convolution_param.bias_term = true;//default value
	netParameter->layer[113].convolution_param.pad_h = 0;//default value
	netParameter->layer[113].convolution_param.pad_w = 0;//default value
	netParameter->layer[113].convolution_param.group = 1;//default value
	netParameter->layer[113].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[113].convolution_param.axis = 1;//default value
	netParameter->layer[113].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[113].convolution_param.num_output = 160;
	netParameter->layer[113].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[113].convolution_param.kernel_size_size = 1;
	netParameter->layer[113].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[113].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[113].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[113].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[113].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[113].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[113].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[113].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[113].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[113].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[113].convolution_param.weight_filler.std = 0.09;

	//Give default values begin:
	strcpy(netParameter->layer[113].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[113].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[113].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[113].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[113].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[113].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[113].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[113].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[113].convolution_param.bias_filler.type,"constant");
	netParameter->layer[113].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_5a/relu_3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[114].name,"inception_5a/relu_3x3_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[114].type,"ReLU");
	netParameter->layer[114].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[114].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[114].bottom[0],"inception_5a/3x3_reduce");
	netParameter->layer[114].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[114].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[114].top[0],"inception_5a/3x3_reduce");
	CHECK_EXPR_RET(strlen("inception_5a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[115].name,"inception_5a/3x3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[115].type,"Convolution");
	netParameter->layer[115].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[115].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[115].bottom[0],"inception_5a/3x3_reduce");
	netParameter->layer[115].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[115].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[115].top[0],"inception_5a/3x3");
	netParameter->layer[115].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[115].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[115].param[i].lr_mult = 1.0;//default value
		netParameter->layer[115].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[115].param[0].lr_mult = 1;
	netParameter->layer[115].param[0].decay_mult = 1;
	netParameter->layer[115].param[1].lr_mult = 2;
	netParameter->layer[115].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[115].convolution_param.bias_term = true;//default value
	netParameter->layer[115].convolution_param.pad_h = 0;//default value
	netParameter->layer[115].convolution_param.pad_w = 0;//default value
	netParameter->layer[115].convolution_param.group = 1;//default value
	netParameter->layer[115].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[115].convolution_param.axis = 1;//default value
	netParameter->layer[115].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[115].convolution_param.num_output = 320;
	netParameter->layer[115].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[115].convolution_param.pad_size = 1;
	netParameter->layer[115].convolution_param.pad[0] = 1;
	netParameter->layer[115].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[115].convolution_param.kernel_size_size = 1;
	netParameter->layer[115].convolution_param.kernel_size[0] = 3;

	//Give default values begin:
	strcpy(netParameter->layer[115].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[115].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[115].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[115].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[115].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[115].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[115].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[115].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[115].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[115].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[115].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[115].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[115].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[115].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[115].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[115].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[115].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[115].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[115].convolution_param.bias_filler.type,"constant");
	netParameter->layer[115].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_5a/relu_3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[116].name,"inception_5a/relu_3x3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[116].type,"ReLU");
	netParameter->layer[116].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[116].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[116].bottom[0],"inception_5a/3x3");
	netParameter->layer[116].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[116].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[116].top[0],"inception_5a/3x3");
	CHECK_EXPR_RET(strlen("inception_5a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[117].name,"inception_5a/5x5_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[117].type,"Convolution");
	netParameter->layer[117].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[117].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool4/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[117].bottom[0],"pool4/3x3_s2");
	netParameter->layer[117].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[117].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[117].top[0],"inception_5a/5x5_reduce");
	netParameter->layer[117].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[117].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[117].param[i].lr_mult = 1.0;//default value
		netParameter->layer[117].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[117].param[0].lr_mult = 1;
	netParameter->layer[117].param[0].decay_mult = 1;
	netParameter->layer[117].param[1].lr_mult = 2;
	netParameter->layer[117].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[117].convolution_param.bias_term = true;//default value
	netParameter->layer[117].convolution_param.pad_h = 0;//default value
	netParameter->layer[117].convolution_param.pad_w = 0;//default value
	netParameter->layer[117].convolution_param.group = 1;//default value
	netParameter->layer[117].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[117].convolution_param.axis = 1;//default value
	netParameter->layer[117].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[117].convolution_param.num_output = 32;
	netParameter->layer[117].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[117].convolution_param.kernel_size_size = 1;
	netParameter->layer[117].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[117].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[117].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[117].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[117].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[117].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[117].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[117].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[117].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[117].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[117].convolution_param.weight_filler.std = 0.2;

	//Give default values begin:
	strcpy(netParameter->layer[117].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[117].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[117].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[117].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[117].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[117].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[117].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[117].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[117].convolution_param.bias_filler.type,"constant");
	netParameter->layer[117].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_5a/relu_5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[118].name,"inception_5a/relu_5x5_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[118].type,"ReLU");
	netParameter->layer[118].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[118].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[118].bottom[0],"inception_5a/5x5_reduce");
	netParameter->layer[118].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[118].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[118].top[0],"inception_5a/5x5_reduce");
	CHECK_EXPR_RET(strlen("inception_5a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[119].name,"inception_5a/5x5");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[119].type,"Convolution");
	netParameter->layer[119].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[119].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[119].bottom[0],"inception_5a/5x5_reduce");
	netParameter->layer[119].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[119].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[119].top[0],"inception_5a/5x5");
	netParameter->layer[119].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[119].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[119].param[i].lr_mult = 1.0;//default value
		netParameter->layer[119].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[119].param[0].lr_mult = 1;
	netParameter->layer[119].param[0].decay_mult = 1;
	netParameter->layer[119].param[1].lr_mult = 2;
	netParameter->layer[119].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[119].convolution_param.bias_term = true;//default value
	netParameter->layer[119].convolution_param.pad_h = 0;//default value
	netParameter->layer[119].convolution_param.pad_w = 0;//default value
	netParameter->layer[119].convolution_param.group = 1;//default value
	netParameter->layer[119].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[119].convolution_param.axis = 1;//default value
	netParameter->layer[119].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[119].convolution_param.num_output = 128;
	netParameter->layer[119].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[119].convolution_param.pad_size = 1;
	netParameter->layer[119].convolution_param.pad[0] = 2;
	netParameter->layer[119].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[119].convolution_param.kernel_size_size = 1;
	netParameter->layer[119].convolution_param.kernel_size[0] = 5;

	//Give default values begin:
	strcpy(netParameter->layer[119].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[119].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[119].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[119].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[119].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[119].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[119].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[119].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[119].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[119].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[119].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[119].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[119].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[119].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[119].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[119].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[119].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[119].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[119].convolution_param.bias_filler.type,"constant");
	netParameter->layer[119].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_5a/relu_5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[120].name,"inception_5a/relu_5x5");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[120].type,"ReLU");
	netParameter->layer[120].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[120].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[120].bottom[0],"inception_5a/5x5");
	netParameter->layer[120].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[120].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[120].top[0],"inception_5a/5x5");
	CHECK_EXPR_RET(strlen("inception_5a/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[121].name,"inception_5a/pool");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[121].type,"Pooling");
	netParameter->layer[121].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[121].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool4/3x3_s2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[121].bottom[0],"pool4/3x3_s2");
	netParameter->layer[121].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[121].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[121].top[0],"inception_5a/pool");

	//Give default values begin:
	netParameter->layer[121].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[121].pooling_param.pad = 0;//default value
	netParameter->layer[121].pooling_param.pad_h = 0;//default value
	netParameter->layer[121].pooling_param.pad_w = 0;//default value
	netParameter->layer[121].pooling_param.stride = 1;//default value
	netParameter->layer[121].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[121].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[121].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[121].pooling_param.kernel_size = 3;
	netParameter->layer[121].pooling_param.stride = 1;
	netParameter->layer[121].pooling_param.pad = 1;
	CHECK_EXPR_RET(strlen("inception_5a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[122].name,"inception_5a/pool_proj");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[122].type,"Convolution");
	netParameter->layer[122].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[122].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[122].bottom[0],"inception_5a/pool");
	netParameter->layer[122].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[122].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[122].top[0],"inception_5a/pool_proj");
	netParameter->layer[122].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[122].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[122].param[i].lr_mult = 1.0;//default value
		netParameter->layer[122].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[122].param[0].lr_mult = 1;
	netParameter->layer[122].param[0].decay_mult = 1;
	netParameter->layer[122].param[1].lr_mult = 2;
	netParameter->layer[122].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[122].convolution_param.bias_term = true;//default value
	netParameter->layer[122].convolution_param.pad_h = 0;//default value
	netParameter->layer[122].convolution_param.pad_w = 0;//default value
	netParameter->layer[122].convolution_param.group = 1;//default value
	netParameter->layer[122].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[122].convolution_param.axis = 1;//default value
	netParameter->layer[122].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[122].convolution_param.num_output = 128;
	netParameter->layer[122].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[122].convolution_param.kernel_size_size = 1;
	netParameter->layer[122].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[122].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[122].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[122].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[122].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[122].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[122].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[122].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[122].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[122].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[122].convolution_param.weight_filler.std = 0.1;

	//Give default values begin:
	strcpy(netParameter->layer[122].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[122].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[122].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[122].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[122].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[122].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[122].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[122].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[122].convolution_param.bias_filler.type,"constant");
	netParameter->layer[122].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_5a/relu_pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[123].name,"inception_5a/relu_pool_proj");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[123].type,"ReLU");
	netParameter->layer[123].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[123].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[123].bottom[0],"inception_5a/pool_proj");
	netParameter->layer[123].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[123].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[123].top[0],"inception_5a/pool_proj");
	CHECK_EXPR_RET(strlen("inception_5a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[124].name,"inception_5a/output");
	CHECK_EXPR_RET(strlen("Concat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[124].type,"Concat");
	netParameter->layer[124].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*4);
	netParameter->layer[124].bottom_size = 4;
	CHECK_EXPR_RET(strlen("inception_5a/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[124].bottom[0],"inception_5a/1x1");
	CHECK_EXPR_RET(strlen("inception_5a/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[124].bottom[1],"inception_5a/3x3");
	CHECK_EXPR_RET(strlen("inception_5a/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[124].bottom[2],"inception_5a/5x5");
	CHECK_EXPR_RET(strlen("inception_5a/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[124].bottom[3],"inception_5a/pool_proj");
	netParameter->layer[124].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[124].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[124].top[0],"inception_5a/output");
	CHECK_EXPR_RET(strlen("inception_5b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[125].name,"inception_5b/1x1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[125].type,"Convolution");
	netParameter->layer[125].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[125].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[125].bottom[0],"inception_5a/output");
	netParameter->layer[125].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[125].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[125].top[0],"inception_5b/1x1");
	netParameter->layer[125].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[125].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[125].param[i].lr_mult = 1.0;//default value
		netParameter->layer[125].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[125].param[0].lr_mult = 1;
	netParameter->layer[125].param[0].decay_mult = 1;
	netParameter->layer[125].param[1].lr_mult = 2;
	netParameter->layer[125].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[125].convolution_param.bias_term = true;//default value
	netParameter->layer[125].convolution_param.pad_h = 0;//default value
	netParameter->layer[125].convolution_param.pad_w = 0;//default value
	netParameter->layer[125].convolution_param.group = 1;//default value
	netParameter->layer[125].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[125].convolution_param.axis = 1;//default value
	netParameter->layer[125].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[125].convolution_param.num_output = 384;
	netParameter->layer[125].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[125].convolution_param.kernel_size_size = 1;
	netParameter->layer[125].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[125].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[125].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[125].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[125].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[125].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[125].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[125].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[125].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[125].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[125].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[125].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[125].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[125].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[125].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[125].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[125].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[125].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[125].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[125].convolution_param.bias_filler.type,"constant");
	netParameter->layer[125].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_5b/relu_1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[126].name,"inception_5b/relu_1x1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[126].type,"ReLU");
	netParameter->layer[126].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[126].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[126].bottom[0],"inception_5b/1x1");
	netParameter->layer[126].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[126].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[126].top[0],"inception_5b/1x1");
	CHECK_EXPR_RET(strlen("inception_5b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[127].name,"inception_5b/3x3_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[127].type,"Convolution");
	netParameter->layer[127].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[127].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[127].bottom[0],"inception_5a/output");
	netParameter->layer[127].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[127].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[127].top[0],"inception_5b/3x3_reduce");
	netParameter->layer[127].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[127].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[127].param[i].lr_mult = 1.0;//default value
		netParameter->layer[127].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[127].param[0].lr_mult = 1;
	netParameter->layer[127].param[0].decay_mult = 1;
	netParameter->layer[127].param[1].lr_mult = 2;
	netParameter->layer[127].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[127].convolution_param.bias_term = true;//default value
	netParameter->layer[127].convolution_param.pad_h = 0;//default value
	netParameter->layer[127].convolution_param.pad_w = 0;//default value
	netParameter->layer[127].convolution_param.group = 1;//default value
	netParameter->layer[127].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[127].convolution_param.axis = 1;//default value
	netParameter->layer[127].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[127].convolution_param.num_output = 192;
	netParameter->layer[127].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[127].convolution_param.kernel_size_size = 1;
	netParameter->layer[127].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[127].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[127].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[127].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[127].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[127].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[127].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[127].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[127].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[127].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[127].convolution_param.weight_filler.std = 0.09;

	//Give default values begin:
	strcpy(netParameter->layer[127].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[127].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[127].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[127].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[127].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[127].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[127].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[127].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[127].convolution_param.bias_filler.type,"constant");
	netParameter->layer[127].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_5b/relu_3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[128].name,"inception_5b/relu_3x3_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[128].type,"ReLU");
	netParameter->layer[128].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[128].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[128].bottom[0],"inception_5b/3x3_reduce");
	netParameter->layer[128].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[128].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[128].top[0],"inception_5b/3x3_reduce");
	CHECK_EXPR_RET(strlen("inception_5b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[129].name,"inception_5b/3x3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[129].type,"Convolution");
	netParameter->layer[129].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[129].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/3x3_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[129].bottom[0],"inception_5b/3x3_reduce");
	netParameter->layer[129].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[129].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[129].top[0],"inception_5b/3x3");
	netParameter->layer[129].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[129].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[129].param[i].lr_mult = 1.0;//default value
		netParameter->layer[129].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[129].param[0].lr_mult = 1;
	netParameter->layer[129].param[0].decay_mult = 1;
	netParameter->layer[129].param[1].lr_mult = 2;
	netParameter->layer[129].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[129].convolution_param.bias_term = true;//default value
	netParameter->layer[129].convolution_param.pad_h = 0;//default value
	netParameter->layer[129].convolution_param.pad_w = 0;//default value
	netParameter->layer[129].convolution_param.group = 1;//default value
	netParameter->layer[129].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[129].convolution_param.axis = 1;//default value
	netParameter->layer[129].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[129].convolution_param.num_output = 384;
	netParameter->layer[129].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[129].convolution_param.pad_size = 1;
	netParameter->layer[129].convolution_param.pad[0] = 1;
	netParameter->layer[129].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[129].convolution_param.kernel_size_size = 1;
	netParameter->layer[129].convolution_param.kernel_size[0] = 3;

	//Give default values begin:
	strcpy(netParameter->layer[129].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[129].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[129].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[129].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[129].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[129].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[129].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[129].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[129].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[129].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[129].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[129].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[129].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[129].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[129].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[129].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[129].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[129].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[129].convolution_param.bias_filler.type,"constant");
	netParameter->layer[129].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_5b/relu_3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[130].name,"inception_5b/relu_3x3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[130].type,"ReLU");
	netParameter->layer[130].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[130].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[130].bottom[0],"inception_5b/3x3");
	netParameter->layer[130].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[130].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[130].top[0],"inception_5b/3x3");
	CHECK_EXPR_RET(strlen("inception_5b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[131].name,"inception_5b/5x5_reduce");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[131].type,"Convolution");
	netParameter->layer[131].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[131].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[131].bottom[0],"inception_5a/output");
	netParameter->layer[131].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[131].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[131].top[0],"inception_5b/5x5_reduce");
	netParameter->layer[131].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[131].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[131].param[i].lr_mult = 1.0;//default value
		netParameter->layer[131].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[131].param[0].lr_mult = 1;
	netParameter->layer[131].param[0].decay_mult = 1;
	netParameter->layer[131].param[1].lr_mult = 2;
	netParameter->layer[131].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[131].convolution_param.bias_term = true;//default value
	netParameter->layer[131].convolution_param.pad_h = 0;//default value
	netParameter->layer[131].convolution_param.pad_w = 0;//default value
	netParameter->layer[131].convolution_param.group = 1;//default value
	netParameter->layer[131].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[131].convolution_param.axis = 1;//default value
	netParameter->layer[131].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[131].convolution_param.num_output = 48;
	netParameter->layer[131].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[131].convolution_param.kernel_size_size = 1;
	netParameter->layer[131].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[131].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[131].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[131].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[131].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[131].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[131].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[131].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[131].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[131].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[131].convolution_param.weight_filler.std = 0.2;

	//Give default values begin:
	strcpy(netParameter->layer[131].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[131].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[131].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[131].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[131].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[131].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[131].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[131].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[131].convolution_param.bias_filler.type,"constant");
	netParameter->layer[131].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_5b/relu_5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[132].name,"inception_5b/relu_5x5_reduce");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[132].type,"ReLU");
	netParameter->layer[132].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[132].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[132].bottom[0],"inception_5b/5x5_reduce");
	netParameter->layer[132].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[132].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[132].top[0],"inception_5b/5x5_reduce");
	CHECK_EXPR_RET(strlen("inception_5b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[133].name,"inception_5b/5x5");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[133].type,"Convolution");
	netParameter->layer[133].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[133].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/5x5_reduce") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[133].bottom[0],"inception_5b/5x5_reduce");
	netParameter->layer[133].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[133].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[133].top[0],"inception_5b/5x5");
	netParameter->layer[133].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[133].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[133].param[i].lr_mult = 1.0;//default value
		netParameter->layer[133].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[133].param[0].lr_mult = 1;
	netParameter->layer[133].param[0].decay_mult = 1;
	netParameter->layer[133].param[1].lr_mult = 2;
	netParameter->layer[133].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[133].convolution_param.bias_term = true;//default value
	netParameter->layer[133].convolution_param.pad_h = 0;//default value
	netParameter->layer[133].convolution_param.pad_w = 0;//default value
	netParameter->layer[133].convolution_param.group = 1;//default value
	netParameter->layer[133].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[133].convolution_param.axis = 1;//default value
	netParameter->layer[133].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[133].convolution_param.num_output = 128;
	netParameter->layer[133].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[133].convolution_param.pad_size = 1;
	netParameter->layer[133].convolution_param.pad[0] = 2;
	netParameter->layer[133].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[133].convolution_param.kernel_size_size = 1;
	netParameter->layer[133].convolution_param.kernel_size[0] = 5;

	//Give default values begin:
	strcpy(netParameter->layer[133].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[133].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[133].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[133].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[133].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[133].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[133].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[133].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[133].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[133].convolution_param.weight_filler.std = 0.03;

	//Give default values begin:
	strcpy(netParameter->layer[133].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[133].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[133].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[133].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[133].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[133].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[133].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[133].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[133].convolution_param.bias_filler.type,"constant");
	netParameter->layer[133].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_5b/relu_5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[134].name,"inception_5b/relu_5x5");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[134].type,"ReLU");
	netParameter->layer[134].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[134].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[134].bottom[0],"inception_5b/5x5");
	netParameter->layer[134].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[134].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[134].top[0],"inception_5b/5x5");
	CHECK_EXPR_RET(strlen("inception_5b/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[135].name,"inception_5b/pool");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[135].type,"Pooling");
	netParameter->layer[135].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[135].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5a/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[135].bottom[0],"inception_5a/output");
	netParameter->layer[135].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[135].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[135].top[0],"inception_5b/pool");

	//Give default values begin:
	netParameter->layer[135].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[135].pooling_param.pad = 0;//default value
	netParameter->layer[135].pooling_param.pad_h = 0;//default value
	netParameter->layer[135].pooling_param.pad_w = 0;//default value
	netParameter->layer[135].pooling_param.stride = 1;//default value
	netParameter->layer[135].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[135].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[135].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[135].pooling_param.kernel_size = 3;
	netParameter->layer[135].pooling_param.stride = 1;
	netParameter->layer[135].pooling_param.pad = 1;
	CHECK_EXPR_RET(strlen("inception_5b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[136].name,"inception_5b/pool_proj");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[136].type,"Convolution");
	netParameter->layer[136].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[136].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/pool") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[136].bottom[0],"inception_5b/pool");
	netParameter->layer[136].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[136].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[136].top[0],"inception_5b/pool_proj");
	netParameter->layer[136].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[136].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[136].param[i].lr_mult = 1.0;//default value
		netParameter->layer[136].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[136].param[0].lr_mult = 1;
	netParameter->layer[136].param[0].decay_mult = 1;
	netParameter->layer[136].param[1].lr_mult = 2;
	netParameter->layer[136].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[136].convolution_param.bias_term = true;//default value
	netParameter->layer[136].convolution_param.pad_h = 0;//default value
	netParameter->layer[136].convolution_param.pad_w = 0;//default value
	netParameter->layer[136].convolution_param.group = 1;//default value
	netParameter->layer[136].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[136].convolution_param.axis = 1;//default value
	netParameter->layer[136].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[136].convolution_param.num_output = 128;
	netParameter->layer[136].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[136].convolution_param.kernel_size_size = 1;
	netParameter->layer[136].convolution_param.kernel_size[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[136].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[136].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[136].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[136].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[136].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[136].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[136].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[136].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[136].convolution_param.weight_filler.type,"xavier");
	netParameter->layer[136].convolution_param.weight_filler.std = 0.1;

	//Give default values begin:
	strcpy(netParameter->layer[136].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[136].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[136].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[136].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[136].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[136].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[136].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[136].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[136].convolution_param.bias_filler.type,"constant");
	netParameter->layer[136].convolution_param.bias_filler.value = 0.2;
	CHECK_EXPR_RET(strlen("inception_5b/relu_pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[137].name,"inception_5b/relu_pool_proj");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[137].type,"ReLU");
	netParameter->layer[137].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[137].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[137].bottom[0],"inception_5b/pool_proj");
	netParameter->layer[137].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[137].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[137].top[0],"inception_5b/pool_proj");
	CHECK_EXPR_RET(strlen("inception_5b/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[138].name,"inception_5b/output");
	CHECK_EXPR_RET(strlen("Concat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[138].type,"Concat");
	netParameter->layer[138].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*4);
	netParameter->layer[138].bottom_size = 4;
	CHECK_EXPR_RET(strlen("inception_5b/1x1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[138].bottom[0],"inception_5b/1x1");
	CHECK_EXPR_RET(strlen("inception_5b/3x3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[138].bottom[1],"inception_5b/3x3");
	CHECK_EXPR_RET(strlen("inception_5b/5x5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[138].bottom[2],"inception_5b/5x5");
	CHECK_EXPR_RET(strlen("inception_5b/pool_proj") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[138].bottom[3],"inception_5b/pool_proj");
	netParameter->layer[138].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[138].top_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[138].top[0],"inception_5b/output");
	CHECK_EXPR_RET(strlen("pool5/7x7_s1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[139].name,"pool5/7x7_s1");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[139].type,"Pooling");
	netParameter->layer[139].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[139].bottom_size = 1;
	CHECK_EXPR_RET(strlen("inception_5b/output") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[139].bottom[0],"inception_5b/output");
	netParameter->layer[139].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[139].top_size = 1;
	CHECK_EXPR_RET(strlen("pool5/7x7_s1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[139].top[0],"pool5/7x7_s1");

	//Give default values begin:
	netParameter->layer[139].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[139].pooling_param.pad = 0;//default value
	netParameter->layer[139].pooling_param.pad_h = 0;//default value
	netParameter->layer[139].pooling_param.pad_w = 0;//default value
	netParameter->layer[139].pooling_param.stride = 1;//default value
	netParameter->layer[139].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[139].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[139].pooling_param.pool = PoolingParameter_PoolMethod_AVE;
	netParameter->layer[139].pooling_param.kernel_size = 7;
	netParameter->layer[139].pooling_param.stride = 1;
	CHECK_EXPR_RET(strlen("pool5/drop_7x7_s1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[140].name,"pool5/drop_7x7_s1");
	CHECK_EXPR_RET(strlen("Dropout") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[140].type,"Dropout");
	netParameter->layer[140].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[140].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool5/7x7_s1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[140].bottom[0],"pool5/7x7_s1");
	netParameter->layer[140].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[140].top_size = 1;
	CHECK_EXPR_RET(strlen("pool5/7x7_s1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[140].top[0],"pool5/7x7_s1");

	//Give default values begin:
	netParameter->layer[140].dropout_param.dropout_ratio = 0.5;//default value
	//Give default values end

	netParameter->layer[140].dropout_param.dropout_ratio = 0.4;
	CHECK_EXPR_RET(strlen("loss3/classifier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[141].name,"loss3/classifier");
	CHECK_EXPR_RET(strlen("InnerProduct") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[141].type,"InnerProduct");
	netParameter->layer[141].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[141].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool5/7x7_s1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[141].bottom[0],"pool5/7x7_s1");
	netParameter->layer[141].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[141].top_size = 1;
	CHECK_EXPR_RET(strlen("loss3/classifier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[141].top[0],"loss3/classifier");
	netParameter->layer[141].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[141].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[141].param[i].lr_mult = 1.0;//default value
		netParameter->layer[141].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[141].param[0].lr_mult = 1;
	netParameter->layer[141].param[0].decay_mult = 1;
	netParameter->layer[141].param[1].lr_mult = 2;
	netParameter->layer[141].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[141].inner_product_param.bias_term = true;//default value
	netParameter->layer[141].inner_product_param.axis = 1;//default value
	netParameter->layer[141].inner_product_param.transpose = false;//default value
	//Give default values end

	netParameter->layer[141].inner_product_param.num_output = 1000;

	//Give default values begin:
	strcpy(netParameter->layer[141].inner_product_param.weight_filler.type,"constant");//default value
	netParameter->layer[141].inner_product_param.weight_filler.value = 0;//default value
	netParameter->layer[141].inner_product_param.weight_filler.min = 0;//default value
	netParameter->layer[141].inner_product_param.weight_filler.max = 1;//default value
	netParameter->layer[141].inner_product_param.weight_filler.mean = 0;//default value
	netParameter->layer[141].inner_product_param.weight_filler.std = 1;//default value
	netParameter->layer[141].inner_product_param.weight_filler.sparse = -1;//default value
	netParameter->layer[141].inner_product_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[141].inner_product_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[141].inner_product_param.bias_filler.type,"constant");//default value
	netParameter->layer[141].inner_product_param.bias_filler.value = 0;//default value
	netParameter->layer[141].inner_product_param.bias_filler.min = 0;//default value
	netParameter->layer[141].inner_product_param.bias_filler.max = 1;//default value
	netParameter->layer[141].inner_product_param.bias_filler.mean = 0;//default value
	netParameter->layer[141].inner_product_param.bias_filler.std = 1;//default value
	netParameter->layer[141].inner_product_param.bias_filler.sparse = -1;//default value
	netParameter->layer[141].inner_product_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[141].inner_product_param.bias_filler.type,"constant");
	netParameter->layer[141].inner_product_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("prob") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[142].name,"prob");
	CHECK_EXPR_RET(strlen("Softmax") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[142].type,"Softmax");
	netParameter->layer[142].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[142].bottom_size = 1;
	CHECK_EXPR_RET(strlen("loss3/classifier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[142].bottom[0],"loss3/classifier");
	netParameter->layer[142].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[142].top_size = 1;
	CHECK_EXPR_RET(strlen("prob") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[142].top[0],"prob");
	return 0;

}
