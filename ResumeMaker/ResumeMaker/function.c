
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
static void putInfo(FILE* file, Info pInfo)			// only use in this file
{
		fprintf(file,"<p>");
		fprintf(file,"Contact No.: ");
		fprintf(file,pInfo.phone);
		fprintf(file,"</p>");
//		newLine(file);

		fprintf(file,"<p>");
		fprintf(file,"E-mail: ");
		fprintf(file,pInfo.eMail);
		fprintf(file,"</p>");
//		newLine(file);
		
		fprintf(file,"<p>");
		fprintf(file,"Address: ");
		fprintf(file,pInfo.adress);
		fprintf(file,"</p>");
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
	getInfo(data,&pInfo);							// featch info 
	
	if(file != NULL)
	{
		fprintf(file,"<html> \n \t <body>\n \t \t<center>");            // start html, body or center tags

		fprintf(file,"\n<table border=\"1\" width=\"800\" cellpadding = \"0\" cellspacing = \"0\">  ");         // table start tag

		fprintf(file,"\n<tr>");											// insert row
		fprintf(file,"\n<td width = \"500\" align = \"center\" >");		// insert data start tag

		
		insertHeading(file,pInfo.name,1);								// insert name as Heading
		

		fprintf(file,"\n</td>");										// insert data end tag

		fprintf(file,"\n<td width = \"300\" valign = \"top\"  rowspan = \"2\" bgcolor=#36A3FB>");		// insert data start tag
		
		putInfo(file,pInfo);

		fprintf(file,"\n</td>");										// insert data end tag

		fprintf(file,"\n</tr>");										// row end tag
		
		
		fprintf(file,"\n<tr>");
		fprintf(file,"\n<td align = \"left\"  >");		                // insert data start tag

		putSections(data,file);
	
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
            while  ( (buffer[counter++] = fgetc( file ))  != '~' );   
            
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
 static void putSections (char* str,FILE* file)
{
	char tmp;
	tmp = *str;

	if(str != NULL)
	{
		while((tmp = *str++) != '~')                     // loop till end of file
		{
			while((tmp = *str++) != '#')				 // loop till new section
			{

				if(tmp == '[')							 
				{
					insertLine(file,"100%%");
					fputs("<h1>",file);
					while(1)							  // print Heading of Section
					{
						tmp = *str++;
						if(tmp == ']')
						{
							fputs("</h1>",file);
							tmp = *str++;
							break;
						}
						fputc(tmp,file);
					}
				}

				if(tmp  == '{')								// loop and print decription of section
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
						if(tmp  == '^')						// check for bold text and insert it
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
							}
						}

						fputc(tmp,file);
					}
				}
			}
		}
		insertLine(file,"100%%");

	}
}
//------------------------------------------------------------------------------------------