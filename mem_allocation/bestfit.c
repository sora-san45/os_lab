#include <stdio.h>
void main(){
    int pno,bno;
    printf("enter number of processes:");
    scanf("%d",&pno);
    printf("enter number of blocks:");
    scanf("%d",&bno);
    int process[pno], block[bno];
    printf("Enter process sizes: \n");
    int allocated[pno];
    for(int i=0;i<pno;i++){
        allocated[i]=-1;
        scanf("%d",&process[i]);
    }
    printf("enter block sizes:\n");
    for(int i=0;i<bno;i++){
        scanf("%d",&block[i]);
    }
    for(int i=0;i<pno;i++){
        int bestblock=-1;
        for(int j=0;j<bno;j++){
            if(block[j]>=process[i]){
                if(block[j]<block[bestblock] || bestblock==-1){
                    bestblock=j;
                }
            }
        }
        if(bestblock!=-1){
            allocated[i]=bestblock;
            block[bestblock]-=process[i];
        }
    }
    printf("Process id\t\t Process size \t\t Block allotted\n");
    for(int i=0;i<pno;i++){
        if(allocated[i]==-1){
            printf("%d\t\t%d\t\t%s\n",i+1,process[i],"not allocated");
        }
        else{
            printf("%d\t\t%d\t\t%d\n",i+1,process[i],allocated[i]);
        }
    }
}