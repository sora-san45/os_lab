#include<stdio.h>
#include<unistd.h>
void main(){
    int pid=fork();
    if(pid==-1){
        printf("child not created");
    }
    if(pid==0){
        int pid1=getpid();
        printf("child process id: %d\n",pid1);
    }
    else{
        int pid2=getpid();
        printf("parent process id: %d\n",pid2);
    }
}