#include<stdio.h>
void fifo(int pages[],int table[],int f, int n){
    int pagefaults=0;
    int hits=0;
    int turn=0;
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=0;j<f;j++){
            if(table[j]==-1){
                table[j]=pages[i];
                pagefaults++;
                break;
            }
            else if(table[j]!=pages[i]){
                s++;
            }
            else{
                hits++;
                break;
            }
        }
        if(s==f){
            table[turn++]=pages[i];
            pagefaults++;
            if(turn==3){
                turn=0;
            }
        }
    }
    printf("Page Faults %d Hits %d",pagefaults,hits);
}

void main(){
    int f;int n;
    printf("Enter number of frames :");
    scanf("%d",&f);
    int table[f];
    for(int i=0;i<f;i++){
        table[i]=-1;
    }
    printf("\nEnter number of pages :");
    scanf("%d",&n);
    int pages[n];
    printf("\n Enter page string :");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    fifo(pages,table,f,n);
}