//
//				This program read info from text file and convert this into Html file
//
//              Author : Muhammad Ahmed

#include <stdio.h>
#include <stdlib.h>



#include "function.h"

int main(int argc, char*argv[])
{
	char* mainBuffer;
	int buffSize ;
	int i = 0;
	Info* pInfo;
	pInfo = (Info*)malloc(sizeof(Info*));

	buffSize = BufferSize(argv[1]);
	mainBuffer = (char*)malloc(sizeof(char) * BufferSize("info.txt"));
	
	printf("%d", buffSize);
	CopyFileToArray(argv[1],mainBuffer);

	for(i = 0; i < buffSize ; i++)
	{
		printf("%c",mainBuffer[i]);
	}	

	TemplateA(mainBuffer,"myCv.html");


	getInfo(mainBuffer, pInfo);

	
	

	/*if(mainBuffer != NULL)
		free(mainBuffer);*/
	return 0;
}