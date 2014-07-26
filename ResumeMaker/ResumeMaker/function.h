
#ifndef __FUNCTION_H
#define __FUNCTION_H

struct personalInfo ;                // personal information
typedef struct personalInfo Info;
int BufferSize(char *Buffer);
void CopyFileToArray(const char* fileName, char* buffer);
void getInfo(char* buffer, Info* i );
void TemplateA(char* data,const char* fileName);
#endif