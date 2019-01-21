/* htmllib.c
 * HTML common library functions for the CGI programs. */
#include <stdio.h>
#include <string.h>
#include "htmllib.h"
void htmlHeader(char *title) {
    printf("Content-type: text/html\n\n<html><head><title>%s</title></head>",
           title);
}
void htmlBody() {
    printf("<body>");
}
void htmlFooter() {
    printf("</body></html>");
}
void addTitleElement(char *title) {
    printf("<h1>%s</h1>", title);
}
void printInputTextInt(char* name, char* var, int default_value) {
    char buffer[20];
    snprintf(buffer, 20, "%d", default_value);
    printInputText(name,var,buffer);
}
void printInputText(char* name, char* var, char* default_value) {
    printf("<td><b>%s:</b></td>\n", name);
    printf("<td><input type='text' name='%s' style='width: 70px;' value='%s'/></td>\n",
           var, default_value);
}
void printInputSelect(char* name, char* var, char* default_value, char** values) {
    printf("<td><b>%s:</b></td>\n", name);
    printf("<td><select name='%s'>\n", var);
    if (values!=NULL) {
        char* value;
        int i=0;
        while ((value=values[i])!=NULL) {
            printf("<option value='%s'", value);
            if (strcmp(value,default_value)==0) {
                printf(" selected");
            }
            printf(">");
            ++i;
            value = values[i];
            if (value!=NULL) {
                printf("%s", value);
                ++i;
            }
            printf("</option>\n");
        }
    }
    printf("</select></td>\n");
}
void printError(char* msg)
{
    printf("<br><font color='red'>%s</font><br>", msg);
}
