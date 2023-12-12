#include<stdio.h>
void bestfit(int process[],int block[],int n, int m){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++){
        int best=-1;
        for(int j=0;j<m;j++){
            if(block[j]>=process[i] && (best==-1||block[j]<block[best])){
                best=j;
            }
        }
        if(best!=-1){
            allocation[i]=best+1;
            block[best]-=process[i];
        }
    }
    printf("process  process_size  block_allocated\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t",i+1,process[i]);
        if(allocation[i]==-1){
            printf("Not allocated\n");
        }else{
            printf("%d\n",allocation[i]);
        }
    }
}
void main(){
    int n,m;
    printf("\nEnter number of processes :");
    scanf("%d",&n);
    printf("\nEnter number of blocks :");
    scanf("%d",&m);
    int process[n],block[m];
    printf("\n Enter processes :");
    for(int i=0;i<n;i++){
        scanf("%d",&process[i]);
    }
    printf("\n Enter blocks :");
    for(int i=0;i<m;i++){
        scanf("%d",&block[i]);
    }
    bestfit(process,block,n,m);
}