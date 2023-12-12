#include<stdio.h>
void worstfit(int process[],int block[],int n,int m){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++){
        int worst=-1;
        for(int j=0;j<m;j++){
            if(block[j]>=process[i] && (worst==-1 || block[j]>block[worst])){
                worst=j;
            }
        }
        if(worst!=-1){
            allocation[i]=worst+1;
            block[worst]-=process[i];
        }
    }
    printf("Process  Process_size  Block_allocated\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t",i+1,process[i]);
        if(allocation[i]!=-1){
            printf("%d\n",allocation[i]);
        }
        else{
            printf("not allocated\n");
        }
    }
}
void main(){
    int n,m;
    printf("\n Enter number of processes :");
    scanf("%d",&n);
    printf("\n Enter number of blocks :");
    scanf("%d",&m);
    printf("\nEnter proceses : ");
    int process[n],block[m];
    for(int i=0;i<n;i++){
        scanf("%d",&process[i]);
    }
    printf("Enter blocks : ");
    for(int i=0;i<m;i++){
        scanf("%d",&block[i]);
    }
    worstfit(process,block,n,m);
}