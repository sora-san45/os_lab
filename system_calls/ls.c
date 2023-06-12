#include<stdio.h>
#include<dirent.h>
void main(int argc, char * args[]){
    DIR * dirp;
    struct dirent *link;
    dirp=opendir(args[1]);
    while((link=readdir(dirp))!=NULL){
        printf("%s\n",link->d_name);
    }
}