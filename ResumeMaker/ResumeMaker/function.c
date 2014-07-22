
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"function.h"

struct personalInfo
{
	char name[256];
};

int BufferSize(char *Buffer) // this function returns the number of characters of text file
{
	int counter = 0;

	FILE *file;
	file = fopen(Buffer,"r");



		if(file != NULL)
        {
            while  ( fgetc( file )  != EOF )   
            {                                        
               counter++;
            }
         fclose( file );                           
        }

		else
		{
				 /* fopen returns 0, the NULL pointer, on failure */
			printf("file not found");
			exit(EXIT_FAILURE);
		}
		 
		return counter;

}