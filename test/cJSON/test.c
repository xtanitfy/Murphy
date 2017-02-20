#include <stdio.h>
#include <stdlib.h>
#include <string.h>                                                                                   
#include "cJSON.h"

char * makeJson()
{
	cJSON * pJsonRoot = NULL;

	pJsonRoot = cJSON_CreateObject();
	if(NULL == pJsonRoot)
	{
	   //error happend here
	   return NULL;
	 }
	cJSON_AddStringToObject(pJsonRoot, "hello", "hello world");
	cJSON_AddNumberToObject(pJsonRoot, "number", 10010);
	cJSON_AddBoolToObject(pJsonRoot, "bool", 1);
	cJSON * pSubJson = NULL;
	 pSubJson = cJSON_CreateObject();
	if(NULL == pSubJson)
	{
		// create object faild, exit
		cJSON_Delete(pJsonRoot);
		return NULL;
	 }
	  cJSON_AddStringToObject(pSubJson, "subjsonobj", "a sub json string");
	 cJSON_AddItemToObject(pJsonRoot, "subobj", pSubJson);
		printf("--->String:%s\n",pJsonRoot->valuestring);
		
	  char * p = cJSON_Print(pJsonRoot);
	// else use : 
	  // char * p = cJSON_PrintUnformatted(pJsonRoot);
	  if(NULL == p)
	  {
		  //convert json list to string faild, exit
		  //because sub json pSubJson han been add to pJsonRoot, so just delete pJsonRoot, if you also delete pSubJson, it will coredump, and error is : double free
		  cJSON_Delete(pJsonRoot);
		  return NULL;
	  }
	  //free(p);
	  
	  cJSON_Delete(pJsonRoot);

	  return p;
}

void parseJson(char * pMsg)
{
	if(NULL == pMsg){
		return;
	}
	cJSON * pJson = cJSON_Parse(pMsg);
	if(NULL == pJson){
		// parse faild, return
		return ;
	}

	// get string from json
	cJSON * pSub = cJSON_GetObjectItem(pJson, "hello");
	if(NULL == pSub)
	{
	//get object named "hello" faild
	}
	printf("hello:%s\n", pSub->valuestring);

	// get number from json
	pSub = cJSON_GetObjectItem(pJson, "number");
	if(NULL == pSub)
	{
	//get number from json faild
	}
	printf("number:%d\n", pSub->valueint);

	// get bool from json
	pSub = cJSON_GetObjectItem(pJson, "bool");
	if(NULL == pSub)
	{
	// get bool from json faild
	}                                                                                                         
	printf("bool:%d\n", pSub->valueint);

	// get sub object
	pSub = cJSON_GetObjectItem(pJson, "subobj");
	if(NULL == pSub){  
	// get sub object faild
	}
	printf("subobj:\n");
	cJSON * pSubSub = cJSON_GetObjectItem(pSub, "subjsonobj");
	if(NULL == pSubSub){
	// get object from subject object faild
	}
	printf("	subjsonobj:%s\n", pSubSub->valuestring);

	cJSON_Delete(pJson);
}


void Jsonfilter(char *p);


int testWriteJsonToFile(char *fileName)
{
	char buf[1024];
	char * p = NULL;
	FILE *fp = NULL;
	
	p = makeJson();
	if(NULL == p)
	{
		return 0;
	}
	fp = fopen(fileName,"w");
	if(fp == NULL){
		printf("open error!");
		return -1;
	}
	
	Jsonfilter(p);
	printf("%s\n", p);
	fwrite(p,1,strlen(p),fp);
	fclose(fp);
	parseJson(p);

	free(p);//千万不要忘记释放内存呀，cJSON_Print()函数或者cJSON_PrintUnformatted（）产生的内存，使用free(char *)进行释放
	return 0;
}


int testReadJsonFromFile(char *fileName)
{
	FILE *fp = NULL;
	char buf[1024];
	
	fp = fopen(fileName,"r");
	if(fp == NULL){
		printf("open error!");
		return -1;
	}
	
	int nread = fread(buf,1,sizeof(buf)-1,fp);
	buf[nread] = '\0';
	parseJson(buf);
	fclose(fp);
	
	return 0;
}

int main(int argc,char **argv)
{
	//testWriteJsonToFile("test.txt");
	testReadJsonFromFile("test1.txt");
	
	return 0;
}


void Jsonfilter(char *p)
{
	char arr[] = {'\b','\f','\n','\r','\t'};
	char buf[1024];
	int i = 0,j = 0,k = 0,len = 0;
	char flag = 0;
	len = sizeof(arr)/sizeof(arr[0]);

	while(p[i]!='\0'){
		for(k = 0;k < len;k++){
			if(p[i] == arr[k]){
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			flag = 0;
		}else{
			buf[j++] = p[i]; 
		}
		i++;
	}
	
	buf[j] = '\0';
	strcpy(p,buf);
}



