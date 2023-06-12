#include<stdio.h>
#include<dirent.h>
#include<string.h>
void main(int argc, char * argv[]){
    FILE * fp;
    char temp[200];
    fp=fopen(argv[1],"r");
    while (fgets(temp, sizeof(temp), fp) != NULL) {
        if (strstr(temp, argv[2]) != NULL) {
            printf("%s", temp);
        }
    }
    fclose(fp);
}