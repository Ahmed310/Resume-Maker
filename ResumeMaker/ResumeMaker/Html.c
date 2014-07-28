#include"Html.h"

void insertHeading(FILE* file, char* txt, int size)
{
	if(size == 1)
	{
		fprintf(file,"<h1>");
		fprintf(file,txt);
		fprintf(file,"</h1>");
	}
	else if(size == 2)
	{
		fprintf(file,"<h2>");
		fprintf(file,txt);
		fprintf(file,"</h2>");
	}
	else if(size == 3)
	{
		fprintf(file,"<h3>");
		fprintf(file,txt);
		fprintf(file,"</h3>");
	}
	else if(size == 4)
	{
		fprintf(file,"<h4>");
		fprintf(file,txt);
		fprintf(file,"</h4>");

	}
	else if(size == 5)
	{
		fprintf(file,"<h5>");
		fprintf(file,txt);
		fprintf(file,"</h5>");
	}
	
}



void insertLine(FILE* file, const char* width)
{
	fprintf(file,"<hr width = \" ");
	fprintf(file,width);
	fprintf(file,"\"> </hr>");
}

void newLine(FILE* file)
{
	fprintf(file,"<br>");
}

void boldText(FILE* file, char* txt)
{
	fputs("<b>",file);
	fputs(txt,file);
	fputs("</b>",file);
}

