#include<stdio.h>
void firstfit(int process[],int block[],int n,int m){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(process[i]<=block[j]){
                block[j]-=process[i];
                allocation[i]=j+1;
                break;
            }
        }
    }
    printf("pno\tprocess size block allocated\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t",i+1,process[i]);
        if(allocation[i]==-1){
            printf("Not allocated\n");
        }
        else{
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
    printf("\nEnter processes :");
    for(int i=0;i<n;i++){
        scanf("%d",&process[i]);
    }
    printf("\nEnter blocks :");
    for(int i=0;i<m;i++){
        scanf("%d",&block[i]);
    }
    firstfit(process,block,n,m);
}