/* cgi.c */
/* main function of sample CGI application */

#include <stdio.h>
#include <string.h>
#include "cgivars.h"
#include "htmllib.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int sys_res = 0;

//#define _HTML_OUTPUT

int read_gpio_center_to_txt() {
    // sys_res = system("gpio write 8 1");
    // sys_res = system("gpio write 9 1");
    // sys_res = system("gpio write 7 1");
    // sys_res = system("gpio write 3 1");
    // sys_res = system("gpio write 22 1");
    // sys_res = system("gpio write 23 1");
    // sys_res = system("gpio write 24 1");
    // sys_res = system("gpio write 25 1");

    FILE *fp;
    char path0[10], path1[10], path2[10], path3[10], path4[10], path5[10], path6[10], path7[10], path8[10];
    /* Open the command for reading. */
    fp = popen("gpio read 8", "r");
    if (fp == NULL) {
        cout << "Failed to run command\n";
        return 0;
    }
    /* Read the output a line at a time - output it. */
    while (fgets(path0, sizeof(path0)-1, fp) != NULL) {
        // cout << path0;
    }
    pclose(fp);

    /* Open the command for reading. */
    fp = popen("gpio read 9", "r");
    if (fp == NULL) {
        cout << "Failed to run command\n";
        return 0;
    }
    /* Read the output a line at a time - output it. */
    while (fgets(path1, sizeof(path0)-1, fp) != NULL) {
        // cout << path1;
    }
    pclose(fp);

    /* Open the command for reading. */
    fp = popen("gpio read 7", "r");
    if (fp == NULL) {
        cout << "Failed to run command\n";
        return 0;
    }
    /* Read the output a line at a time - output it. */
    while (fgets(path2, sizeof(path0)-1, fp) != NULL) {
        // cout << path2;
    }
    pclose(fp);

    /* Open the command for reading. */
    fp = popen("gpio read 3", "r");
    if (fp == NULL) {
        cout << "Failed to run command\n";
        return 0;
    }
    /* Read the output a line at a time - output it. */
    while (fgets(path3, sizeof(path0)-1, fp) != NULL) {
        // cout << path3;
    }
    pclose(fp);

    /* Open the command for reading. */
    fp = popen("gpio read 22", "r");
    if (fp == NULL) {
        cout << "Failed to run command\n";
        return 0;
    }
    /* Read the output a line at a time - output it. */
    while (fgets(path4, sizeof(path0)-1, fp) != NULL) {
        // cout << path4;
    }
    pclose(fp);

    /* Open the command for reading. */
    fp = popen("gpio read 23", "r");
    if (fp == NULL) {
        cout << "Failed to run command\n";
        return 0;
    }
    /* Read the output a line at a time - output it. */
    while (fgets(path5, sizeof(path0)-1, fp) != NULL) {
        // cout << path5;
    }
    pclose(fp);

    /* Open the command for reading. */
    fp = popen("gpio read 24", "r");
    if (fp == NULL) {
        cout << "Failed to run command\n";
        return 0;
    }
    /* Read the output a line at a time - output it. */
    while (fgets(path6, sizeof(path0)-1, fp) != NULL) {
        // cout << path6;
    }
    pclose(fp);

    /* Open the command for reading. */
    fp = popen("gpio read 25", "r");
    if (fp == NULL) {
        cout << "Failed to run command\n";
        return 0;
    }
    /* Read the output a line at a time - output it. */
    while (fgets(path7, sizeof(path0)-1, fp) != NULL) {
        cout << path7;
    }
    pclose(fp);

    /* Open the command for reading. */
    fp = popen("gpio read 21", "r");
    if (fp == NULL) {
        cout << "Failed to run command\n";
        return 0;
    }
    /* Read the output a line at a time - output it. */
    while (fgets(path8, sizeof(path0)-1, fp) != NULL) {
        // cout << path8;
    }
    pclose(fp);

    // path[1] = 0;
    fp = fopen("shift_center.txt", "w+");
    fprintf(fp, "%c,%c,%c,%c,%c,%c,%c,%c,%c,%c", path7[0], path6[0], path5[0], path4[0], path3[0], path2[0]
                                               , path1[0], path0[0], path8[0], path8[0]);
    fclose(fp);
    cout << "Done.\n";
    return 1;
}

