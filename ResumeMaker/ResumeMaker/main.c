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
	
	if(argc < 2)
	{
		printf("[program name.exe] [textfile.txt]\n");
		exit(EXIT_SUCCESS);
	}
	
	buffSize = BufferSize(argv[1]);
	mainBuffer = (char*)malloc(sizeof(char) * BufferSize("info.txt"));
	CopyFileToArray(argv[1],mainBuffer);

	TemplateA(mainBuffer,"myCv.html");


	
	/*if(mainBuffer != NULL)
		free(mainBuffer);*/
	return 0;
}