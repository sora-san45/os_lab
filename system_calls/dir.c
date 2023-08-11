#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
struct dirent * dptr;
void main(){
char buff[100];
DIR * dirp;
printf("Enter directory name\n");
scanf("%s",&buff);
if((dirp=opendir(buff))==NULL){
printf("directory does not exist\n");
exit(1);
}
while(dptr=readdir(dirp)){
printf("%s\n",dptr->d_name);
}
closedir(dirp);
}