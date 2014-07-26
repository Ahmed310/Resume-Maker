
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"
#include"Html.h"

struct personalInfo
{
	char name[64];
	char phone[25];
	char eMail[64];
	char adress[256];
	
};
//------------------------------------------------------------------------------------------
static void CopyInfo(char* buffer, const char* token ,char* f)			// only used in this file
{
	char* data;
	char ok = 'n';
	int index = 0;
	char c ;
	data = strstr(buffer, token);

	while(1)
	{
		c = *data++ ;
		if(c == '>')
		{
			f[index] = '\0';
			break;
		}

		if(c == '<')
		{
			ok = 'y';
			c = *data++ ;
		}

		if(ok == 'y')
			f[index++] = c;

	}
}
//------------------------------------------------------------------------------------------
static void putSummary (char* buffer, const char* token, FILE* file)			// only used in this file
{
	char* data;
	char ok = 'n';
	int index = 0;
	char c ;
	char p = 'n';						// print to file or not
	data = strstr(buffer, token);

	while(1)
	{
		c = *data++ ;
		if(c == '<' && ok == 'n')
		{
			ok = 'y';
			continue;
		}
		
		if(c == '<' && ok == 'y')
		{
			p = 'y';
			c = *data++;
		}

		if(p == 'y')
		{
			if(c == '>')
				break;
			fputc(c,file);
		}

	}
}
//------------------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------------------
void TemplateA(char* data,const char* fileName)
{
	FILE *file;
	Info pInfo;
	char summaryT[25] = {'\0', '\0'};													// summary title
	file = fopen(fileName,"w");
	getInfo(data,&pInfo);
	CopyInfo(data,"summary",summaryT);
	if(file != NULL)
	{
		fprintf(file,"<html> \n \t <body>\n \t \t<center>");            // start html, body or center tags

		fprintf(file,"\n<table border=\"1\" width=\"800\" cellpadding = \"0\" cellspacing = \"0\">  ");         // table start tag

		fprintf(file,"\n<tr>");											// insert row
		fprintf(file,"\n<td width = \"500\" align = \"center\" >");		// insert data start tag

		//insertLine(file,"90%%");
		insertHeading(file,"Muhammad Ahmed",1);
		//insertLine(file,"90%%");

		

		fprintf(file,"\n</td>");										// insert data end tag

		fprintf(file,"\n<td width = \"300\" align = \"left\" >");		// insert data start tag
		
		fprintf(file,"P: ");
		fprintf(file,pInfo.phone);
		newLine(file);

		fprintf(file,"E: ");
		fprintf(file,pInfo.eMail);
		newLine(file);

		fprintf(file,"A: ");
		fprintf(file,pInfo.adress);
		newLine(file);

		fprintf(file,"\n</td>");										// insert data end tag

		fprintf(file,"\n</tr>");										// row end tag
		
		
		fprintf(file,"\n<tr>");
		fprintf(file,"\n<td align = \"center\"  colspan = \"2\"  >");		                // insert data start tag

		//insertLine(file,"90%%");
		insertHeading(file,summaryT,1);
		//insertLine(file,"90%%");
		
		putSummary(data,"summary",file);

		fprintf(file,"\n</td>");										// insert data end tag
		fprintf(file,"\n</tr>");										// row end tag
		
		fprintf(file,"\n</table>  ");									// table end tag

		fprintf(file,"\n\t\t</center> \n \t </body> \n </html>");		// end html, body or center tags
	}

}
//------------------------------------------------------------------------------------------
void CopyFileToArray(const char* fileName, char* buffer)
{
	int counter = 0;
	FILE *file;
	file = fopen(fileName,"r");



		if(file != NULL)
        {
            while  ( (buffer[counter++] = fgetc( file ))  != EOF );   
            
			fclose( file );                           
        }

		else
		{
				 /* fopen returns 0, the NULL pointer, on failure */
			printf("file not found");
			exit(EXIT_FAILURE);
		}
}
//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
void getInfo(char* buffer, Info* i )
{
	CopyInfo(buffer,"name",i->name);
	CopyInfo(buffer,"phone",i->phone);
	CopyInfo(buffer,"email",i->eMail);
	CopyInfo(buffer,"adress",i->adress);
}
//------------------------------------------------------------------------------------------
