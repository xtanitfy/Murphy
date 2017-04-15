#include "parameter.h"
int parse(NetParameter * netParameter)
{
	CHECK_EXPR_RET(strlen("VGG_VOC0712_SSD_300x300_deploy") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->name,"VGG_VOC0712_SSD_300x300_deploy");
	netParameter->input = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->input_size = 1;
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->input[0],"data");
	netParameter->input_shape = (BlobShape *)malloc(sizeof(BlobShape)*1);
	netParameter->input_shape_size = 1;
	netParameter->input_shape[0].dim = (INT64 *)malloc(sizeof(INT64)*4);
	netParameter->input_shape[0].dim_size = 4;
	netParameter->input_shape[0].dim[0] = 1;
	netParameter->input_shape[0].dim[1] = 3;
	netParameter->input_shape[0].dim[2] = 300;
	netParameter->input_shape[0].dim[3] = 300;
	netParameter->layer = (LayerParameter *)malloc(sizeof(LayerParameter)*98);
	netParameter->layer_size = 98;
	CHECK_EXPR_RET(strlen("conv1_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].name,"conv1_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].type,"Convolution");
	netParameter->layer[0].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[0].bottom_size = 1;
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].bottom[0],"data");
	netParameter->layer[0].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[0].top_size = 1;
	CHECK_EXPR_RET(strlen("conv1_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].top[0],"conv1_1");
	netParameter->layer[0].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[0].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[0].param[i].lr_mult = 1.0;//default value
		netParameter->layer[0].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[0].param[0].lr_mult = 0;
	netParameter->layer[0].param[0].decay_mult = 0;
	netParameter->layer[0].param[1].lr_mult = 0;
	netParameter->layer[0].param[1].decay_mult = 0;

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

	//Give default values begin:
	strcpy(netParameter->layer[0].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[0].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[0].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[0].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[0].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[0].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[0].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[0].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[0].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[0].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[0].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[0].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[0].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[0].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[0].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[0].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].convolution_param.bias_filler.type,"constant");
	netParameter->layer[0].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu1_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].name,"relu1_1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].type,"ReLU");
	netParameter->layer[1].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[1].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv1_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].bottom[0],"conv1_1");
	netParameter->layer[1].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[1].top_size = 1;
	CHECK_EXPR_RET(strlen("conv1_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].top[0],"conv1_1");
	CHECK_EXPR_RET(strlen("conv1_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].name,"conv1_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].type,"Convolution");
	netParameter->layer[2].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[2].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv1_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].bottom[0],"conv1_1");
	netParameter->layer[2].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[2].top_size = 1;
	CHECK_EXPR_RET(strlen("conv1_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].top[0],"conv1_2");
	netParameter->layer[2].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[2].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[2].param[i].lr_mult = 1.0;//default value
		netParameter->layer[2].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[2].param[0].lr_mult = 0;
	netParameter->layer[2].param[0].decay_mult = 0;
	netParameter->layer[2].param[1].lr_mult = 0;
	netParameter->layer[2].param[1].decay_mult = 0;

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

	//Give default values begin:
	strcpy(netParameter->layer[2].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[2].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[2].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[2].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[2].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[2].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[2].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[2].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[2].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[2].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[2].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[2].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[2].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[2].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[2].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[2].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].convolution_param.bias_filler.type,"constant");
	netParameter->layer[2].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu1_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].name,"relu1_2");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].type,"ReLU");
	netParameter->layer[3].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[3].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv1_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].bottom[0],"conv1_2");
	netParameter->layer[3].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[3].top_size = 1;
	CHECK_EXPR_RET(strlen("conv1_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].top[0],"conv1_2");
	CHECK_EXPR_RET(strlen("pool1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].name,"pool1");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].type,"Pooling");
	netParameter->layer[4].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[4].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv1_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].bottom[0],"conv1_2");
	netParameter->layer[4].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[4].top_size = 1;
	CHECK_EXPR_RET(strlen("pool1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].top[0],"pool1");

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
	CHECK_EXPR_RET(strlen("conv2_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].name,"conv2_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].type,"Convolution");
	netParameter->layer[5].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[5].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].bottom[0],"pool1");
	netParameter->layer[5].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[5].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].top[0],"conv2_1");
	netParameter->layer[5].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[5].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[5].param[i].lr_mult = 1.0;//default value
		netParameter->layer[5].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[5].param[0].lr_mult = 0;
	netParameter->layer[5].param[0].decay_mult = 0;
	netParameter->layer[5].param[1].lr_mult = 0;
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

	netParameter->layer[5].convolution_param.num_output = 128;
	netParameter->layer[5].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[5].convolution_param.pad_size = 1;
	netParameter->layer[5].convolution_param.pad[0] = 1;
	netParameter->layer[5].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[5].convolution_param.kernel_size_size = 1;
	netParameter->layer[5].convolution_param.kernel_size[0] = 3;

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
	netParameter->layer[5].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu2_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].name,"relu2_1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].type,"ReLU");
	netParameter->layer[6].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[6].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].bottom[0],"conv2_1");
	netParameter->layer[6].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[6].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].top[0],"conv2_1");
	CHECK_EXPR_RET(strlen("conv2_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].name,"conv2_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].type,"Convolution");
	netParameter->layer[7].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[7].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].bottom[0],"conv2_1");
	netParameter->layer[7].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[7].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].top[0],"conv2_2");
	netParameter->layer[7].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[7].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[7].param[i].lr_mult = 1.0;//default value
		netParameter->layer[7].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[7].param[0].lr_mult = 0;
	netParameter->layer[7].param[0].decay_mult = 0;
	netParameter->layer[7].param[1].lr_mult = 0;
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

	netParameter->layer[7].convolution_param.num_output = 128;
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
	netParameter->layer[7].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu2_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].name,"relu2_2");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].type,"ReLU");
	netParameter->layer[8].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[8].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].bottom[0],"conv2_2");
	netParameter->layer[8].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[8].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].top[0],"conv2_2");
	CHECK_EXPR_RET(strlen("pool2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].name,"pool2");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].type,"Pooling");
	netParameter->layer[9].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[9].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].bottom[0],"conv2_2");
	netParameter->layer[9].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[9].top_size = 1;
	CHECK_EXPR_RET(strlen("pool2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].top[0],"pool2");

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
	CHECK_EXPR_RET(strlen("conv3_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].name,"conv3_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].type,"Convolution");
	netParameter->layer[10].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[10].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].bottom[0],"pool2");
	netParameter->layer[10].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[10].top_size = 1;
	CHECK_EXPR_RET(strlen("conv3_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].top[0],"conv3_1");
	netParameter->layer[10].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[10].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[10].param[i].lr_mult = 1.0;//default value
		netParameter->layer[10].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[10].param[0].lr_mult = 1;
	netParameter->layer[10].param[0].decay_mult = 1;
	netParameter->layer[10].param[1].lr_mult = 2;
	netParameter->layer[10].param[1].decay_mult = 0;

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

	//Give default values begin:
	strcpy(netParameter->layer[10].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[10].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[10].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[10].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[10].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[10].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[10].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[10].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[10].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[10].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[10].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[10].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[10].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[10].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[10].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[10].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].convolution_param.bias_filler.type,"constant");
	netParameter->layer[10].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu3_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].name,"relu3_1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].type,"ReLU");
	netParameter->layer[11].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[11].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv3_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].bottom[0],"conv3_1");
	netParameter->layer[11].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[11].top_size = 1;
	CHECK_EXPR_RET(strlen("conv3_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[11].top[0],"conv3_1");
	CHECK_EXPR_RET(strlen("conv3_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].name,"conv3_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].type,"Convolution");
	netParameter->layer[12].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[12].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv3_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].bottom[0],"conv3_1");
	netParameter->layer[12].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[12].top_size = 1;
	CHECK_EXPR_RET(strlen("conv3_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].top[0],"conv3_2");
	netParameter->layer[12].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[12].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[12].param[i].lr_mult = 1.0;//default value
		netParameter->layer[12].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[12].param[0].lr_mult = 1;
	netParameter->layer[12].param[0].decay_mult = 1;
	netParameter->layer[12].param[1].lr_mult = 2;
	netParameter->layer[12].param[1].decay_mult = 0;

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

	//Give default values begin:
	strcpy(netParameter->layer[12].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[12].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[12].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[12].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[12].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[12].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[12].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[12].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[12].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[12].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[12].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[12].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[12].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[12].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[12].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[12].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[12].convolution_param.bias_filler.type,"constant");
	netParameter->layer[12].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu3_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].name,"relu3_2");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].type,"ReLU");
	netParameter->layer[13].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[13].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv3_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].bottom[0],"conv3_2");
	netParameter->layer[13].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[13].top_size = 1;
	CHECK_EXPR_RET(strlen("conv3_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[13].top[0],"conv3_2");
	CHECK_EXPR_RET(strlen("conv3_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].name,"conv3_3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].type,"Convolution");
	netParameter->layer[14].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[14].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv3_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].bottom[0],"conv3_2");
	netParameter->layer[14].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[14].top_size = 1;
	CHECK_EXPR_RET(strlen("conv3_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].top[0],"conv3_3");
	netParameter->layer[14].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[14].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[14].param[i].lr_mult = 1.0;//default value
		netParameter->layer[14].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[14].param[0].lr_mult = 1;
	netParameter->layer[14].param[0].decay_mult = 1;
	netParameter->layer[14].param[1].lr_mult = 2;
	netParameter->layer[14].param[1].decay_mult = 0;

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

	//Give default values begin:
	strcpy(netParameter->layer[14].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[14].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[14].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[14].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[14].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[14].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[14].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[14].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[14].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[14].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[14].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[14].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[14].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[14].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[14].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[14].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[14].convolution_param.bias_filler.type,"constant");
	netParameter->layer[14].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu3_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].name,"relu3_3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].type,"ReLU");
	netParameter->layer[15].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[15].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv3_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].bottom[0],"conv3_3");
	netParameter->layer[15].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[15].top_size = 1;
	CHECK_EXPR_RET(strlen("conv3_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[15].top[0],"conv3_3");
	CHECK_EXPR_RET(strlen("pool3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[16].name,"pool3");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[16].type,"Pooling");
	netParameter->layer[16].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[16].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv3_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[16].bottom[0],"conv3_3");
	netParameter->layer[16].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[16].top_size = 1;
	CHECK_EXPR_RET(strlen("pool3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[16].top[0],"pool3");

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
	CHECK_EXPR_RET(strlen("conv4_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].name,"conv4_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].type,"Convolution");
	netParameter->layer[17].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[17].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].bottom[0],"pool3");
	netParameter->layer[17].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[17].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[17].top[0],"conv4_1");
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

	netParameter->layer[17].convolution_param.num_output = 512;
	netParameter->layer[17].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[17].convolution_param.pad_size = 1;
	netParameter->layer[17].convolution_param.pad[0] = 1;
	netParameter->layer[17].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[17].convolution_param.kernel_size_size = 1;
	netParameter->layer[17].convolution_param.kernel_size[0] = 3;

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
	netParameter->layer[17].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu4_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[18].name,"relu4_1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[18].type,"ReLU");
	netParameter->layer[18].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[18].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[18].bottom[0],"conv4_1");
	netParameter->layer[18].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[18].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[18].top[0],"conv4_1");
	CHECK_EXPR_RET(strlen("conv4_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].name,"conv4_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].type,"Convolution");
	netParameter->layer[19].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[19].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].bottom[0],"conv4_1");
	netParameter->layer[19].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[19].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[19].top[0],"conv4_2");
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

	netParameter->layer[19].convolution_param.num_output = 512;
	netParameter->layer[19].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[19].convolution_param.pad_size = 1;
	netParameter->layer[19].convolution_param.pad[0] = 1;
	netParameter->layer[19].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[19].convolution_param.kernel_size_size = 1;
	netParameter->layer[19].convolution_param.kernel_size[0] = 3;

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
	netParameter->layer[19].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu4_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[20].name,"relu4_2");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[20].type,"ReLU");
	netParameter->layer[20].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[20].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[20].bottom[0],"conv4_2");
	netParameter->layer[20].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[20].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[20].top[0],"conv4_2");
	CHECK_EXPR_RET(strlen("conv4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].name,"conv4_3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].type,"Convolution");
	netParameter->layer[21].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[21].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].bottom[0],"conv4_2");
	netParameter->layer[21].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[21].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].top[0],"conv4_3");
	netParameter->layer[21].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[21].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[21].param[i].lr_mult = 1.0;//default value
		netParameter->layer[21].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[21].param[0].lr_mult = 1;
	netParameter->layer[21].param[0].decay_mult = 1;
	netParameter->layer[21].param[1].lr_mult = 2;
	netParameter->layer[21].param[1].decay_mult = 0;

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

	//Give default values begin:
	strcpy(netParameter->layer[21].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[21].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[21].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[21].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[21].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[21].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[21].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[21].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[21].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[21].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[21].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[21].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[21].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[21].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[21].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[21].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[21].convolution_param.bias_filler.type,"constant");
	netParameter->layer[21].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].name,"relu4_3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].type,"ReLU");
	netParameter->layer[22].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[22].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].bottom[0],"conv4_3");
	netParameter->layer[22].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[22].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[22].top[0],"conv4_3");
	CHECK_EXPR_RET(strlen("pool4") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[23].name,"pool4");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[23].type,"Pooling");
	netParameter->layer[23].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[23].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[23].bottom[0],"conv4_3");
	netParameter->layer[23].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[23].top_size = 1;
	CHECK_EXPR_RET(strlen("pool4") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[23].top[0],"pool4");

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
	CHECK_EXPR_RET(strlen("conv5_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].name,"conv5_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].type,"Convolution");
	netParameter->layer[24].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[24].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool4") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].bottom[0],"pool4");
	netParameter->layer[24].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[24].top_size = 1;
	CHECK_EXPR_RET(strlen("conv5_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].top[0],"conv5_1");
	netParameter->layer[24].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[24].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[24].param[i].lr_mult = 1.0;//default value
		netParameter->layer[24].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[24].param[0].lr_mult = 1;
	netParameter->layer[24].param[0].decay_mult = 1;
	netParameter->layer[24].param[1].lr_mult = 2;
	netParameter->layer[24].param[1].decay_mult = 0;

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

	//Give default values begin:
	strcpy(netParameter->layer[24].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[24].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[24].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[24].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[24].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[24].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[24].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[24].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[24].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[24].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[24].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[24].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[24].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[24].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[24].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[24].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[24].convolution_param.bias_filler.type,"constant");
	netParameter->layer[24].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu5_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].name,"relu5_1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].type,"ReLU");
	netParameter->layer[25].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[25].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv5_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].bottom[0],"conv5_1");
	netParameter->layer[25].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[25].top_size = 1;
	CHECK_EXPR_RET(strlen("conv5_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[25].top[0],"conv5_1");
	CHECK_EXPR_RET(strlen("conv5_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].name,"conv5_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].type,"Convolution");
	netParameter->layer[26].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[26].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv5_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].bottom[0],"conv5_1");
	netParameter->layer[26].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[26].top_size = 1;
	CHECK_EXPR_RET(strlen("conv5_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].top[0],"conv5_2");
	netParameter->layer[26].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[26].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[26].param[i].lr_mult = 1.0;//default value
		netParameter->layer[26].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[26].param[0].lr_mult = 1;
	netParameter->layer[26].param[0].decay_mult = 1;
	netParameter->layer[26].param[1].lr_mult = 2;
	netParameter->layer[26].param[1].decay_mult = 0;

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

	//Give default values begin:
	strcpy(netParameter->layer[26].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[26].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[26].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[26].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[26].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[26].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[26].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[26].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[26].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[26].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[26].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[26].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[26].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[26].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[26].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[26].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[26].convolution_param.bias_filler.type,"constant");
	netParameter->layer[26].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu5_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].name,"relu5_2");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].type,"ReLU");
	netParameter->layer[27].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[27].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv5_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].bottom[0],"conv5_2");
	netParameter->layer[27].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[27].top_size = 1;
	CHECK_EXPR_RET(strlen("conv5_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[27].top[0],"conv5_2");
	CHECK_EXPR_RET(strlen("conv5_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].name,"conv5_3");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].type,"Convolution");
	netParameter->layer[28].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[28].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv5_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].bottom[0],"conv5_2");
	netParameter->layer[28].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[28].top_size = 1;
	CHECK_EXPR_RET(strlen("conv5_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].top[0],"conv5_3");
	netParameter->layer[28].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[28].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[28].param[i].lr_mult = 1.0;//default value
		netParameter->layer[28].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[28].param[0].lr_mult = 1;
	netParameter->layer[28].param[0].decay_mult = 1;
	netParameter->layer[28].param[1].lr_mult = 2;
	netParameter->layer[28].param[1].decay_mult = 0;

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

	//Give default values begin:
	strcpy(netParameter->layer[28].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[28].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[28].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[28].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[28].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[28].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[28].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[28].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[28].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[28].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[28].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[28].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[28].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[28].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[28].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[28].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[28].convolution_param.bias_filler.type,"constant");
	netParameter->layer[28].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu5_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].name,"relu5_3");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].type,"ReLU");
	netParameter->layer[29].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[29].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv5_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].bottom[0],"conv5_3");
	netParameter->layer[29].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[29].top_size = 1;
	CHECK_EXPR_RET(strlen("conv5_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[29].top[0],"conv5_3");
	CHECK_EXPR_RET(strlen("pool5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[30].name,"pool5");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[30].type,"Pooling");
	netParameter->layer[30].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[30].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv5_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[30].bottom[0],"conv5_3");
	netParameter->layer[30].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[30].top_size = 1;
	CHECK_EXPR_RET(strlen("pool5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[30].top[0],"pool5");

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
	netParameter->layer[30].pooling_param.kernel_size = 3;
	netParameter->layer[30].pooling_param.stride = 1;
	netParameter->layer[30].pooling_param.pad = 1;
	CHECK_EXPR_RET(strlen("fc6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].name,"fc6");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].type,"Convolution");
	netParameter->layer[31].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[31].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool5") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].bottom[0],"pool5");
	netParameter->layer[31].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[31].top_size = 1;
	CHECK_EXPR_RET(strlen("fc6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[31].top[0],"fc6");
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

	netParameter->layer[31].convolution_param.num_output = 1024;
	netParameter->layer[31].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[31].convolution_param.pad_size = 1;
	netParameter->layer[31].convolution_param.pad[0] = 6;
	netParameter->layer[31].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[31].convolution_param.kernel_size_size = 1;
	netParameter->layer[31].convolution_param.kernel_size[0] = 3;

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
	netParameter->layer[31].convolution_param.bias_filler.value = 0;
	netParameter->layer[31].convolution_param.dilation = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[31].convolution_param.dilation_size = 1;
	netParameter->layer[31].convolution_param.dilation[0] = 6;
	CHECK_EXPR_RET(strlen("relu6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[32].name,"relu6");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[32].type,"ReLU");
	netParameter->layer[32].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[32].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[32].bottom[0],"fc6");
	netParameter->layer[32].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[32].top_size = 1;
	CHECK_EXPR_RET(strlen("fc6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[32].top[0],"fc6");
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].name,"fc7");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].type,"Convolution");
	netParameter->layer[33].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[33].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].bottom[0],"fc6");
	netParameter->layer[33].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[33].top_size = 1;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[33].top[0],"fc7");
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

	netParameter->layer[33].convolution_param.num_output = 1024;
	netParameter->layer[33].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[33].convolution_param.kernel_size_size = 1;
	netParameter->layer[33].convolution_param.kernel_size[0] = 1;

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
	netParameter->layer[33].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("relu7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[34].name,"relu7");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[34].type,"ReLU");
	netParameter->layer[34].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[34].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[34].bottom[0],"fc7");
	netParameter->layer[34].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[34].top_size = 1;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[34].top[0],"fc7");
	CHECK_EXPR_RET(strlen("conv6_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].name,"conv6_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].type,"Convolution");
	netParameter->layer[35].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[35].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].bottom[0],"fc7");
	netParameter->layer[35].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[35].top_size = 1;
	CHECK_EXPR_RET(strlen("conv6_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].top[0],"conv6_1");
	netParameter->layer[35].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[35].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[35].param[i].lr_mult = 1.0;//default value
		netParameter->layer[35].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[35].param[0].lr_mult = 1;
	netParameter->layer[35].param[0].decay_mult = 1;
	netParameter->layer[35].param[1].lr_mult = 2;
	netParameter->layer[35].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[35].convolution_param.bias_term = true;//default value
	netParameter->layer[35].convolution_param.pad_h = 0;//default value
	netParameter->layer[35].convolution_param.pad_w = 0;//default value
	netParameter->layer[35].convolution_param.group = 1;//default value
	netParameter->layer[35].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[35].convolution_param.axis = 1;//default value
	netParameter->layer[35].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[35].convolution_param.num_output = 256;
	netParameter->layer[35].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[35].convolution_param.pad_size = 1;
	netParameter->layer[35].convolution_param.pad[0] = 0;
	netParameter->layer[35].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[35].convolution_param.kernel_size_size = 1;
	netParameter->layer[35].convolution_param.kernel_size[0] = 1;
	netParameter->layer[35].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[35].convolution_param.stride_size = 1;
	netParameter->layer[35].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[35].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[35].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[35].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[35].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[35].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[35].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[35].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[35].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[35].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[35].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[35].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[35].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[35].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[35].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[35].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[35].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[35].convolution_param.bias_filler.type,"constant");
	netParameter->layer[35].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv6_1_relu") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].name,"conv6_1_relu");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].type,"ReLU");
	netParameter->layer[36].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[36].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv6_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].bottom[0],"conv6_1");
	netParameter->layer[36].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[36].top_size = 1;
	CHECK_EXPR_RET(strlen("conv6_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[36].top[0],"conv6_1");
	CHECK_EXPR_RET(strlen("conv6_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].name,"conv6_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].type,"Convolution");
	netParameter->layer[37].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[37].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv6_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].bottom[0],"conv6_1");
	netParameter->layer[37].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[37].top_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].top[0],"conv6_2");
	netParameter->layer[37].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[37].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[37].param[i].lr_mult = 1.0;//default value
		netParameter->layer[37].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[37].param[0].lr_mult = 1;
	netParameter->layer[37].param[0].decay_mult = 1;
	netParameter->layer[37].param[1].lr_mult = 2;
	netParameter->layer[37].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[37].convolution_param.bias_term = true;//default value
	netParameter->layer[37].convolution_param.pad_h = 0;//default value
	netParameter->layer[37].convolution_param.pad_w = 0;//default value
	netParameter->layer[37].convolution_param.group = 1;//default value
	netParameter->layer[37].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[37].convolution_param.axis = 1;//default value
	netParameter->layer[37].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[37].convolution_param.num_output = 512;
	netParameter->layer[37].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[37].convolution_param.pad_size = 1;
	netParameter->layer[37].convolution_param.pad[0] = 1;
	netParameter->layer[37].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[37].convolution_param.kernel_size_size = 1;
	netParameter->layer[37].convolution_param.kernel_size[0] = 3;
	netParameter->layer[37].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[37].convolution_param.stride_size = 1;
	netParameter->layer[37].convolution_param.stride[0] = 2;

	//Give default values begin:
	strcpy(netParameter->layer[37].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[37].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[37].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[37].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[37].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[37].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[37].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[37].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[37].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[37].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[37].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[37].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[37].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[37].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[37].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[37].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[37].convolution_param.bias_filler.type,"constant");
	netParameter->layer[37].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv6_2_relu") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].name,"conv6_2_relu");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].type,"ReLU");
	netParameter->layer[38].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[38].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].bottom[0],"conv6_2");
	netParameter->layer[38].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[38].top_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[38].top[0],"conv6_2");
	CHECK_EXPR_RET(strlen("conv7_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[39].name,"conv7_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[39].type,"Convolution");
	netParameter->layer[39].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[39].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[39].bottom[0],"conv6_2");
	netParameter->layer[39].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[39].top_size = 1;
	CHECK_EXPR_RET(strlen("conv7_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[39].top[0],"conv7_1");
	netParameter->layer[39].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[39].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[39].param[i].lr_mult = 1.0;//default value
		netParameter->layer[39].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[39].param[0].lr_mult = 1;
	netParameter->layer[39].param[0].decay_mult = 1;
	netParameter->layer[39].param[1].lr_mult = 2;
	netParameter->layer[39].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[39].convolution_param.bias_term = true;//default value
	netParameter->layer[39].convolution_param.pad_h = 0;//default value
	netParameter->layer[39].convolution_param.pad_w = 0;//default value
	netParameter->layer[39].convolution_param.group = 1;//default value
	netParameter->layer[39].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[39].convolution_param.axis = 1;//default value
	netParameter->layer[39].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[39].convolution_param.num_output = 128;
	netParameter->layer[39].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[39].convolution_param.pad_size = 1;
	netParameter->layer[39].convolution_param.pad[0] = 0;
	netParameter->layer[39].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[39].convolution_param.kernel_size_size = 1;
	netParameter->layer[39].convolution_param.kernel_size[0] = 1;
	netParameter->layer[39].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[39].convolution_param.stride_size = 1;
	netParameter->layer[39].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[39].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[39].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[39].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[39].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[39].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[39].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[39].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[39].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[39].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[39].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[39].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[39].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[39].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[39].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[39].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[39].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[39].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[39].convolution_param.bias_filler.type,"constant");
	netParameter->layer[39].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv7_1_relu") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[40].name,"conv7_1_relu");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[40].type,"ReLU");
	netParameter->layer[40].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[40].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv7_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[40].bottom[0],"conv7_1");
	netParameter->layer[40].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[40].top_size = 1;
	CHECK_EXPR_RET(strlen("conv7_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[40].top[0],"conv7_1");
	CHECK_EXPR_RET(strlen("conv7_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[41].name,"conv7_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[41].type,"Convolution");
	netParameter->layer[41].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[41].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv7_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[41].bottom[0],"conv7_1");
	netParameter->layer[41].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[41].top_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[41].top[0],"conv7_2");
	netParameter->layer[41].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[41].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[41].param[i].lr_mult = 1.0;//default value
		netParameter->layer[41].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[41].param[0].lr_mult = 1;
	netParameter->layer[41].param[0].decay_mult = 1;
	netParameter->layer[41].param[1].lr_mult = 2;
	netParameter->layer[41].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[41].convolution_param.bias_term = true;//default value
	netParameter->layer[41].convolution_param.pad_h = 0;//default value
	netParameter->layer[41].convolution_param.pad_w = 0;//default value
	netParameter->layer[41].convolution_param.group = 1;//default value
	netParameter->layer[41].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[41].convolution_param.axis = 1;//default value
	netParameter->layer[41].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[41].convolution_param.num_output = 256;
	netParameter->layer[41].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[41].convolution_param.pad_size = 1;
	netParameter->layer[41].convolution_param.pad[0] = 1;
	netParameter->layer[41].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[41].convolution_param.kernel_size_size = 1;
	netParameter->layer[41].convolution_param.kernel_size[0] = 3;
	netParameter->layer[41].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[41].convolution_param.stride_size = 1;
	netParameter->layer[41].convolution_param.stride[0] = 2;

	//Give default values begin:
	strcpy(netParameter->layer[41].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[41].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[41].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[41].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[41].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[41].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[41].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[41].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[41].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[41].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[41].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[41].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[41].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[41].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[41].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[41].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[41].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[41].convolution_param.bias_filler.type,"constant");
	netParameter->layer[41].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv7_2_relu") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[42].name,"conv7_2_relu");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[42].type,"ReLU");
	netParameter->layer[42].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[42].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[42].bottom[0],"conv7_2");
	netParameter->layer[42].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[42].top_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[42].top[0],"conv7_2");
	CHECK_EXPR_RET(strlen("conv8_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[43].name,"conv8_1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[43].type,"Convolution");
	netParameter->layer[43].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[43].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[43].bottom[0],"conv7_2");
	netParameter->layer[43].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[43].top_size = 1;
	CHECK_EXPR_RET(strlen("conv8_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[43].top[0],"conv8_1");
	netParameter->layer[43].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[43].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[43].param[i].lr_mult = 1.0;//default value
		netParameter->layer[43].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[43].param[0].lr_mult = 1;
	netParameter->layer[43].param[0].decay_mult = 1;
	netParameter->layer[43].param[1].lr_mult = 2;
	netParameter->layer[43].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[43].convolution_param.bias_term = true;//default value
	netParameter->layer[43].convolution_param.pad_h = 0;//default value
	netParameter->layer[43].convolution_param.pad_w = 0;//default value
	netParameter->layer[43].convolution_param.group = 1;//default value
	netParameter->layer[43].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[43].convolution_param.axis = 1;//default value
	netParameter->layer[43].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[43].convolution_param.num_output = 128;
	netParameter->layer[43].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[43].convolution_param.pad_size = 1;
	netParameter->layer[43].convolution_param.pad[0] = 0;
	netParameter->layer[43].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[43].convolution_param.kernel_size_size = 1;
	netParameter->layer[43].convolution_param.kernel_size[0] = 1;
	netParameter->layer[43].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[43].convolution_param.stride_size = 1;
	netParameter->layer[43].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[43].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[43].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[43].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[43].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[43].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[43].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[43].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[43].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[43].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[43].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[43].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[43].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[43].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[43].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[43].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[43].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[43].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[43].convolution_param.bias_filler.type,"constant");
	netParameter->layer[43].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv8_1_relu") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[44].name,"conv8_1_relu");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[44].type,"ReLU");
	netParameter->layer[44].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[44].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv8_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[44].bottom[0],"conv8_1");
	netParameter->layer[44].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[44].top_size = 1;
	CHECK_EXPR_RET(strlen("conv8_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[44].top[0],"conv8_1");
	CHECK_EXPR_RET(strlen("conv8_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[45].name,"conv8_2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[45].type,"Convolution");
	netParameter->layer[45].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[45].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv8_1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[45].bottom[0],"conv8_1");
	netParameter->layer[45].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[45].top_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[45].top[0],"conv8_2");
	netParameter->layer[45].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[45].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[45].param[i].lr_mult = 1.0;//default value
		netParameter->layer[45].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[45].param[0].lr_mult = 1;
	netParameter->layer[45].param[0].decay_mult = 1;
	netParameter->layer[45].param[1].lr_mult = 2;
	netParameter->layer[45].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[45].convolution_param.bias_term = true;//default value
	netParameter->layer[45].convolution_param.pad_h = 0;//default value
	netParameter->layer[45].convolution_param.pad_w = 0;//default value
	netParameter->layer[45].convolution_param.group = 1;//default value
	netParameter->layer[45].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[45].convolution_param.axis = 1;//default value
	netParameter->layer[45].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[45].convolution_param.num_output = 256;
	netParameter->layer[45].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[45].convolution_param.pad_size = 1;
	netParameter->layer[45].convolution_param.pad[0] = 1;
	netParameter->layer[45].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[45].convolution_param.kernel_size_size = 1;
	netParameter->layer[45].convolution_param.kernel_size[0] = 3;
	netParameter->layer[45].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[45].convolution_param.stride_size = 1;
	netParameter->layer[45].convolution_param.stride[0] = 2;

	//Give default values begin:
	strcpy(netParameter->layer[45].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[45].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[45].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[45].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[45].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[45].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[45].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[45].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[45].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[45].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[45].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[45].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[45].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[45].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[45].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[45].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[45].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[45].convolution_param.bias_filler.type,"constant");
	netParameter->layer[45].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv8_2_relu") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[46].name,"conv8_2_relu");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[46].type,"ReLU");
	netParameter->layer[46].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[46].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[46].bottom[0],"conv8_2");
	netParameter->layer[46].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[46].top_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[46].top[0],"conv8_2");
	CHECK_EXPR_RET(strlen("pool6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[47].name,"pool6");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[47].type,"Pooling");
	netParameter->layer[47].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[47].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[47].bottom[0],"conv8_2");
	netParameter->layer[47].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[47].top_size = 1;
	CHECK_EXPR_RET(strlen("pool6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[47].top[0],"pool6");

	//Give default values begin:
	netParameter->layer[47].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[47].pooling_param.pad = 0;//default value
	netParameter->layer[47].pooling_param.pad_h = 0;//default value
	netParameter->layer[47].pooling_param.pad_w = 0;//default value
	netParameter->layer[47].pooling_param.stride = 1;//default value
	netParameter->layer[47].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[47].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[47].pooling_param.pool = PoolingParameter_PoolMethod_AVE;
	netParameter->layer[47].pooling_param.global_pooling = true;
	CHECK_EXPR_RET(strlen("conv4_3_norm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[48].name,"conv4_3_norm");
	CHECK_EXPR_RET(strlen("Normalize") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[48].type,"Normalize");
	netParameter->layer[48].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[48].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[48].bottom[0],"conv4_3");
	netParameter->layer[48].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[48].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[48].top[0],"conv4_3_norm");

	//Give default values begin:
	netParameter->layer[48].norm_param.across_spatial = true;//default value
	netParameter->layer[48].norm_param.channel_shared = true;//default value
	netParameter->layer[48].norm_param.eps = 1e-10;//default value
	//Give default values end

	netParameter->layer[48].norm_param.across_spatial = false;

	//Give default values begin:
	strcpy(netParameter->layer[48].norm_param.scale_filler.type,"constant");//default value
	netParameter->layer[48].norm_param.scale_filler.value = 0;//default value
	netParameter->layer[48].norm_param.scale_filler.min = 0;//default value
	netParameter->layer[48].norm_param.scale_filler.max = 1;//default value
	netParameter->layer[48].norm_param.scale_filler.mean = 0;//default value
	netParameter->layer[48].norm_param.scale_filler.std = 1;//default value
	netParameter->layer[48].norm_param.scale_filler.sparse = -1;//default value
	netParameter->layer[48].norm_param.scale_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[48].norm_param.scale_filler.type,"constant");
	netParameter->layer[48].norm_param.scale_filler.value = 20;
	netParameter->layer[48].norm_param.channel_shared = false;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[49].name,"conv4_3_norm_mbox_loc");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[49].type,"Convolution");
	netParameter->layer[49].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[49].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[49].bottom[0],"conv4_3_norm");
	netParameter->layer[49].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[49].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[49].top[0],"conv4_3_norm_mbox_loc");
	netParameter->layer[49].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[49].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[49].param[i].lr_mult = 1.0;//default value
		netParameter->layer[49].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[49].param[0].lr_mult = 1;
	netParameter->layer[49].param[0].decay_mult = 1;
	netParameter->layer[49].param[1].lr_mult = 2;
	netParameter->layer[49].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[49].convolution_param.bias_term = true;//default value
	netParameter->layer[49].convolution_param.pad_h = 0;//default value
	netParameter->layer[49].convolution_param.pad_w = 0;//default value
	netParameter->layer[49].convolution_param.group = 1;//default value
	netParameter->layer[49].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[49].convolution_param.axis = 1;//default value
	netParameter->layer[49].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[49].convolution_param.num_output = 12;
	netParameter->layer[49].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[49].convolution_param.pad_size = 1;
	netParameter->layer[49].convolution_param.pad[0] = 1;
	netParameter->layer[49].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[49].convolution_param.kernel_size_size = 1;
	netParameter->layer[49].convolution_param.kernel_size[0] = 3;
	netParameter->layer[49].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[49].convolution_param.stride_size = 1;
	netParameter->layer[49].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[49].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[49].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[49].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[49].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[49].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[49].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[49].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[49].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[49].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[49].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[49].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[49].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[49].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[49].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[49].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[49].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[49].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[49].convolution_param.bias_filler.type,"constant");
	netParameter->layer[49].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[50].name,"conv4_3_norm_mbox_loc_perm");
	CHECK_EXPR_RET(strlen("Permute") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[50].type,"Permute");
	netParameter->layer[50].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[50].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[50].bottom[0],"conv4_3_norm_mbox_loc");
	netParameter->layer[50].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[50].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[50].top[0],"conv4_3_norm_mbox_loc_perm");
	netParameter->layer[50].permute_param.order = (UINT32 *)malloc(sizeof(UINT32)*4);
	netParameter->layer[50].permute_param.order_size = 4;
	netParameter->layer[50].permute_param.order[0] = 0;
	netParameter->layer[50].permute_param.order[1] = 2;
	netParameter->layer[50].permute_param.order[2] = 3;
	netParameter->layer[50].permute_param.order[3] = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[51].name,"conv4_3_norm_mbox_loc_flat");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[51].type,"Flatten");
	netParameter->layer[51].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[51].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[51].bottom[0],"conv4_3_norm_mbox_loc_perm");
	netParameter->layer[51].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[51].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[51].top[0],"conv4_3_norm_mbox_loc_flat");

	//Give default values begin:
	netParameter->layer[51].flatten_param.axis = 1;//default value
	netParameter->layer[51].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[51].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[52].name,"conv4_3_norm_mbox_conf");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[52].type,"Convolution");
	netParameter->layer[52].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[52].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[52].bottom[0],"conv4_3_norm");
	netParameter->layer[52].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[52].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[52].top[0],"conv4_3_norm_mbox_conf");
	netParameter->layer[52].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[52].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[52].param[i].lr_mult = 1.0;//default value
		netParameter->layer[52].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[52].param[0].lr_mult = 1;
	netParameter->layer[52].param[0].decay_mult = 1;
	netParameter->layer[52].param[1].lr_mult = 2;
	netParameter->layer[52].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[52].convolution_param.bias_term = true;//default value
	netParameter->layer[52].convolution_param.pad_h = 0;//default value
	netParameter->layer[52].convolution_param.pad_w = 0;//default value
	netParameter->layer[52].convolution_param.group = 1;//default value
	netParameter->layer[52].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[52].convolution_param.axis = 1;//default value
	netParameter->layer[52].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[52].convolution_param.num_output = 63;
	netParameter->layer[52].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[52].convolution_param.pad_size = 1;
	netParameter->layer[52].convolution_param.pad[0] = 1;
	netParameter->layer[52].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[52].convolution_param.kernel_size_size = 1;
	netParameter->layer[52].convolution_param.kernel_size[0] = 3;
	netParameter->layer[52].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[52].convolution_param.stride_size = 1;
	netParameter->layer[52].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[52].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[52].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[52].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[52].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[52].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[52].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[52].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[52].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[52].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[52].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[52].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[52].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[52].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[52].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[52].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[52].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[52].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[52].convolution_param.bias_filler.type,"constant");
	netParameter->layer[52].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[53].name,"conv4_3_norm_mbox_conf_perm");
	CHECK_EXPR_RET(strlen("Permute") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[53].type,"Permute");
	netParameter->layer[53].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[53].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[53].bottom[0],"conv4_3_norm_mbox_conf");
	netParameter->layer[53].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[53].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[53].top[0],"conv4_3_norm_mbox_conf_perm");
	netParameter->layer[53].permute_param.order = (UINT32 *)malloc(sizeof(UINT32)*4);
	netParameter->layer[53].permute_param.order_size = 4;
	netParameter->layer[53].permute_param.order[0] = 0;
	netParameter->layer[53].permute_param.order[1] = 2;
	netParameter->layer[53].permute_param.order[2] = 3;
	netParameter->layer[53].permute_param.order[3] = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[54].name,"conv4_3_norm_mbox_conf_flat");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[54].type,"Flatten");
	netParameter->layer[54].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[54].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[54].bottom[0],"conv4_3_norm_mbox_conf_perm");
	netParameter->layer[54].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[54].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[54].top[0],"conv4_3_norm_mbox_conf_flat");

	//Give default values begin:
	netParameter->layer[54].flatten_param.axis = 1;//default value
	netParameter->layer[54].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[54].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[55].name,"conv4_3_norm_mbox_priorbox");
	CHECK_EXPR_RET(strlen("PriorBox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[55].type,"PriorBox");
	netParameter->layer[55].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*2);
	netParameter->layer[55].bottom_size = 2;
	CHECK_EXPR_RET(strlen("conv4_3_norm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[55].bottom[0],"conv4_3_norm");
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[55].bottom[1],"data");
	netParameter->layer[55].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[55].top_size = 1;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[55].top[0],"conv4_3_norm_mbox_priorbox");

	//Give default values begin:
	netParameter->layer[55].prior_box_param.flip = true;//default value
	netParameter->layer[55].prior_box_param.clip = true;//default value
	//Give default values end

	netParameter->layer[55].prior_box_param.min_size = 30.0;
	netParameter->layer[55].prior_box_param.aspect_ratio = (float *)malloc(sizeof(float)*1);
	netParameter->layer[55].prior_box_param.aspect_ratio_size = 1;
	netParameter->layer[55].prior_box_param.aspect_ratio[0] = 2;
	netParameter->layer[55].prior_box_param.flip = true;
	netParameter->layer[55].prior_box_param.clip = true;
	netParameter->layer[55].prior_box_param.variance = (float *)malloc(sizeof(float)*4);
	netParameter->layer[55].prior_box_param.variance_size = 4;
	netParameter->layer[55].prior_box_param.variance[0] = 0.1;
	netParameter->layer[55].prior_box_param.variance[1] = 0.1;
	netParameter->layer[55].prior_box_param.variance[2] = 0.2;
	netParameter->layer[55].prior_box_param.variance[3] = 0.2;
	CHECK_EXPR_RET(strlen("fc7_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[56].name,"fc7_mbox_loc");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[56].type,"Convolution");
	netParameter->layer[56].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[56].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[56].bottom[0],"fc7");
	netParameter->layer[56].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[56].top_size = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[56].top[0],"fc7_mbox_loc");
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

	netParameter->layer[56].convolution_param.num_output = 24;
	netParameter->layer[56].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[56].convolution_param.pad_size = 1;
	netParameter->layer[56].convolution_param.pad[0] = 1;
	netParameter->layer[56].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[56].convolution_param.kernel_size_size = 1;
	netParameter->layer[56].convolution_param.kernel_size[0] = 3;
	netParameter->layer[56].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[56].convolution_param.stride_size = 1;
	netParameter->layer[56].convolution_param.stride[0] = 1;

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
	netParameter->layer[56].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("fc7_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[57].name,"fc7_mbox_loc_perm");
	CHECK_EXPR_RET(strlen("Permute") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[57].type,"Permute");
	netParameter->layer[57].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[57].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[57].bottom[0],"fc7_mbox_loc");
	netParameter->layer[57].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[57].top_size = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[57].top[0],"fc7_mbox_loc_perm");
	netParameter->layer[57].permute_param.order = (UINT32 *)malloc(sizeof(UINT32)*4);
	netParameter->layer[57].permute_param.order_size = 4;
	netParameter->layer[57].permute_param.order[0] = 0;
	netParameter->layer[57].permute_param.order[1] = 2;
	netParameter->layer[57].permute_param.order[2] = 3;
	netParameter->layer[57].permute_param.order[3] = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[58].name,"fc7_mbox_loc_flat");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[58].type,"Flatten");
	netParameter->layer[58].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[58].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[58].bottom[0],"fc7_mbox_loc_perm");
	netParameter->layer[58].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[58].top_size = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[58].top[0],"fc7_mbox_loc_flat");

	//Give default values begin:
	netParameter->layer[58].flatten_param.axis = 1;//default value
	netParameter->layer[58].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[58].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[59].name,"fc7_mbox_conf");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[59].type,"Convolution");
	netParameter->layer[59].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[59].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[59].bottom[0],"fc7");
	netParameter->layer[59].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[59].top_size = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[59].top[0],"fc7_mbox_conf");
	netParameter->layer[59].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[59].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[59].param[i].lr_mult = 1.0;//default value
		netParameter->layer[59].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[59].param[0].lr_mult = 1;
	netParameter->layer[59].param[0].decay_mult = 1;
	netParameter->layer[59].param[1].lr_mult = 2;
	netParameter->layer[59].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[59].convolution_param.bias_term = true;//default value
	netParameter->layer[59].convolution_param.pad_h = 0;//default value
	netParameter->layer[59].convolution_param.pad_w = 0;//default value
	netParameter->layer[59].convolution_param.group = 1;//default value
	netParameter->layer[59].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[59].convolution_param.axis = 1;//default value
	netParameter->layer[59].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[59].convolution_param.num_output = 126;
	netParameter->layer[59].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[59].convolution_param.pad_size = 1;
	netParameter->layer[59].convolution_param.pad[0] = 1;
	netParameter->layer[59].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[59].convolution_param.kernel_size_size = 1;
	netParameter->layer[59].convolution_param.kernel_size[0] = 3;
	netParameter->layer[59].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[59].convolution_param.stride_size = 1;
	netParameter->layer[59].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[59].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[59].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[59].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[59].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[59].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[59].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[59].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[59].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[59].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[59].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[59].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[59].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[59].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[59].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[59].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[59].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[59].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[59].convolution_param.bias_filler.type,"constant");
	netParameter->layer[59].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("fc7_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[60].name,"fc7_mbox_conf_perm");
	CHECK_EXPR_RET(strlen("Permute") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[60].type,"Permute");
	netParameter->layer[60].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[60].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[60].bottom[0],"fc7_mbox_conf");
	netParameter->layer[60].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[60].top_size = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[60].top[0],"fc7_mbox_conf_perm");
	netParameter->layer[60].permute_param.order = (UINT32 *)malloc(sizeof(UINT32)*4);
	netParameter->layer[60].permute_param.order_size = 4;
	netParameter->layer[60].permute_param.order[0] = 0;
	netParameter->layer[60].permute_param.order[1] = 2;
	netParameter->layer[60].permute_param.order[2] = 3;
	netParameter->layer[60].permute_param.order[3] = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[61].name,"fc7_mbox_conf_flat");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[61].type,"Flatten");
	netParameter->layer[61].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[61].bottom_size = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[61].bottom[0],"fc7_mbox_conf_perm");
	netParameter->layer[61].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[61].top_size = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[61].top[0],"fc7_mbox_conf_flat");

	//Give default values begin:
	netParameter->layer[61].flatten_param.axis = 1;//default value
	netParameter->layer[61].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[61].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[62].name,"fc7_mbox_priorbox");
	CHECK_EXPR_RET(strlen("PriorBox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[62].type,"PriorBox");
	netParameter->layer[62].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*2);
	netParameter->layer[62].bottom_size = 2;
	CHECK_EXPR_RET(strlen("fc7") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[62].bottom[0],"fc7");
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[62].bottom[1],"data");
	netParameter->layer[62].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[62].top_size = 1;
	CHECK_EXPR_RET(strlen("fc7_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[62].top[0],"fc7_mbox_priorbox");

	//Give default values begin:
	netParameter->layer[62].prior_box_param.flip = true;//default value
	netParameter->layer[62].prior_box_param.clip = true;//default value
	//Give default values end

	netParameter->layer[62].prior_box_param.min_size = 60.0;
	netParameter->layer[62].prior_box_param.max_size = 114.0;
	netParameter->layer[62].prior_box_param.aspect_ratio = (float *)malloc(sizeof(float)*2);
	netParameter->layer[62].prior_box_param.aspect_ratio_size = 2;
	netParameter->layer[62].prior_box_param.aspect_ratio[0] = 2;
	netParameter->layer[62].prior_box_param.aspect_ratio[1] = 3;
	netParameter->layer[62].prior_box_param.flip = true;
	netParameter->layer[62].prior_box_param.clip = true;
	netParameter->layer[62].prior_box_param.variance = (float *)malloc(sizeof(float)*4);
	netParameter->layer[62].prior_box_param.variance_size = 4;
	netParameter->layer[62].prior_box_param.variance[0] = 0.1;
	netParameter->layer[62].prior_box_param.variance[1] = 0.1;
	netParameter->layer[62].prior_box_param.variance[2] = 0.2;
	netParameter->layer[62].prior_box_param.variance[3] = 0.2;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[63].name,"conv6_2_mbox_loc");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[63].type,"Convolution");
	netParameter->layer[63].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[63].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[63].bottom[0],"conv6_2");
	netParameter->layer[63].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[63].top_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[63].top[0],"conv6_2_mbox_loc");
	netParameter->layer[63].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[63].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[63].param[i].lr_mult = 1.0;//default value
		netParameter->layer[63].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[63].param[0].lr_mult = 1;
	netParameter->layer[63].param[0].decay_mult = 1;
	netParameter->layer[63].param[1].lr_mult = 2;
	netParameter->layer[63].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[63].convolution_param.bias_term = true;//default value
	netParameter->layer[63].convolution_param.pad_h = 0;//default value
	netParameter->layer[63].convolution_param.pad_w = 0;//default value
	netParameter->layer[63].convolution_param.group = 1;//default value
	netParameter->layer[63].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[63].convolution_param.axis = 1;//default value
	netParameter->layer[63].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[63].convolution_param.num_output = 24;
	netParameter->layer[63].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[63].convolution_param.pad_size = 1;
	netParameter->layer[63].convolution_param.pad[0] = 1;
	netParameter->layer[63].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[63].convolution_param.kernel_size_size = 1;
	netParameter->layer[63].convolution_param.kernel_size[0] = 3;
	netParameter->layer[63].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[63].convolution_param.stride_size = 1;
	netParameter->layer[63].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[63].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[63].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[63].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[63].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[63].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[63].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[63].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[63].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[63].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[63].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[63].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[63].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[63].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[63].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[63].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[63].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[63].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[63].convolution_param.bias_filler.type,"constant");
	netParameter->layer[63].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[64].name,"conv6_2_mbox_loc_perm");
	CHECK_EXPR_RET(strlen("Permute") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[64].type,"Permute");
	netParameter->layer[64].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[64].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[64].bottom[0],"conv6_2_mbox_loc");
	netParameter->layer[64].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[64].top_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[64].top[0],"conv6_2_mbox_loc_perm");
	netParameter->layer[64].permute_param.order = (UINT32 *)malloc(sizeof(UINT32)*4);
	netParameter->layer[64].permute_param.order_size = 4;
	netParameter->layer[64].permute_param.order[0] = 0;
	netParameter->layer[64].permute_param.order[1] = 2;
	netParameter->layer[64].permute_param.order[2] = 3;
	netParameter->layer[64].permute_param.order[3] = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[65].name,"conv6_2_mbox_loc_flat");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[65].type,"Flatten");
	netParameter->layer[65].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[65].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[65].bottom[0],"conv6_2_mbox_loc_perm");
	netParameter->layer[65].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[65].top_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[65].top[0],"conv6_2_mbox_loc_flat");

	//Give default values begin:
	netParameter->layer[65].flatten_param.axis = 1;//default value
	netParameter->layer[65].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[65].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[66].name,"conv6_2_mbox_conf");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[66].type,"Convolution");
	netParameter->layer[66].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[66].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[66].bottom[0],"conv6_2");
	netParameter->layer[66].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[66].top_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[66].top[0],"conv6_2_mbox_conf");
	netParameter->layer[66].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[66].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[66].param[i].lr_mult = 1.0;//default value
		netParameter->layer[66].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[66].param[0].lr_mult = 1;
	netParameter->layer[66].param[0].decay_mult = 1;
	netParameter->layer[66].param[1].lr_mult = 2;
	netParameter->layer[66].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[66].convolution_param.bias_term = true;//default value
	netParameter->layer[66].convolution_param.pad_h = 0;//default value
	netParameter->layer[66].convolution_param.pad_w = 0;//default value
	netParameter->layer[66].convolution_param.group = 1;//default value
	netParameter->layer[66].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[66].convolution_param.axis = 1;//default value
	netParameter->layer[66].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[66].convolution_param.num_output = 126;
	netParameter->layer[66].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[66].convolution_param.pad_size = 1;
	netParameter->layer[66].convolution_param.pad[0] = 1;
	netParameter->layer[66].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[66].convolution_param.kernel_size_size = 1;
	netParameter->layer[66].convolution_param.kernel_size[0] = 3;
	netParameter->layer[66].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[66].convolution_param.stride_size = 1;
	netParameter->layer[66].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[66].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[66].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[66].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[66].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[66].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[66].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[66].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[66].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[66].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[66].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[66].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[66].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[66].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[66].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[66].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[66].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[66].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[66].convolution_param.bias_filler.type,"constant");
	netParameter->layer[66].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[67].name,"conv6_2_mbox_conf_perm");
	CHECK_EXPR_RET(strlen("Permute") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[67].type,"Permute");
	netParameter->layer[67].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[67].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[67].bottom[0],"conv6_2_mbox_conf");
	netParameter->layer[67].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[67].top_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[67].top[0],"conv6_2_mbox_conf_perm");
	netParameter->layer[67].permute_param.order = (UINT32 *)malloc(sizeof(UINT32)*4);
	netParameter->layer[67].permute_param.order_size = 4;
	netParameter->layer[67].permute_param.order[0] = 0;
	netParameter->layer[67].permute_param.order[1] = 2;
	netParameter->layer[67].permute_param.order[2] = 3;
	netParameter->layer[67].permute_param.order[3] = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[68].name,"conv6_2_mbox_conf_flat");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[68].type,"Flatten");
	netParameter->layer[68].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[68].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[68].bottom[0],"conv6_2_mbox_conf_perm");
	netParameter->layer[68].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[68].top_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[68].top[0],"conv6_2_mbox_conf_flat");

	//Give default values begin:
	netParameter->layer[68].flatten_param.axis = 1;//default value
	netParameter->layer[68].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[68].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[69].name,"conv6_2_mbox_priorbox");
	CHECK_EXPR_RET(strlen("PriorBox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[69].type,"PriorBox");
	netParameter->layer[69].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*2);
	netParameter->layer[69].bottom_size = 2;
	CHECK_EXPR_RET(strlen("conv6_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[69].bottom[0],"conv6_2");
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[69].bottom[1],"data");
	netParameter->layer[69].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[69].top_size = 1;
	CHECK_EXPR_RET(strlen("conv6_2_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[69].top[0],"conv6_2_mbox_priorbox");

	//Give default values begin:
	netParameter->layer[69].prior_box_param.flip = true;//default value
	netParameter->layer[69].prior_box_param.clip = true;//default value
	//Give default values end

	netParameter->layer[69].prior_box_param.min_size = 114.0;
	netParameter->layer[69].prior_box_param.max_size = 168.0;
	netParameter->layer[69].prior_box_param.aspect_ratio = (float *)malloc(sizeof(float)*2);
	netParameter->layer[69].prior_box_param.aspect_ratio_size = 2;
	netParameter->layer[69].prior_box_param.aspect_ratio[0] = 2;
	netParameter->layer[69].prior_box_param.aspect_ratio[1] = 3;
	netParameter->layer[69].prior_box_param.flip = true;
	netParameter->layer[69].prior_box_param.clip = true;
	netParameter->layer[69].prior_box_param.variance = (float *)malloc(sizeof(float)*4);
	netParameter->layer[69].prior_box_param.variance_size = 4;
	netParameter->layer[69].prior_box_param.variance[0] = 0.1;
	netParameter->layer[69].prior_box_param.variance[1] = 0.1;
	netParameter->layer[69].prior_box_param.variance[2] = 0.2;
	netParameter->layer[69].prior_box_param.variance[3] = 0.2;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[70].name,"conv7_2_mbox_loc");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[70].type,"Convolution");
	netParameter->layer[70].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[70].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[70].bottom[0],"conv7_2");
	netParameter->layer[70].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[70].top_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[70].top[0],"conv7_2_mbox_loc");
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

	netParameter->layer[70].convolution_param.num_output = 24;
	netParameter->layer[70].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[70].convolution_param.pad_size = 1;
	netParameter->layer[70].convolution_param.pad[0] = 1;
	netParameter->layer[70].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[70].convolution_param.kernel_size_size = 1;
	netParameter->layer[70].convolution_param.kernel_size[0] = 3;
	netParameter->layer[70].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[70].convolution_param.stride_size = 1;
	netParameter->layer[70].convolution_param.stride[0] = 1;

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
	netParameter->layer[70].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[71].name,"conv7_2_mbox_loc_perm");
	CHECK_EXPR_RET(strlen("Permute") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[71].type,"Permute");
	netParameter->layer[71].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[71].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[71].bottom[0],"conv7_2_mbox_loc");
	netParameter->layer[71].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[71].top_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[71].top[0],"conv7_2_mbox_loc_perm");
	netParameter->layer[71].permute_param.order = (UINT32 *)malloc(sizeof(UINT32)*4);
	netParameter->layer[71].permute_param.order_size = 4;
	netParameter->layer[71].permute_param.order[0] = 0;
	netParameter->layer[71].permute_param.order[1] = 2;
	netParameter->layer[71].permute_param.order[2] = 3;
	netParameter->layer[71].permute_param.order[3] = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[72].name,"conv7_2_mbox_loc_flat");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[72].type,"Flatten");
	netParameter->layer[72].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[72].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[72].bottom[0],"conv7_2_mbox_loc_perm");
	netParameter->layer[72].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[72].top_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[72].top[0],"conv7_2_mbox_loc_flat");

	//Give default values begin:
	netParameter->layer[72].flatten_param.axis = 1;//default value
	netParameter->layer[72].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[72].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[73].name,"conv7_2_mbox_conf");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[73].type,"Convolution");
	netParameter->layer[73].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[73].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[73].bottom[0],"conv7_2");
	netParameter->layer[73].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[73].top_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[73].top[0],"conv7_2_mbox_conf");
	netParameter->layer[73].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[73].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[73].param[i].lr_mult = 1.0;//default value
		netParameter->layer[73].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[73].param[0].lr_mult = 1;
	netParameter->layer[73].param[0].decay_mult = 1;
	netParameter->layer[73].param[1].lr_mult = 2;
	netParameter->layer[73].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[73].convolution_param.bias_term = true;//default value
	netParameter->layer[73].convolution_param.pad_h = 0;//default value
	netParameter->layer[73].convolution_param.pad_w = 0;//default value
	netParameter->layer[73].convolution_param.group = 1;//default value
	netParameter->layer[73].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[73].convolution_param.axis = 1;//default value
	netParameter->layer[73].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[73].convolution_param.num_output = 126;
	netParameter->layer[73].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[73].convolution_param.pad_size = 1;
	netParameter->layer[73].convolution_param.pad[0] = 1;
	netParameter->layer[73].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[73].convolution_param.kernel_size_size = 1;
	netParameter->layer[73].convolution_param.kernel_size[0] = 3;
	netParameter->layer[73].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[73].convolution_param.stride_size = 1;
	netParameter->layer[73].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[73].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[73].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[73].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[73].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[73].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[73].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[73].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[73].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[73].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[73].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[73].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[73].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[73].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[73].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[73].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[73].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[73].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[73].convolution_param.bias_filler.type,"constant");
	netParameter->layer[73].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[74].name,"conv7_2_mbox_conf_perm");
	CHECK_EXPR_RET(strlen("Permute") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[74].type,"Permute");
	netParameter->layer[74].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[74].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[74].bottom[0],"conv7_2_mbox_conf");
	netParameter->layer[74].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[74].top_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[74].top[0],"conv7_2_mbox_conf_perm");
	netParameter->layer[74].permute_param.order = (UINT32 *)malloc(sizeof(UINT32)*4);
	netParameter->layer[74].permute_param.order_size = 4;
	netParameter->layer[74].permute_param.order[0] = 0;
	netParameter->layer[74].permute_param.order[1] = 2;
	netParameter->layer[74].permute_param.order[2] = 3;
	netParameter->layer[74].permute_param.order[3] = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[75].name,"conv7_2_mbox_conf_flat");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[75].type,"Flatten");
	netParameter->layer[75].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[75].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[75].bottom[0],"conv7_2_mbox_conf_perm");
	netParameter->layer[75].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[75].top_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[75].top[0],"conv7_2_mbox_conf_flat");

	//Give default values begin:
	netParameter->layer[75].flatten_param.axis = 1;//default value
	netParameter->layer[75].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[75].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[76].name,"conv7_2_mbox_priorbox");
	CHECK_EXPR_RET(strlen("PriorBox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[76].type,"PriorBox");
	netParameter->layer[76].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*2);
	netParameter->layer[76].bottom_size = 2;
	CHECK_EXPR_RET(strlen("conv7_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[76].bottom[0],"conv7_2");
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[76].bottom[1],"data");
	netParameter->layer[76].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[76].top_size = 1;
	CHECK_EXPR_RET(strlen("conv7_2_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[76].top[0],"conv7_2_mbox_priorbox");

	//Give default values begin:
	netParameter->layer[76].prior_box_param.flip = true;//default value
	netParameter->layer[76].prior_box_param.clip = true;//default value
	//Give default values end

	netParameter->layer[76].prior_box_param.min_size = 168.0;
	netParameter->layer[76].prior_box_param.max_size = 222.0;
	netParameter->layer[76].prior_box_param.aspect_ratio = (float *)malloc(sizeof(float)*2);
	netParameter->layer[76].prior_box_param.aspect_ratio_size = 2;
	netParameter->layer[76].prior_box_param.aspect_ratio[0] = 2;
	netParameter->layer[76].prior_box_param.aspect_ratio[1] = 3;
	netParameter->layer[76].prior_box_param.flip = true;
	netParameter->layer[76].prior_box_param.clip = true;
	netParameter->layer[76].prior_box_param.variance = (float *)malloc(sizeof(float)*4);
	netParameter->layer[76].prior_box_param.variance_size = 4;
	netParameter->layer[76].prior_box_param.variance[0] = 0.1;
	netParameter->layer[76].prior_box_param.variance[1] = 0.1;
	netParameter->layer[76].prior_box_param.variance[2] = 0.2;
	netParameter->layer[76].prior_box_param.variance[3] = 0.2;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[77].name,"conv8_2_mbox_loc");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[77].type,"Convolution");
	netParameter->layer[77].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[77].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[77].bottom[0],"conv8_2");
	netParameter->layer[77].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[77].top_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[77].top[0],"conv8_2_mbox_loc");
	netParameter->layer[77].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[77].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[77].param[i].lr_mult = 1.0;//default value
		netParameter->layer[77].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[77].param[0].lr_mult = 1;
	netParameter->layer[77].param[0].decay_mult = 1;
	netParameter->layer[77].param[1].lr_mult = 2;
	netParameter->layer[77].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[77].convolution_param.bias_term = true;//default value
	netParameter->layer[77].convolution_param.pad_h = 0;//default value
	netParameter->layer[77].convolution_param.pad_w = 0;//default value
	netParameter->layer[77].convolution_param.group = 1;//default value
	netParameter->layer[77].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[77].convolution_param.axis = 1;//default value
	netParameter->layer[77].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[77].convolution_param.num_output = 24;
	netParameter->layer[77].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[77].convolution_param.pad_size = 1;
	netParameter->layer[77].convolution_param.pad[0] = 1;
	netParameter->layer[77].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[77].convolution_param.kernel_size_size = 1;
	netParameter->layer[77].convolution_param.kernel_size[0] = 3;
	netParameter->layer[77].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[77].convolution_param.stride_size = 1;
	netParameter->layer[77].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[77].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[77].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[77].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[77].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[77].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[77].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[77].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[77].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[77].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[77].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[77].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[77].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[77].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[77].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[77].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[77].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[77].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[77].convolution_param.bias_filler.type,"constant");
	netParameter->layer[77].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[78].name,"conv8_2_mbox_loc_perm");
	CHECK_EXPR_RET(strlen("Permute") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[78].type,"Permute");
	netParameter->layer[78].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[78].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[78].bottom[0],"conv8_2_mbox_loc");
	netParameter->layer[78].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[78].top_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[78].top[0],"conv8_2_mbox_loc_perm");
	netParameter->layer[78].permute_param.order = (UINT32 *)malloc(sizeof(UINT32)*4);
	netParameter->layer[78].permute_param.order_size = 4;
	netParameter->layer[78].permute_param.order[0] = 0;
	netParameter->layer[78].permute_param.order[1] = 2;
	netParameter->layer[78].permute_param.order[2] = 3;
	netParameter->layer[78].permute_param.order[3] = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[79].name,"conv8_2_mbox_loc_flat");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[79].type,"Flatten");
	netParameter->layer[79].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[79].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[79].bottom[0],"conv8_2_mbox_loc_perm");
	netParameter->layer[79].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[79].top_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[79].top[0],"conv8_2_mbox_loc_flat");

	//Give default values begin:
	netParameter->layer[79].flatten_param.axis = 1;//default value
	netParameter->layer[79].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[79].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[80].name,"conv8_2_mbox_conf");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[80].type,"Convolution");
	netParameter->layer[80].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[80].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[80].bottom[0],"conv8_2");
	netParameter->layer[80].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[80].top_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[80].top[0],"conv8_2_mbox_conf");
	netParameter->layer[80].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[80].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[80].param[i].lr_mult = 1.0;//default value
		netParameter->layer[80].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[80].param[0].lr_mult = 1;
	netParameter->layer[80].param[0].decay_mult = 1;
	netParameter->layer[80].param[1].lr_mult = 2;
	netParameter->layer[80].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[80].convolution_param.bias_term = true;//default value
	netParameter->layer[80].convolution_param.pad_h = 0;//default value
	netParameter->layer[80].convolution_param.pad_w = 0;//default value
	netParameter->layer[80].convolution_param.group = 1;//default value
	netParameter->layer[80].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[80].convolution_param.axis = 1;//default value
	netParameter->layer[80].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[80].convolution_param.num_output = 126;
	netParameter->layer[80].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[80].convolution_param.pad_size = 1;
	netParameter->layer[80].convolution_param.pad[0] = 1;
	netParameter->layer[80].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[80].convolution_param.kernel_size_size = 1;
	netParameter->layer[80].convolution_param.kernel_size[0] = 3;
	netParameter->layer[80].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[80].convolution_param.stride_size = 1;
	netParameter->layer[80].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[80].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[80].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[80].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[80].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[80].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[80].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[80].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[80].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[80].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[80].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[80].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[80].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[80].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[80].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[80].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[80].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[80].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[80].convolution_param.bias_filler.type,"constant");
	netParameter->layer[80].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[81].name,"conv8_2_mbox_conf_perm");
	CHECK_EXPR_RET(strlen("Permute") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[81].type,"Permute");
	netParameter->layer[81].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[81].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[81].bottom[0],"conv8_2_mbox_conf");
	netParameter->layer[81].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[81].top_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[81].top[0],"conv8_2_mbox_conf_perm");
	netParameter->layer[81].permute_param.order = (UINT32 *)malloc(sizeof(UINT32)*4);
	netParameter->layer[81].permute_param.order_size = 4;
	netParameter->layer[81].permute_param.order[0] = 0;
	netParameter->layer[81].permute_param.order[1] = 2;
	netParameter->layer[81].permute_param.order[2] = 3;
	netParameter->layer[81].permute_param.order[3] = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[82].name,"conv8_2_mbox_conf_flat");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[82].type,"Flatten");
	netParameter->layer[82].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[82].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[82].bottom[0],"conv8_2_mbox_conf_perm");
	netParameter->layer[82].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[82].top_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[82].top[0],"conv8_2_mbox_conf_flat");

	//Give default values begin:
	netParameter->layer[82].flatten_param.axis = 1;//default value
	netParameter->layer[82].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[82].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[83].name,"conv8_2_mbox_priorbox");
	CHECK_EXPR_RET(strlen("PriorBox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[83].type,"PriorBox");
	netParameter->layer[83].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*2);
	netParameter->layer[83].bottom_size = 2;
	CHECK_EXPR_RET(strlen("conv8_2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[83].bottom[0],"conv8_2");
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[83].bottom[1],"data");
	netParameter->layer[83].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[83].top_size = 1;
	CHECK_EXPR_RET(strlen("conv8_2_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[83].top[0],"conv8_2_mbox_priorbox");

	//Give default values begin:
	netParameter->layer[83].prior_box_param.flip = true;//default value
	netParameter->layer[83].prior_box_param.clip = true;//default value
	//Give default values end

	netParameter->layer[83].prior_box_param.min_size = 222.0;
	netParameter->layer[83].prior_box_param.max_size = 276.0;
	netParameter->layer[83].prior_box_param.aspect_ratio = (float *)malloc(sizeof(float)*2);
	netParameter->layer[83].prior_box_param.aspect_ratio_size = 2;
	netParameter->layer[83].prior_box_param.aspect_ratio[0] = 2;
	netParameter->layer[83].prior_box_param.aspect_ratio[1] = 3;
	netParameter->layer[83].prior_box_param.flip = true;
	netParameter->layer[83].prior_box_param.clip = true;
	netParameter->layer[83].prior_box_param.variance = (float *)malloc(sizeof(float)*4);
	netParameter->layer[83].prior_box_param.variance_size = 4;
	netParameter->layer[83].prior_box_param.variance[0] = 0.1;
	netParameter->layer[83].prior_box_param.variance[1] = 0.1;
	netParameter->layer[83].prior_box_param.variance[2] = 0.2;
	netParameter->layer[83].prior_box_param.variance[3] = 0.2;
	CHECK_EXPR_RET(strlen("pool6_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[84].name,"pool6_mbox_loc");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[84].type,"Convolution");
	netParameter->layer[84].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[84].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[84].bottom[0],"pool6");
	netParameter->layer[84].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[84].top_size = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[84].top[0],"pool6_mbox_loc");
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

	netParameter->layer[84].convolution_param.num_output = 24;
	netParameter->layer[84].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[84].convolution_param.pad_size = 1;
	netParameter->layer[84].convolution_param.pad[0] = 1;
	netParameter->layer[84].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[84].convolution_param.kernel_size_size = 1;
	netParameter->layer[84].convolution_param.kernel_size[0] = 3;
	netParameter->layer[84].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[84].convolution_param.stride_size = 1;
	netParameter->layer[84].convolution_param.stride[0] = 1;

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
	netParameter->layer[84].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("pool6_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[85].name,"pool6_mbox_loc_perm");
	CHECK_EXPR_RET(strlen("Permute") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[85].type,"Permute");
	netParameter->layer[85].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[85].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[85].bottom[0],"pool6_mbox_loc");
	netParameter->layer[85].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[85].top_size = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[85].top[0],"pool6_mbox_loc_perm");
	netParameter->layer[85].permute_param.order = (UINT32 *)malloc(sizeof(UINT32)*4);
	netParameter->layer[85].permute_param.order_size = 4;
	netParameter->layer[85].permute_param.order[0] = 0;
	netParameter->layer[85].permute_param.order[1] = 2;
	netParameter->layer[85].permute_param.order[2] = 3;
	netParameter->layer[85].permute_param.order[3] = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[86].name,"pool6_mbox_loc_flat");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[86].type,"Flatten");
	netParameter->layer[86].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[86].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_loc_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[86].bottom[0],"pool6_mbox_loc_perm");
	netParameter->layer[86].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[86].top_size = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[86].top[0],"pool6_mbox_loc_flat");

	//Give default values begin:
	netParameter->layer[86].flatten_param.axis = 1;//default value
	netParameter->layer[86].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[86].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[87].name,"pool6_mbox_conf");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[87].type,"Convolution");
	netParameter->layer[87].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[87].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[87].bottom[0],"pool6");
	netParameter->layer[87].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[87].top_size = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[87].top[0],"pool6_mbox_conf");
	netParameter->layer[87].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[87].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[87].param[i].lr_mult = 1.0;//default value
		netParameter->layer[87].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[87].param[0].lr_mult = 1;
	netParameter->layer[87].param[0].decay_mult = 1;
	netParameter->layer[87].param[1].lr_mult = 2;
	netParameter->layer[87].param[1].decay_mult = 0;

	//Give default values begin:
	netParameter->layer[87].convolution_param.bias_term = true;//default value
	netParameter->layer[87].convolution_param.pad_h = 0;//default value
	netParameter->layer[87].convolution_param.pad_w = 0;//default value
	netParameter->layer[87].convolution_param.group = 1;//default value
	netParameter->layer[87].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[87].convolution_param.axis = 1;//default value
	netParameter->layer[87].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[87].convolution_param.num_output = 126;
	netParameter->layer[87].convolution_param.pad = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[87].convolution_param.pad_size = 1;
	netParameter->layer[87].convolution_param.pad[0] = 1;
	netParameter->layer[87].convolution_param.kernel_size = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[87].convolution_param.kernel_size_size = 1;
	netParameter->layer[87].convolution_param.kernel_size[0] = 3;
	netParameter->layer[87].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[87].convolution_param.stride_size = 1;
	netParameter->layer[87].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[87].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[87].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[87].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[87].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[87].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[87].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[87].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[87].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[87].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[87].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[87].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[87].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[87].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[87].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[87].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[87].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[87].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[87].convolution_param.bias_filler.type,"constant");
	netParameter->layer[87].convolution_param.bias_filler.value = 0;
	CHECK_EXPR_RET(strlen("pool6_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[88].name,"pool6_mbox_conf_perm");
	CHECK_EXPR_RET(strlen("Permute") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[88].type,"Permute");
	netParameter->layer[88].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[88].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[88].bottom[0],"pool6_mbox_conf");
	netParameter->layer[88].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[88].top_size = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[88].top[0],"pool6_mbox_conf_perm");
	netParameter->layer[88].permute_param.order = (UINT32 *)malloc(sizeof(UINT32)*4);
	netParameter->layer[88].permute_param.order_size = 4;
	netParameter->layer[88].permute_param.order[0] = 0;
	netParameter->layer[88].permute_param.order[1] = 2;
	netParameter->layer[88].permute_param.order[2] = 3;
	netParameter->layer[88].permute_param.order[3] = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[89].name,"pool6_mbox_conf_flat");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[89].type,"Flatten");
	netParameter->layer[89].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[89].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_conf_perm") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[89].bottom[0],"pool6_mbox_conf_perm");
	netParameter->layer[89].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[89].top_size = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[89].top[0],"pool6_mbox_conf_flat");

	//Give default values begin:
	netParameter->layer[89].flatten_param.axis = 1;//default value
	netParameter->layer[89].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[89].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[90].name,"pool6_mbox_priorbox");
	CHECK_EXPR_RET(strlen("PriorBox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[90].type,"PriorBox");
	netParameter->layer[90].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*2);
	netParameter->layer[90].bottom_size = 2;
	CHECK_EXPR_RET(strlen("pool6") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[90].bottom[0],"pool6");
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[90].bottom[1],"data");
	netParameter->layer[90].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[90].top_size = 1;
	CHECK_EXPR_RET(strlen("pool6_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[90].top[0],"pool6_mbox_priorbox");

	//Give default values begin:
	netParameter->layer[90].prior_box_param.flip = true;//default value
	netParameter->layer[90].prior_box_param.clip = true;//default value
	//Give default values end

	netParameter->layer[90].prior_box_param.min_size = 276.0;
	netParameter->layer[90].prior_box_param.max_size = 330.0;
	netParameter->layer[90].prior_box_param.aspect_ratio = (float *)malloc(sizeof(float)*2);
	netParameter->layer[90].prior_box_param.aspect_ratio_size = 2;
	netParameter->layer[90].prior_box_param.aspect_ratio[0] = 2;
	netParameter->layer[90].prior_box_param.aspect_ratio[1] = 3;
	netParameter->layer[90].prior_box_param.flip = true;
	netParameter->layer[90].prior_box_param.clip = true;
	netParameter->layer[90].prior_box_param.variance = (float *)malloc(sizeof(float)*4);
	netParameter->layer[90].prior_box_param.variance_size = 4;
	netParameter->layer[90].prior_box_param.variance[0] = 0.1;
	netParameter->layer[90].prior_box_param.variance[1] = 0.1;
	netParameter->layer[90].prior_box_param.variance[2] = 0.2;
	netParameter->layer[90].prior_box_param.variance[3] = 0.2;
	CHECK_EXPR_RET(strlen("mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].name,"mbox_loc");
	CHECK_EXPR_RET(strlen("Concat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].type,"Concat");
	netParameter->layer[91].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*6);
	netParameter->layer[91].bottom_size = 6;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].bottom[0],"conv4_3_norm_mbox_loc_flat");
	CHECK_EXPR_RET(strlen("fc7_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].bottom[1],"fc7_mbox_loc_flat");
	CHECK_EXPR_RET(strlen("conv6_2_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].bottom[2],"conv6_2_mbox_loc_flat");
	CHECK_EXPR_RET(strlen("conv7_2_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].bottom[3],"conv7_2_mbox_loc_flat");
	CHECK_EXPR_RET(strlen("conv8_2_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].bottom[4],"conv8_2_mbox_loc_flat");
	CHECK_EXPR_RET(strlen("pool6_mbox_loc_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].bottom[5],"pool6_mbox_loc_flat");
	netParameter->layer[91].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[91].top_size = 1;
	CHECK_EXPR_RET(strlen("mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[91].top[0],"mbox_loc");

	//Give default values begin:
	netParameter->layer[91].concat_param.axis = 1;//default value
	netParameter->layer[91].concat_param.concat_dim = 1;//default value
	//Give default values end

	netParameter->layer[91].concat_param.axis = 1;
	CHECK_EXPR_RET(strlen("mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].name,"mbox_conf");
	CHECK_EXPR_RET(strlen("Concat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].type,"Concat");
	netParameter->layer[92].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*6);
	netParameter->layer[92].bottom_size = 6;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].bottom[0],"conv4_3_norm_mbox_conf_flat");
	CHECK_EXPR_RET(strlen("fc7_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].bottom[1],"fc7_mbox_conf_flat");
	CHECK_EXPR_RET(strlen("conv6_2_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].bottom[2],"conv6_2_mbox_conf_flat");
	CHECK_EXPR_RET(strlen("conv7_2_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].bottom[3],"conv7_2_mbox_conf_flat");
	CHECK_EXPR_RET(strlen("conv8_2_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].bottom[4],"conv8_2_mbox_conf_flat");
	CHECK_EXPR_RET(strlen("pool6_mbox_conf_flat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].bottom[5],"pool6_mbox_conf_flat");
	netParameter->layer[92].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[92].top_size = 1;
	CHECK_EXPR_RET(strlen("mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[92].top[0],"mbox_conf");

	//Give default values begin:
	netParameter->layer[92].concat_param.axis = 1;//default value
	netParameter->layer[92].concat_param.concat_dim = 1;//default value
	//Give default values end

	netParameter->layer[92].concat_param.axis = 1;
	CHECK_EXPR_RET(strlen("mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].name,"mbox_priorbox");
	CHECK_EXPR_RET(strlen("Concat") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].type,"Concat");
	netParameter->layer[93].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*6);
	netParameter->layer[93].bottom_size = 6;
	CHECK_EXPR_RET(strlen("conv4_3_norm_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].bottom[0],"conv4_3_norm_mbox_priorbox");
	CHECK_EXPR_RET(strlen("fc7_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].bottom[1],"fc7_mbox_priorbox");
	CHECK_EXPR_RET(strlen("conv6_2_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].bottom[2],"conv6_2_mbox_priorbox");
	CHECK_EXPR_RET(strlen("conv7_2_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].bottom[3],"conv7_2_mbox_priorbox");
	CHECK_EXPR_RET(strlen("conv8_2_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].bottom[4],"conv8_2_mbox_priorbox");
	CHECK_EXPR_RET(strlen("pool6_mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].bottom[5],"pool6_mbox_priorbox");
	netParameter->layer[93].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[93].top_size = 1;
	CHECK_EXPR_RET(strlen("mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[93].top[0],"mbox_priorbox");

	//Give default values begin:
	netParameter->layer[93].concat_param.axis = 1;//default value
	netParameter->layer[93].concat_param.concat_dim = 1;//default value
	//Give default values end

	netParameter->layer[93].concat_param.axis = 2;
	CHECK_EXPR_RET(strlen("mbox_conf_reshape") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[94].name,"mbox_conf_reshape");
	CHECK_EXPR_RET(strlen("Reshape") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[94].type,"Reshape");
	netParameter->layer[94].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[94].bottom_size = 1;
	CHECK_EXPR_RET(strlen("mbox_conf") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[94].bottom[0],"mbox_conf");
	netParameter->layer[94].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[94].top_size = 1;
	CHECK_EXPR_RET(strlen("mbox_conf_reshape") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[94].top[0],"mbox_conf_reshape");

	//Give default values begin:
	netParameter->layer[94].reshape_param.axis = 0;//default value
	netParameter->layer[94].reshape_param.num_axes = -1;//default value
	//Give default values end

	netParameter->layer[94].reshape_param.shape.dim = (INT64 *)malloc(sizeof(INT64)*3);
	netParameter->layer[94].reshape_param.shape.dim_size = 3;
	netParameter->layer[94].reshape_param.shape.dim[0] = 0;
	netParameter->layer[94].reshape_param.shape.dim[1] = -1;
	netParameter->layer[94].reshape_param.shape.dim[2] = 21;
	CHECK_EXPR_RET(strlen("mbox_conf_softmax") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[95].name,"mbox_conf_softmax");
	CHECK_EXPR_RET(strlen("Softmax") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[95].type,"Softmax");
	netParameter->layer[95].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[95].bottom_size = 1;
	CHECK_EXPR_RET(strlen("mbox_conf_reshape") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[95].bottom[0],"mbox_conf_reshape");
	netParameter->layer[95].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[95].top_size = 1;
	CHECK_EXPR_RET(strlen("mbox_conf_softmax") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[95].top[0],"mbox_conf_softmax");

	//Give default values begin:
	netParameter->layer[95].softmax_param.engine = SoftmaxParameter_Engine_DEFAULT;//default value
	netParameter->layer[95].softmax_param.axis = 1;//default value
	//Give default values end

	netParameter->layer[95].softmax_param.axis = 2;
	CHECK_EXPR_RET(strlen("mbox_conf_flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[96].name,"mbox_conf_flatten");
	CHECK_EXPR_RET(strlen("Flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[96].type,"Flatten");
	netParameter->layer[96].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[96].bottom_size = 1;
	CHECK_EXPR_RET(strlen("mbox_conf_softmax") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[96].bottom[0],"mbox_conf_softmax");
	netParameter->layer[96].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[96].top_size = 1;
	CHECK_EXPR_RET(strlen("mbox_conf_flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[96].top[0],"mbox_conf_flatten");

	//Give default values begin:
	netParameter->layer[96].flatten_param.axis = 1;//default value
	netParameter->layer[96].flatten_param.end_axis = -1;//default value
	//Give default values end

	netParameter->layer[96].flatten_param.axis = 1;
	CHECK_EXPR_RET(strlen("detection_out") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].name,"detection_out");
	CHECK_EXPR_RET(strlen("DetectionOutput") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].type,"DetectionOutput");
	netParameter->layer[97].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*3);
	netParameter->layer[97].bottom_size = 3;
	CHECK_EXPR_RET(strlen("mbox_loc") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].bottom[0],"mbox_loc");
	CHECK_EXPR_RET(strlen("mbox_conf_flatten") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].bottom[1],"mbox_conf_flatten");
	CHECK_EXPR_RET(strlen("mbox_priorbox") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].bottom[2],"mbox_priorbox");
	netParameter->layer[97].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[97].top_size = 1;
	CHECK_EXPR_RET(strlen("detection_out") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].top[0],"detection_out");
	netParameter->layer[97].include = (NetStateRule *)malloc(sizeof(NetStateRule)*1);
	netParameter->layer[97].include_size = 1;
	netParameter->layer[97].include[0].phase = TEST;

	//Give default values begin:
	netParameter->layer[97].detection_output_param.share_location = true;//default value
	netParameter->layer[97].detection_output_param.background_label_id = 0;//default value
	netParameter->layer[97].detection_output_param.code_type = PriorBoxParameter_CodeType_CORNER;//default value
	netParameter->layer[97].detection_output_param.variance_encoded_in_target = false;//default value
	netParameter->layer[97].detection_output_param.keep_top_k = -1;//default value
	netParameter->layer[97].detection_output_param.visualize = false;//default value
	//Give default values end

	netParameter->layer[97].detection_output_param.num_classes = 21;
	netParameter->layer[97].detection_output_param.share_location = true;
	netParameter->layer[97].detection_output_param.background_label_id = 0;

	//Give default values begin:
	netParameter->layer[97].detection_output_param.nms_param.nms_threshold = 0.3;//default value
	//Give default values end

	netParameter->layer[97].detection_output_param.nms_param.nms_threshold = 0.45;
	netParameter->layer[97].detection_output_param.nms_param.top_k = 400;
	CHECK_EXPR_RET(strlen("/root/data/VOCdevkit/results/VOC2007/SSD_300x300/Main") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].detection_output_param.save_output_param.output_directory,"/root/data/VOCdevkit/results/VOC2007/SSD_300x300/Main");
	CHECK_EXPR_RET(strlen("comp4_det_test_") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].detection_output_param.save_output_param.output_name_prefix,"comp4_det_test_");
	CHECK_EXPR_RET(strlen("VOC") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].detection_output_param.save_output_param.output_format,"VOC");
	CHECK_EXPR_RET(strlen("data/VOC0712/labelmap_voc.prototxt") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].detection_output_param.save_output_param.label_map_file,"data/VOC0712/labelmap_voc.prototxt");
	CHECK_EXPR_RET(strlen("data/VOC0712/test_name_size.txt") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[97].detection_output_param.save_output_param.name_size_file,"data/VOC0712/test_name_size.txt");
	netParameter->layer[97].detection_output_param.save_output_param.num_test_image = 4952;
	netParameter->layer[97].detection_output_param.code_type = PriorBoxParameter_CodeType_CENTER_SIZE;
	netParameter->layer[97].detection_output_param.keep_top_k = 200;
	netParameter->layer[97].detection_output_param.confidence_threshold = 0.01;
	return 0;

}
