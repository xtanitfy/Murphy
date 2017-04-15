#include "parameter.h"
int parse(NetParameter * netParameter)
{
	CHECK_EXPR_RET(strlen("LeNet") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->name,"LeNet");
	netParameter->layer = (LayerParameter *)malloc(sizeof(LayerParameter)*11);
	netParameter->layer_size = 11;
	CHECK_EXPR_RET(strlen("mnist") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].name,"mnist");
	CHECK_EXPR_RET(strlen("Data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].type,"Data");
	netParameter->layer[0].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*2);
	netParameter->layer[0].top_size = 2;
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].top[0],"data");
	CHECK_EXPR_RET(strlen("label") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].top[1],"label");
	netParameter->layer[0].include = (NetStateRule *)malloc(sizeof(NetStateRule)*1);
	netParameter->layer[0].include_size = 1;
	netParameter->layer[0].include[0].phase = TRAIN;

	//Give default values begin:
	netParameter->layer[0].transform_param.scale = 1;//default value
	netParameter->layer[0].transform_param.mirror = false;//default value
	netParameter->layer[0].transform_param.crop_size = 0;//default value
	netParameter->layer[0].transform_param.crop_h = 0;//default value
	netParameter->layer[0].transform_param.crop_w = 0;//default value
	netParameter->layer[0].transform_param.force_color = false;//default value
	netParameter->layer[0].transform_param.force_gray = false;//default value
	//Give default values end

	netParameter->layer[0].transform_param.scale = 0.00390625;
	CHECK_EXPR_RET(strlen("examples/my_mnist/mean.binaryproto") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].transform_param.mean_file,"examples/my_mnist/mean.binaryproto");

	//Give default values begin:
	netParameter->layer[0].data_param.rand_skip = 0;//default value
	netParameter->layer[0].data_param.backend = DataParameter_DB_LEVELDB;//default value
	netParameter->layer[0].data_param.scale = 1;//default value
	netParameter->layer[0].data_param.crop_size = 0;//default value
	netParameter->layer[0].data_param.mirror = false;//default value
	netParameter->layer[0].data_param.force_encoded_color = false;//default value
	netParameter->layer[0].data_param.prefetch = 4;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("examples/my_mnist/mnist_train_lmdb") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[0].data_param.source,"examples/my_mnist/mnist_train_lmdb");
	netParameter->layer[0].data_param.batch_size = 64;
	netParameter->layer[0].data_param.backend = DataParameter_DB_LMDB;
	CHECK_EXPR_RET(strlen("mnist") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].name,"mnist");
	CHECK_EXPR_RET(strlen("Data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].type,"Data");
	netParameter->layer[1].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*2);
	netParameter->layer[1].top_size = 2;
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].top[0],"data");
	CHECK_EXPR_RET(strlen("label") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].top[1],"label");
	netParameter->layer[1].include = (NetStateRule *)malloc(sizeof(NetStateRule)*1);
	netParameter->layer[1].include_size = 1;
	netParameter->layer[1].include[0].phase = TEST;

	//Give default values begin:
	netParameter->layer[1].transform_param.scale = 1;//default value
	netParameter->layer[1].transform_param.mirror = false;//default value
	netParameter->layer[1].transform_param.crop_size = 0;//default value
	netParameter->layer[1].transform_param.crop_h = 0;//default value
	netParameter->layer[1].transform_param.crop_w = 0;//default value
	netParameter->layer[1].transform_param.force_color = false;//default value
	netParameter->layer[1].transform_param.force_gray = false;//default value
	//Give default values end

	netParameter->layer[1].transform_param.scale = 0.00390625;
	CHECK_EXPR_RET(strlen("examples/my_mnist/mean.binaryproto") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].transform_param.mean_file,"examples/my_mnist/mean.binaryproto");

	//Give default values begin:
	netParameter->layer[1].data_param.rand_skip = 0;//default value
	netParameter->layer[1].data_param.backend = DataParameter_DB_LEVELDB;//default value
	netParameter->layer[1].data_param.scale = 1;//default value
	netParameter->layer[1].data_param.crop_size = 0;//default value
	netParameter->layer[1].data_param.mirror = false;//default value
	netParameter->layer[1].data_param.force_encoded_color = false;//default value
	netParameter->layer[1].data_param.prefetch = 4;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("examples/my_mnist/mnist_test_lmdb") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[1].data_param.source,"examples/my_mnist/mnist_test_lmdb");
	netParameter->layer[1].data_param.batch_size = 100;
	netParameter->layer[1].data_param.backend = DataParameter_DB_LMDB;
	CHECK_EXPR_RET(strlen("conv1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].name,"conv1");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].type,"Convolution");
	netParameter->layer[2].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[2].bottom_size = 1;
	CHECK_EXPR_RET(strlen("data") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].bottom[0],"data");
	netParameter->layer[2].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[2].top_size = 1;
	CHECK_EXPR_RET(strlen("conv1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[2].top[0],"conv1");
	netParameter->layer[2].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[2].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[2].param[i].lr_mult = 1.0;//default value
		netParameter->layer[2].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[2].param[0].lr_mult = 1;
	netParameter->layer[2].param[1].lr_mult = 2;

	//Give default values begin:
	netParameter->layer[2].convolution_param.bias_term = true;//default value
	netParameter->layer[2].convolution_param.pad_h = 0;//default value
	netParameter->layer[2].convolution_param.pad_w = 0;//default value
	netParameter->layer[2].convolution_param.group = 1;//default value
	netParameter->layer[2].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[2].convolution_param.axis = 1;//default value
	netParameter->layer[2].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[2].convolution_param.num_output = 20;
	netParameter->layer[2].convolution_param.kernel_w = 5;
	netParameter->layer[2].convolution_param.kernel_h = 5;
	netParameter->layer[2].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[2].convolution_param.stride_size = 1;
	netParameter->layer[2].convolution_param.stride[0] = 1;

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
	CHECK_EXPR_RET(strlen("pool1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].name,"pool1");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].type,"Pooling");
	netParameter->layer[3].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[3].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].bottom[0],"conv1");
	netParameter->layer[3].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[3].top_size = 1;
	CHECK_EXPR_RET(strlen("pool1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[3].top[0],"pool1");

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
	netParameter->layer[3].pooling_param.kernel_size = 2;
	netParameter->layer[3].pooling_param.stride = 2;
	CHECK_EXPR_RET(strlen("conv2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].name,"conv2");
	CHECK_EXPR_RET(strlen("Convolution") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].type,"Convolution");
	netParameter->layer[4].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[4].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].bottom[0],"pool1");
	netParameter->layer[4].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[4].top_size = 1;
	CHECK_EXPR_RET(strlen("conv2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].top[0],"conv2");
	netParameter->layer[4].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[4].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[4].param[i].lr_mult = 1.0;//default value
		netParameter->layer[4].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[4].param[0].lr_mult = 1;
	netParameter->layer[4].param[1].lr_mult = 2;

	//Give default values begin:
	netParameter->layer[4].convolution_param.bias_term = true;//default value
	netParameter->layer[4].convolution_param.pad_h = 0;//default value
	netParameter->layer[4].convolution_param.pad_w = 0;//default value
	netParameter->layer[4].convolution_param.group = 1;//default value
	netParameter->layer[4].convolution_param.engine = ConvolutionParameter_Engine_DEFAULT;//default value
	netParameter->layer[4].convolution_param.axis = 1;//default value
	netParameter->layer[4].convolution_param.force_nd_im2col = false;//default value
	//Give default values end

	netParameter->layer[4].convolution_param.num_output = 50;
	netParameter->layer[4].convolution_param.kernel_w = 5;
	netParameter->layer[4].convolution_param.kernel_h = 5;
	netParameter->layer[4].convolution_param.stride = (UINT32 *)malloc(sizeof(UINT32)*1);
	netParameter->layer[4].convolution_param.stride_size = 1;
	netParameter->layer[4].convolution_param.stride[0] = 1;

	//Give default values begin:
	strcpy(netParameter->layer[4].convolution_param.weight_filler.type,"constant");//default value
	netParameter->layer[4].convolution_param.weight_filler.value = 0;//default value
	netParameter->layer[4].convolution_param.weight_filler.min = 0;//default value
	netParameter->layer[4].convolution_param.weight_filler.max = 1;//default value
	netParameter->layer[4].convolution_param.weight_filler.mean = 0;//default value
	netParameter->layer[4].convolution_param.weight_filler.std = 1;//default value
	netParameter->layer[4].convolution_param.weight_filler.sparse = -1;//default value
	netParameter->layer[4].convolution_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].convolution_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[4].convolution_param.bias_filler.type,"constant");//default value
	netParameter->layer[4].convolution_param.bias_filler.value = 0;//default value
	netParameter->layer[4].convolution_param.bias_filler.min = 0;//default value
	netParameter->layer[4].convolution_param.bias_filler.max = 1;//default value
	netParameter->layer[4].convolution_param.bias_filler.mean = 0;//default value
	netParameter->layer[4].convolution_param.bias_filler.std = 1;//default value
	netParameter->layer[4].convolution_param.bias_filler.sparse = -1;//default value
	netParameter->layer[4].convolution_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[4].convolution_param.bias_filler.type,"constant");
	CHECK_EXPR_RET(strlen("pool2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].name,"pool2");
	CHECK_EXPR_RET(strlen("Pooling") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].type,"Pooling");
	netParameter->layer[5].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[5].bottom_size = 1;
	CHECK_EXPR_RET(strlen("conv2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].bottom[0],"conv2");
	netParameter->layer[5].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[5].top_size = 1;
	CHECK_EXPR_RET(strlen("pool2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[5].top[0],"pool2");

	//Give default values begin:
	netParameter->layer[5].pooling_param.pool = PoolingParameter_PoolMethod_MAX;//default value
	netParameter->layer[5].pooling_param.pad = 0;//default value
	netParameter->layer[5].pooling_param.pad_h = 0;//default value
	netParameter->layer[5].pooling_param.pad_w = 0;//default value
	netParameter->layer[5].pooling_param.stride = 1;//default value
	netParameter->layer[5].pooling_param.engine = PoolingParameter_Engine_DEFAULT;//default value
	netParameter->layer[5].pooling_param.global_pooling = false;//default value
	//Give default values end

	netParameter->layer[5].pooling_param.pool = PoolingParameter_PoolMethod_MAX;
	netParameter->layer[5].pooling_param.kernel_size = 2;
	netParameter->layer[5].pooling_param.stride = 2;
	CHECK_EXPR_RET(strlen("ip1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].name,"ip1");
	CHECK_EXPR_RET(strlen("InnerProduct") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].type,"InnerProduct");
	netParameter->layer[6].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[6].bottom_size = 1;
	CHECK_EXPR_RET(strlen("pool2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].bottom[0],"pool2");
	netParameter->layer[6].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[6].top_size = 1;
	CHECK_EXPR_RET(strlen("ip1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].top[0],"ip1");
	netParameter->layer[6].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[6].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[6].param[i].lr_mult = 1.0;//default value
		netParameter->layer[6].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[6].param[0].lr_mult = 1;
	netParameter->layer[6].param[1].lr_mult = 2;

	//Give default values begin:
	netParameter->layer[6].inner_product_param.bias_term = true;//default value
	netParameter->layer[6].inner_product_param.axis = 1;//default value
	netParameter->layer[6].inner_product_param.transpose = false;//default value
	//Give default values end

	netParameter->layer[6].inner_product_param.num_output = 500;

	//Give default values begin:
	strcpy(netParameter->layer[6].inner_product_param.weight_filler.type,"constant");//default value
	netParameter->layer[6].inner_product_param.weight_filler.value = 0;//default value
	netParameter->layer[6].inner_product_param.weight_filler.min = 0;//default value
	netParameter->layer[6].inner_product_param.weight_filler.max = 1;//default value
	netParameter->layer[6].inner_product_param.weight_filler.mean = 0;//default value
	netParameter->layer[6].inner_product_param.weight_filler.std = 1;//default value
	netParameter->layer[6].inner_product_param.weight_filler.sparse = -1;//default value
	netParameter->layer[6].inner_product_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].inner_product_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[6].inner_product_param.bias_filler.type,"constant");//default value
	netParameter->layer[6].inner_product_param.bias_filler.value = 0;//default value
	netParameter->layer[6].inner_product_param.bias_filler.min = 0;//default value
	netParameter->layer[6].inner_product_param.bias_filler.max = 1;//default value
	netParameter->layer[6].inner_product_param.bias_filler.mean = 0;//default value
	netParameter->layer[6].inner_product_param.bias_filler.std = 1;//default value
	netParameter->layer[6].inner_product_param.bias_filler.sparse = -1;//default value
	netParameter->layer[6].inner_product_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[6].inner_product_param.bias_filler.type,"constant");
	CHECK_EXPR_RET(strlen("relu1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].name,"relu1");
	CHECK_EXPR_RET(strlen("ReLU") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].type,"ReLU");
	netParameter->layer[7].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[7].bottom_size = 1;
	CHECK_EXPR_RET(strlen("ip1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].bottom[0],"ip1");
	netParameter->layer[7].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[7].top_size = 1;
	CHECK_EXPR_RET(strlen("ip1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[7].top[0],"ip1");
	CHECK_EXPR_RET(strlen("ip2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].name,"ip2");
	CHECK_EXPR_RET(strlen("InnerProduct") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].type,"InnerProduct");
	netParameter->layer[8].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[8].bottom_size = 1;
	CHECK_EXPR_RET(strlen("ip1") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].bottom[0],"ip1");
	netParameter->layer[8].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[8].top_size = 1;
	CHECK_EXPR_RET(strlen("ip2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].top[0],"ip2");
	netParameter->layer[8].param = (ParamSpec *)malloc(sizeof(ParamSpec)*2);
	netParameter->layer[8].param_size = 2;

	//Give default values begin:
	for (int i = 0;i < 2;i++) {
		netParameter->layer[8].param[i].lr_mult = 1.0;//default value
		netParameter->layer[8].param[i].decay_mult = 1.0;//default value
	}
	//Give default values end

	netParameter->layer[8].param[0].lr_mult = 1;
	netParameter->layer[8].param[1].lr_mult = 2;

	//Give default values begin:
	netParameter->layer[8].inner_product_param.bias_term = true;//default value
	netParameter->layer[8].inner_product_param.axis = 1;//default value
	netParameter->layer[8].inner_product_param.transpose = false;//default value
	//Give default values end

	netParameter->layer[8].inner_product_param.num_output = 2;

	//Give default values begin:
	strcpy(netParameter->layer[8].inner_product_param.weight_filler.type,"constant");//default value
	netParameter->layer[8].inner_product_param.weight_filler.value = 0;//default value
	netParameter->layer[8].inner_product_param.weight_filler.min = 0;//default value
	netParameter->layer[8].inner_product_param.weight_filler.max = 1;//default value
	netParameter->layer[8].inner_product_param.weight_filler.mean = 0;//default value
	netParameter->layer[8].inner_product_param.weight_filler.std = 1;//default value
	netParameter->layer[8].inner_product_param.weight_filler.sparse = -1;//default value
	netParameter->layer[8].inner_product_param.weight_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("xavier") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].inner_product_param.weight_filler.type,"xavier");

	//Give default values begin:
	strcpy(netParameter->layer[8].inner_product_param.bias_filler.type,"constant");//default value
	netParameter->layer[8].inner_product_param.bias_filler.value = 0;//default value
	netParameter->layer[8].inner_product_param.bias_filler.min = 0;//default value
	netParameter->layer[8].inner_product_param.bias_filler.max = 1;//default value
	netParameter->layer[8].inner_product_param.bias_filler.mean = 0;//default value
	netParameter->layer[8].inner_product_param.bias_filler.std = 1;//default value
	netParameter->layer[8].inner_product_param.bias_filler.sparse = -1;//default value
	netParameter->layer[8].inner_product_param.bias_filler.variance_norm = FillerParameter_VarianceNorm_FAN_IN;//default value
	//Give default values end

	CHECK_EXPR_RET(strlen("constant") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[8].inner_product_param.bias_filler.type,"constant");
	CHECK_EXPR_RET(strlen("accuracy") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].name,"accuracy");
	CHECK_EXPR_RET(strlen("Accuracy") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].type,"Accuracy");
	netParameter->layer[9].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*2);
	netParameter->layer[9].bottom_size = 2;
	CHECK_EXPR_RET(strlen("ip2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].bottom[0],"ip2");
	CHECK_EXPR_RET(strlen("label") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].bottom[1],"label");
	netParameter->layer[9].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[9].top_size = 1;
	CHECK_EXPR_RET(strlen("accuracy") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[9].top[0],"accuracy");
	netParameter->layer[9].include = (NetStateRule *)malloc(sizeof(NetStateRule)*1);
	netParameter->layer[9].include_size = 1;
	netParameter->layer[9].include[0].phase = TEST;
	CHECK_EXPR_RET(strlen("loss") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].name,"loss");
	CHECK_EXPR_RET(strlen("SoftmaxWithLoss") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].type,"SoftmaxWithLoss");
	netParameter->layer[10].bottom = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*2);
	netParameter->layer[10].bottom_size = 2;
	CHECK_EXPR_RET(strlen("ip2") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].bottom[0],"ip2");
	CHECK_EXPR_RET(strlen("label") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].bottom[1],"label");
	netParameter->layer[10].top = (char (*)[PARSE_STR_NAME_SIZE])malloc(PARSE_STR_NAME_SIZE*1);
	netParameter->layer[10].top_size = 1;
	CHECK_EXPR_RET(strlen("loss") > PARSE_STR_NAME_SIZE - 1,-1);
	strcpy(netParameter->layer[10].top[0],"loss");
	return 0;

}