int check_user_pass(string user, string pass) {
    string line;
    ifstream myfile;

    // htmlHeader("CGI Router Program");
    // htmlBody();
    // addTitleElement("CGI Raiwan Router Controller");
    // cout << "<p>Reports::\n";
    // cout << "<hr>\n";
    cout << "<br>\n";

    int found_user = 0, found_pass = 0;
    myfile.open("users.txt");
    while(getline(myfile, line)) {
        int i = line.find(",\"")+2;
        int j = line.find("\"", i);
        int ii = line.find(",\"", i)+2;
        int jj = line.find("\"", ii);
        // cout << i << ", " << j << "<br>\n";
        // cout << line.substr(i, j - i) << ", " << line.substr(ii, jj - ii) << "<br>\n";
        // cout << user << ", " << pass << "<br>\n";
        found_user = 0; found_pass = 0;
        if(line.compare(i, j - i, user) == 0) {found_user = 1; cout << "found user <br>\n";}
        if(line.compare(ii, jj - ii, pass) == 0) {found_pass = 1; cout << "found pass <br>\n";}
        if(found_user && found_pass) break;
    }
    myfile.close();

    if(found_user && found_pass){
        // ofstream outfile;
        // outfile.open ("username.txt");
        // outfile << user;
        // outfile.close();
        return 1;
    }
    return 0;
    // htmlFooter();
}

