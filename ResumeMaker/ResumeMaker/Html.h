#ifndef __HTML_H
#define __HTML_H

#include<stdio.h>

void insertHeading(FILE* file, char* txt, int size);
void newLine(FILE* file);
void insertLine(FILE* file, const char* width);					// persentage 0 - 100
void boldText(FILE* file, char* txt);


#endif