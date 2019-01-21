/* htmllib.h */
#ifndef _HTMLLIB_H
#define _HTMLLIB_H
/* function prototypes */
void htmlHeader(char *title);
void htmlBody();
void htmlFooter();
void addTitleElement(char *title);
void printInputSelect(char* name, char* var, char* default_value, char** values);
void printInputText(char* name, char* var,char* default_value);
void printInputTextInt(char* name, char* var,int default_value);
void printError(char* msg);
#endif /* !_HTMLLIB_H*/