int main() {
    char **postvars = NULL; /* POST request data repository */
    char **getvars = NULL; /* GET request data repository */
    int form_method; /* POST = 1, GET = 0 */
    char buf_upload[50 * 1024];
    char *lenstr;
    long len;

    lenstr = getenv("CONTENT_TYPE");
    if(lenstr[0] == 'm' && lenstr[1] == 'u') {
        htmlHeader("CGI Router Program");
        htmlBody();
        addTitleElement("CGI Raiwan Router Controller");
        cout << "<p>Reports::\n";
        cout << "<hr>\n";
        cout << "<h1> REDIRECTING TO THE LOGIN PAGE ...\n";
        htmlFooter();
        cout << "<!DOCTYPE html><html><head><meta http-equiv='Refresh' content='0; url=/index.html' /></head><body></body></html>\r\n\r\n";

        lenstr = getenv("CONTENT_LENGTH");
        if(lenstr != NULL && sscanf(lenstr,"%ld",&len) == 1){
            //        fgets(buf_upload, len+1, stdin);
            fread(buf_upload, 1, len, stdin);

            // cout << "<p>Loaded.\n";
            // cout << "|" << buf_upload[string(buf_upload).find(" ", string(buf_upload).find("application/octet-stream"))+1] << "|" << "\n";
            // cout << string(buf_upload).find("application/octet-stream") << "\n";
            // cout << "<hr>\n";

            char file_name[30];
            int i = 0;
            int st_file_point = (string(buf_upload).find("filename=\"")) + 10;
            int en_file_point = (string(&buf_upload[st_file_point+1]).find(".")) + 2;
            for(i = st_file_point; i < (st_file_point+en_file_point); i++) {
                file_name[i-st_file_point] = buf_upload[i];
                // cout << buf_upload[i];
            }
            file_name[i-st_file_point] = 'z';
            file_name[i-st_file_point+1] = 'i';
            file_name[i-st_file_point+2] = 'p';
            file_name[i-st_file_point+3] = 0;

            // cout << "<hr>\n";

            int st_point = (string(buf_upload).find("application/octet-stream")) + 28;
            int en_point = len - 46; //(string(buf_upload).find("WebKitFormBoundary", 10)) - 2;
            //                    (string(&buf_upload[st_point]).find("WebKitFormBoundary")) : (int)len;
            // cout << st_point << ", \n";
            // cout << en_point << "\n";
            // cout << "<hr>\n";

            FILE *fp = fopen(file_name, "w+");
            for(i = st_point; i < (en_point); i++) {
                fprintf(fp, "%c", buf_upload[i]);
                // cout << buf_upload[i];
            }
            fclose(fp);

            char cmd[100];
            sprintf(cmd, "unzip -P raiwanraiwan %s &", file_name);
            sys_res = system(cmd);

            // sys_res = system("cp -f upload/home/* /home/raiwan/");
            // sys_res = system("cp -f upload/html/* /var/www/html/");
            // sys_res = system("cp -f upload/cgi/* /usr/lib/cgi-bin/");

            // FILE* fpt;
            // char buf[1024];

            // fpt = fopen("upload/cmd.txt", "r");
            // while (fgets(buf, sizeof(buf), fpt) != NULL)
            // {
            //     buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
            //     sprintf(cmd, "%s &", buf);
            //     sys_res = system(cmd);
            // }
            // fclose(fpt);

            string line;
            ifstream myfile;
            myfile.open("upload/cmd.txt");

            // if(!myfile.is_open()) {
            //     perror("Error open");
            //     exit(EXIT_FAILURE);
            // }
            while(getline(myfile, line)) {
                sys_res = system(line.c_str());
            }

            myfile.close();

            sys_res = system("cp -f upload/home/* /home/raiwan/");
            sys_res = system("cp -f upload/html/* /var/www/html/");
            sys_res = system("cp -f upload/cgi/* /usr/lib/cgi-bin/");
            sys_res = system("sudo chmod -R 777 /home/raiwan/");
            sys_res = system("sudo chmod -R 777 /var/www/html/");
            sys_res = system("sudo chmod -R 777 /usr/lib/cgi-bin/");
            sys_res = system("sudo chmod +x /usr/lib/cgi-bin/");

            return 0;
        }
    }
    else {
        form_method = getRequestMethod();
        if(form_method == POST) {
            getvars = getGETvars();
            postvars = getPOSTvars();
        } else if(form_method == GET) {
            getvars = getGETvars();
        }
#ifdef _HTML_OUTPUT
        htmlHeader("CGI Router Program");
        htmlBody();
        addTitleElement("CGI Raiwan Router Controller");
        cout << "<p>Reports::\n";
        cout << "<hr>\n";
        cout << "<p>Request method: " << (form_method == 1 ? "POST" : "GET") << "\n";
#endif


        if(form_method == POST) {
            if (strcmp(postvars[0], "type") == 0) {
                //            cout << "<p>type: " << postvars[1] << "\n";
                if (strcmp(postvars[1], "shell_command") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    FILE *fp;
                    char path[1035];
                    /* Open the command for reading. */
                    fp = popen(postvars[3], "r");
                    if (fp == NULL) {
                        cout << "Failed to run command\n";
                        return 0;
                    }
                    /* Read the output a line at a time - output it. */
                    while (fgets(path, sizeof(path)-1, fp) != NULL) {
                        cout << path;
                    }
                    pclose(fp);
                }
                else if (strcmp(postvars[1], "user_load") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    FILE *f = fopen("users.txt", "rb");
                    fseek(f, 0, SEEK_END);
                    long fsize = ftell(f);
                    fseek(f, 0, SEEK_SET);  //same as rewind(f);

                    char *string = (char *)malloc(fsize + 1);
                    fread(string, fsize, 1, f);
                    fclose(f);

                    cout << "[[";
                    for(int i = 1; i < fsize; i++) {
                        if(string[i] == '[') cout << ",";
                        cout << string[i];

                    }
                    cout << "]";
                }
                else if (strcmp(postvars[1], "user_add") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    FILE *fp = fopen("users.txt", "a+");
                    fprintf(fp, "[\"%s\",\"%s\",\"%s\",%s]\n", postvars[3], postvars[5], postvars[7], postvars[9]);
                    fclose(fp);
                }
                else if (strcmp(postvars[1], "user_remove") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    FILE* fp;
                    char buf[1024];

                    cout << postvars[3] << ", " << postvars[5] << ", " << postvars[7] << " ";

                    if ((fp = fopen("users.txt", "r")) == NULL)
                    {
                        cout << "users file open error!";
                        return 1;
                    }

                    FILE *fpt = fopen("users-tmp.txt", "w+");
                    while (fgets(buf, sizeof(buf), fp) != NULL)
                    {
                        buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
                        if(string(buf).find(postvars[3]) == 2 && buf[2 + strlen(postvars[3])] == '\"') continue;
                        else
                            fprintf(fpt, "%s\n", buf);
                    }
                    fclose(fpt);
                    fclose(fp);
                    sys_res = system("cp -f users-tmp.txt users.txt");
                    sys_res = system("rm -f users-tmp.txt");
                }
                else if (strcmp(postvars[1], "user_read_username") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    string line;
                    ifstream myfile;
                    myfile.open("username.txt");
                    while(getline(myfile, line)) {
                        cout << line;
                    }
                    myfile.close();
                }
                // else if (strcmp(postvars[1], "ip_status") == 0) {
                //     cout << "Content-Type: text/plain;\r\n\r\n";
                //     cout << "DHCP";
                // }
                else if (strcmp(postvars[1], "logout") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    FILE *fp;
                    fp = fopen("username.txt", "w+");
                    //fprintf(fp, "-");
                    fclose(fp);

                    cout << "127.0.0.1";
                }
                else if (strcmp(postvars[1], "gpio_load_descriptions") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    FILE *f = fopen("gpio_descriptions.txt", "rb");
                    fseek(f, 0, SEEK_END);
                    long fsize = ftell(f);
                    fseek(f, 0, SEEK_SET);  //same as rewind(f);

                    char *string = (char *)malloc(fsize + 1);
                    fread(string, fsize, 1, f);
                    fclose(f);

                    for(int i = 0; i < fsize; i++)
                        cout << string[i];
                }
                else if (strcmp(postvars[1], "gpio_write_descriptions") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    FILE *fp = fopen("gpio_descriptions.txt", "w+");
                    fprintf(fp, "%s", postvars[3]);
                    fclose(fp);
                }
                else if (strcmp(postvars[1], "gpio_load_status_center") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    FILE *f = fopen("shift_center.txt", "rb");
                    char buff[20];
                    fgets(buff, 20, (FILE*)f);
                    fclose(f);

                    cout << buff;
                }
                else if (strcmp(postvars[1], "gpio_load_status_left") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    FILE *f = fopen("shift_left.txt", "rb");
                    char buff[5];
                    fscanf(f, "%s", buff);
                    fclose(f);

                    cout << buff;
                }
                else if (strcmp(postvars[1], "gpio_load_status_right") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    FILE *f = fopen("shift_right.txt", "rb");
                    char buff[5];
                    fscanf(f, "%s", buff);
                    fclose(f);

                    cout << buff;
                }
                else if (strcmp(postvars[1], "gpio_controller") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    FILE *f = fopen("shift_right.txt", "rb");
                    char buff[5];
                    fscanf(f, "%s", buff);
                    int shift_r = atoi(buff);
                    fclose(f);

                    f = fopen("shift_left.txt", "rb");
                    fscanf(f, "%s", buff);
                    int shift_l = atoi(buff);
                    fclose(f);
                    
                    if(strcmp(postvars[3], "250") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0) {
                            sys_res = system("gpio write 8 1");
                            sys_res = system("gpio write 9 1");
                            sys_res = system("gpio write 7 1");
                            sys_res = system("gpio write 3 1");
                            sys_res = system("gpio write 22 1");
                            sys_res = system("gpio write 23 1");
                            sys_res = system("gpio write 24 1");
                            sys_res = system("gpio write 25 1");
                            sys_res = system(string("./shift_gpio.sh left 255 &").c_str());
                            sys_res = system(string("./shift_gpio.sh right 255 &").c_str());
                            FILE *fp = fopen("shift_left.txt", "w+");
                            fprintf(fp, "255");
                            fclose(fp);
                            fp = fopen("shift_right.txt", "w+");
                            fprintf(fp, "255");
                            fclose(fp);
                            fp = fopen("shift_center.txt", "w+");
                            fprintf(fp, "1,1,1,1,1,1,1,1,1,1");
                            fclose(fp);
                        }
                        else {
                            sys_res = system("gpio write 8 0");
                            sys_res = system("gpio write 9 0");
                            sys_res = system("gpio write 7 0");
                            sys_res = system("gpio write 3 0");
                            sys_res = system("gpio write 22 0");
                            sys_res = system("gpio write 23 0");
                            sys_res = system("gpio write 24 0");
                            sys_res = system("gpio write 25 0");
                            sys_res = system(string("./shift_gpio.sh left 0 &").c_str());
                            sys_res = system(string("./shift_gpio.sh right 0 &").c_str());
                            FILE *fp = fopen("shift_left.txt", "w+");
                            fprintf(fp, "0");
                            fclose(fp);
                            fp = fopen("shift_right.txt", "w+");
                            fprintf(fp, "0");
                            fclose(fp);
                            fp = fopen("shift_center.txt", "w+");
                            fprintf(fp, "0,0,0,0,0,0,0,0,0,0");
                            fclose(fp);
                        }
                        cout << "All " << postvars[5] << "\n";
                    }
                    else if(strcmp(postvars[3], "25") == 0) {
                        if(strcmp(postvars[5], "true") == 0)
                            sys_res = system("gpio write 21 1");
                        else
                            sys_res = system("gpio write 21 0");
                        read_gpio_center_to_txt();
                        cout << "16 " << postvars[5] << "\n";
                    }
                    else if(strcmp(postvars[3], "24") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b10000000 | shift_r);
                        else
                            sprintf(tmp_buff, "%d", 0b01111111 & shift_r);
                        sys_res = system(string(string("./shift_gpio.sh right ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_right.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "23") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b01000000 | shift_r);
                        else
                            sprintf(tmp_buff, "%d", 0b10111111 & shift_r);
                        sys_res = system(string(string("./shift_gpio.sh right ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_right.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "22") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b00100000 | shift_r);
                        else
                            sprintf(tmp_buff, "%d", 0b11011111 & shift_r);
                        sys_res = system(string(string("./shift_gpio.sh right ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_right.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "21") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b00010000 | shift_r);
                        else
                            sprintf(tmp_buff, "%d", 0b11101111 & shift_r);
                        sys_res = system(string(string("./shift_gpio.sh right ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_right.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "20") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b00001000 | shift_r);
                        else
                            sprintf(tmp_buff, "%d", 0b11110111 & shift_r);
                        sys_res = system(string(string("./shift_gpio.sh right ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_right.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "19") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b00000100 | shift_r);
                        else
                            sprintf(tmp_buff, "%d", 0b11111011 & shift_r);
                        sys_res = system(string(string("./shift_gpio.sh right ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_right.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "18") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b00000010 | shift_r);
                        else
                            sprintf(tmp_buff, "%d", 0b11111101 & shift_r);
                        sys_res = system(string(string("./shift_gpio.sh right ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_right.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "17") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b00000001 | shift_r);
                        else
                            sprintf(tmp_buff, "%d", 0b11111110 & shift_r);
                        sys_res = system(string(string("./shift_gpio.sh right ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_right.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "16") == 0) {
                        if(strcmp(postvars[5], "true") == 0)
                            sys_res = system("gpio write 8 1");
                        else
                            sys_res = system("gpio write 8 0");
                        read_gpio_center_to_txt();
                        cout << "16 " << postvars[5] << "\n";
                    }
                    else if(strcmp(postvars[3], "15") == 0) {
                        if(strcmp(postvars[5], "true") == 0)
                            sys_res = system("gpio write 9 1");
                        else
                            sys_res = system("gpio write 9 0");
                        read_gpio_center_to_txt();
                        cout << "16 " << postvars[5] << "\n";
                    }
                    else if(strcmp(postvars[3], "14") == 0) {
                        if(strcmp(postvars[5], "true") == 0)
                            sys_res = system("gpio write 7 1");
                        else
                            sys_res = system("gpio write 7 0");
                        read_gpio_center_to_txt();
                        cout << "16 " << postvars[5] << "\n";
                    }
                    else if(strcmp(postvars[3], "13") == 0) {
                        if(strcmp(postvars[5], "true") == 0)
                            sys_res = system("gpio write 3 1");
                        else
                            sys_res = system("gpio write 3 0");
                        read_gpio_center_to_txt();
                        cout << "16 " << postvars[5] << "\n";
                    }
                    else if(strcmp(postvars[3], "12") == 0) {
                        if(strcmp(postvars[5], "true") == 0)
                            sys_res = system("gpio write 22 1");
                        else
                            sys_res = system("gpio write 22 0");
                        read_gpio_center_to_txt();
                        cout << "16 " << postvars[5] << "\n";
                    }
                    else if(strcmp(postvars[3], "11") == 0) {
                        if(strcmp(postvars[5], "true") == 0)
                            sys_res = system("gpio write 23 1");
                        else
                            sys_res = system("gpio write 23 0");
                        read_gpio_center_to_txt();
                        cout << "16 " << postvars[5] << "\n";
                    }
                    else if(strcmp(postvars[3], "10") == 0) {
                        if(strcmp(postvars[5], "true") == 0)
                            sys_res = system("gpio write 24 1");
                        else
                            sys_res = system("gpio write 24 0");
                        read_gpio_center_to_txt();
                        cout << "16 " << postvars[5] << "\n";
                    }
                    else if(strcmp(postvars[3], "9") == 0) {
                        if(strcmp(postvars[5], "true") == 0)
                            sys_res = system("gpio write 25 1");
                        else
                            sys_res = system("gpio write 25 0");
                        read_gpio_center_to_txt();
                        cout << "16 " << postvars[5] << "\n";
                    }
                    else if(strcmp(postvars[3], "8") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b10000000 | shift_l);
                        else
                            sprintf(tmp_buff, "%d", 0b01111111 & shift_l);
                        sys_res = system(string(string("./shift_gpio.sh left ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_left.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "7") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b01000000 | shift_l);
                        else
                            sprintf(tmp_buff, "%d", 0b10111111 & shift_l);
                        sys_res = system(string(string("./shift_gpio.sh left ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_left.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "6") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b00100000 | shift_l);
                        else
                            sprintf(tmp_buff, "%d", 0b11011111 & shift_l);
                        sys_res = system(string(string("./shift_gpio.sh left ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_left.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "5") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b00010000 | shift_l);
                        else
                            sprintf(tmp_buff, "%d", 0b11101111 & shift_l);
                        sys_res = system(string(string("./shift_gpio.sh left ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_left.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "4") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b00001000 | shift_l);
                        else
                            sprintf(tmp_buff, "%d", 0b11110111 & shift_l);
                        sys_res = system(string(string("./shift_gpio.sh left ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_left.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "3") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b00000100 | shift_l);
                        else
                            sprintf(tmp_buff, "%d", 0b11111011 & shift_l);
                        sys_res = system(string(string("./shift_gpio.sh left ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_left.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "2") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b00000010 | shift_l);
                        else
                            sprintf(tmp_buff, "%d", 0b11111101 & shift_l);
                        sys_res = system(string(string("./shift_gpio.sh left ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_left.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    else if(strcmp(postvars[3], "1") == 0) {
                        char tmp_buff[5];
                        if(strcmp(postvars[5], "true") == 0)
                            sprintf(tmp_buff, "%d", 0b00000001 | shift_l);
                        else
                            sprintf(tmp_buff, "%d", 0b11111110 & shift_l);
                        sys_res = system(string(string("./shift_gpio.sh left ") + string(tmp_buff) + string(" &")).c_str());
                        FILE *fp = fopen("shift_left.txt", "w+");
                        fprintf(fp, "%s", tmp_buff);
                        fclose(fp);
                        cout << postvars[3] << ", " << postvars[5] << ", " << tmp_buff << "\n";
                    }
                    cout << postvars[3] << ", " << postvars[5];
                }
                else if (strcmp(postvars[1], "log_read") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    FILE *f = fopen("log.txt", "rb");
                    if(f == NULL) {
                        cout << "can't open file";
                        return 0;
                    }
                    fseek(f, 0, SEEK_END);
                    long fsize = ftell(f);
                    fseek(f, 0, SEEK_SET);  //same as rewind(f);

                    char *string = (char *)malloc(fsize + 1);
                    fread(string, fsize, 1, f);
                    fclose(f);

                    for(int i = 0; i < fsize; i++)
                        cout << string[i];
                    cout << "]";
                }
                else if (strcmp(postvars[1], "log_write") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    time_t mytime = time(NULL);
                    char * time_str = ctime(&mytime);
                    time_str[strlen(time_str)-1] = '\0';

                    FILE *fp;
                    fp = fopen("log.txt", "rb");
                    if(fp == NULL){
                        fp = fopen("log.txt", "w+");
                        fprintf(fp, "[[\"System\",\"%s\",\"Log File Created\"]\n", time_str);
                        fprintf(fp, ",[\"%s\",\"%s\",\"%s\"]\n", postvars[3], time_str, postvars[5]);
                        fclose(fp);
                    }
                    else {
                        fclose(fp);
                        fp = fopen("log.txt", "a+");
                        fprintf(fp, ",[\"%s\",\"%s\",\"%s\"]\n", postvars[3], time_str, postvars[5]);
                        fclose(fp);
                    }

                }
                else if (strcmp(postvars[1], "log_erase") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    time_t mytime = time(NULL);
                    char * time_str = ctime(&mytime);
                    time_str[strlen(time_str)-1] = '\0';

                    FILE *fp;
                    fp = fopen("log.txt", "w+");
                    fprintf(fp, "[[\"System\",\"%s\",\"Log File Created\"]\n", time_str);
                    fclose(fp);
                }
                else if (strcmp(postvars[1], "reset_factory") == 0) {
                    cout << "Content-Type: text/plain;\r\n\r\n";

                    system("cp -f /home/raiwan/users.txt /usr/lib/cgi-bin/");
                    system("cp -f /home/raiwan/gpio_descriptions.txt /usr/lib/cgi-bin/");
                    system("cp -f /home/raiwan/shift_center.txt /usr/lib/cgi-bin/");
                    system("cp -f /home/raiwan/shift_left.txt /usr/lib/cgi-bin/");
                    system("cp -f /home/raiwan/shift_right.txt /usr/lib/cgi-bin/");
                    system("sudo python /home/raiwan/python_gpio_init.py");
                    system("rm -f /usr/lib/cgi-bin/log.txt");
                    system("rm -f /usr/lib/cgi-bin/username.txt");
                    system("echo 'dhcp:192.168.2.2:24:192.168.2.1' > /home/raiwan/ip_log.txt");

                    system("sudo chmod -R 777 /home/raiwan/");
                    system("sudo chmod -R 777 /var/www/html/");
                    system("sudo chmod -R 777 /usr/lib/cgi-bin/");

                    system("nmcli connection delete uuid $(LC_ALL=C nmcli -f UUID,DEVICE connection show | grep eth0 | awk '{print $1}') >/dev/null 2>&1");
                    system("nmcli con add con-name \"Armbian ethernet\" type ethernet ifname eth0 >/dev/null 2>&1");
                    system("nmcli con up \"Armbian ethernet\" >/dev/null 2>&1");
                }
                else {
                    cout << "command is not defined! ignore message: " << postvars[1] << "\n";
                }
            }
            else if (strcmp(postvars[0], "username") == 0) {
                htmlHeader("CGI Router Program");
                htmlBody();
                addTitleElement("CGI Raiwan Router Controller");
                cout << "<p>Reports::\n";
                cout << "<hr>\n";
                cout << "<p>Request method: " << (form_method == 1 ? "POST" : "GET") << "\n";
                cout << "<p>username: " << postvars[1] << " password: " << postvars[3] << "\n";
                cout << "<h1> REDIRECTING TO THE MAIN PAGE ...\n";
                htmlFooter();
                if(check_user_pass(string(postvars[1]), string(postvars[3]))) {
                    // FILE *fp;
                    // fp = fopen("username.txt", "w+");
                    // fprintf(fp, "%s", postvars[1]);
                    // fclose(fp);

                    ofstream outfile;
                    outfile.open("username.txt");
                    outfile << postvars[1];
                    outfile.close();

                    cout << "<!DOCTYPE html><html><head><meta http-equiv='Refresh' content='0; url=/main.html' /></head><body></body></html>\r\n\r\n";
                    cleanUp(form_method, getvars, postvars);
                    fflush(stdout);
                    return 0;
                }
                else {
                    cout << "<!DOCTYPE html><html><head><meta http-equiv='Refresh' content='0; url=/index.html' /></head><body></body></html>\r\n\r\n";
                    cleanUp(form_method, getvars, postvars);
                    fflush(stdout);
                    return 0;
                }
            }
            else {
                cout << "<p>type is not defined! ignore message: " << postvars[0] << "\n";
            }
        }
#ifdef _HTML_OUTPUT
        htmlFooter();
#endif
        cleanUp(form_method, getvars, postvars);
        fflush(stdout);
    }
    return 0;
}
