
#ifndef __FUNCTION_H
#define __FUNCTION_H

struct personalInfo ;                // structure containg personal information 
typedef struct personalInfo Info;	 // create alias for simplicity
int BufferSize(char *Buffer);		 // count characters from input file
void CopyFileToArray(const char* fileName, char* buffer);		// copy text file to array
void getInfo(char* buffer, Info* i );							// use CopyInfo function to featch information
static void putSections (char* str,FILE* file);				    // featch all section from data and insert them in html file
void TemplateA(char* data,const char* fileName);				// generate TemplateA in feature support more templates
static void CopyInfo(char* buffer, const char* token ,char* f);	// featch info from data base on key
#endif