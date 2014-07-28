
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
			perror("file not found @ BufferSize");
			exit(EXIT_FAILURE);
		}
		 
		return counter;

}
//------------------------------------------------------------------------------------------
void TemplateA(char* data,const char* fileName)
{
	FILE *file;
	Info pInfo;
	file = fopen(fileName,"w");
	if(file == NULL)
	{
		perror("file not found @ TemplateA");
		exit(EXIT_FAILURE);
	}
	getInfo(data,&pInfo);
	
	if(file != NULL)
	{
		fprintf(file,"<html> \n \t <body>\n \t \t<center>");            // start html, body or center tags

		fprintf(file,"\n<table border=\"1\" width=\"800\" cellpadding = \"0\" cellspacing = \"0\">  ");         // table start tag

		fprintf(file,"\n<tr>");											// insert row
		fprintf(file,"\n<td width = \"500\" align = \"center\" >");		// insert data start tag

		
		insertHeading(file,pInfo.name,1);
		

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
		
		fprintf(file,"\n</td>");										// insert data end tag

		fprintf(file,"\n</tr>");										// row end tag
		
		
		fprintf(file,"\n<tr>");
		fprintf(file,"\n<td align = \"center\"  colspan = \"2\"  >");		                // insert data start tag

		putSection(data,"summary",file);
		putSection(data,"education",file);
		putSection(data,"job",file);
		putSection(data,"experties",file);
		


		fprintf(file,"\n</td>");										// insert data end tag
		fprintf(file,"\n</tr>");										// row end tag
		
		fprintf(file,"\n</table>  ");									// table end tag

		fprintf(file,"\n\t\t</center> \n \t </body> \n </html>");		// end html, body or center tags

		fclose( file );                           // close file
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
			perror("file not found @ CopyFileToArray");
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
//------------------------------------------------------------------------------------------
 static void putSection (char* buffer, const char* name, FILE* file)
{
	char* str;
	char tmp;
	char tmpBuf[64];
	char ok = 0;
	str = strstr(buffer,name);
	tmp = *str++;

	if(str != NULL)
	{
		CopyInfo(buffer,name,tmpBuf);
		insertHeading(file,tmpBuf,1);

		while((tmp = *str++) != '#')
		{

			if(tmp  == '{')
			{
				while(1)
				{
					tmp = *str++;
					if(tmp  == '}')
					{
						fputs("\n",file);
						newLine(file);
						break;
					}
					if(tmp  == '^')
					{
						fputs("<b>",file);
						while(1)
						{
							tmp = *str++;
							if(tmp == '^')
							{
								fputs("</b>",file);
								newLine(file);
								tmp = *str++;
								break;
							}
							fputc(tmp,file);
							//boldChar(file,tmp);
						}
					}

					fputc(tmp,file);
				}
			}
		}

		insertLine(file,"100%%");

	}
}
//------------------------------------------------------------------------------------------