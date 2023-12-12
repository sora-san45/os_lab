#include<stdio.h>
#include<math.h>
void scan(int a[],int done[],int head, int n){
    int start=head;
    int total=0;
    
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
    }
    scan(a,head,n);
}