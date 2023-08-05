#include<stdio.h>
#include<math.h>
void sstf(int a[],int done[],int head, int n){
    int start=head;
    int total=0;
    for(int i=0;i<n;i++){
        int min=fabs(start-a[0]);
        int min_pos=0;
        for(int j=1;j<n;j++){
            int sum=fabs(start-a[j]);
            if(sum<min && !done[j]){
                min=sum;
                min_pos=j;
            }
        }
        total+=min;
        start=a[min_pos];
        done[min_pos]=1;
    }
    printf("Total head movement: %d",total);
}
void main(){
    int n,head;
    printf("\nEnter number of requests");
    scanf("%d",&n);
    printf("\nEnter head position");
    int a[n];
    int done[n];
    scanf("%d",&head);
    printf("\nEnter requests:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        done[i]=0;
    }
    sstf(a,done,head,n);
}