#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>
void main(){
    char buff[100];
    void * shared_mem;
    int shmid;
    shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);
    shared_mem=shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_mem);
    printf("Enter a string:");
    fgets(buff,sizeof(buff),stdin);
    strcpy(shared_mem,buff);
    printf("You copied %s",(char *)shared_mem);
}