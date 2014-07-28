#ifndef __HTML_H
#define __HTML_H

#include<stdio.h>

void insertHeading(FILE* file, char* txt, int size);			// insert heading in html file
void newLine(FILE* file);										// insert new line in html file
void insertLine(FILE* file, const char* width);					// Draw horizonlat line persentage 0 - 100
void boldText(FILE* file, char* txt);						    // insert bold text in html file


#endif