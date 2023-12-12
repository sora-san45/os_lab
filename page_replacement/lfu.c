#include<stdio.h>
struct entry{
    int page;
    int freq;
}
void lfu(int n,int f,int pages[],struct entry table[]){
    int pagefaults=0;
    int hits=0;
    int turn=0;
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<f;j++){
            if(table[j].page==-1){
                pagefaults++;
                table[j].page=pages[i];
                table[j].freq=1;
                flag=1;
                break;
            }
            else if(table[j].page==pages[i]){
                table[j].freq++;
                hits++;
                break;
            }
        }
        if(flag==0){
            int minfreq
        }
    }
}
void main(){
    int f,n;
    printf("Enter number of frames : ");
    scanf("%d",&f);
    printf("\nEnter number of pages : ");
    scanf("%d",&n);
    int pages[n],struct entry table[f];
    printf("\nEnter pages : ");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    for(int i=0;i<f;i++){
        table[i].page=-1;
        table[i].freq=0;
    }
    lfu(f,n,pages,table);
}