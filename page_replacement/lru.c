#include<stdio.h>
void lru(int pages[],int table[],int f, int n){
    int pagefaults=0;
    int hits=0;
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
            int num1=pages[i-1];
            int num2=-1;
            for(int m=i-2;m>=0;m--){
                if(num1!=pages[m]){
                    if(num2==-1){
                        num2=pages[m];
                    }
                    else if(num2!=pages[m]){
                        int num3=pages[m];
                        for (int k = 0; k < f; k++) {
                            if (table[k] == num3) {
                                table[k] = pages[i];
                                pagefaults++;
                                break;
                            }
                        }
                        break;
                    }
                }
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
    lru(pages,table,f,n);
}