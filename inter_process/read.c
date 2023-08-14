#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>
void main(){
    int shmid;
    void * shared_mem;
    shmid=shmget((key_t)1122,1024,0666);
    shared_mem=shmat(shmid,NULL,0);
    printf("process attached at %p \n",shared_mem);
    printf("Info is : %s",(char *)shared_mem);
}