#include<stdio.h>
#include<math.h>
void fcfs(int a[],int head,int n){
    int total=0;
    int start=head;
    for(int i=0;i<n;i++){
        total+=fabs(a[i]-start);
        start=a[i];
    }
    printf("Total head movement : %d",total);
}
void main(){
    int n,head;
    printf("\nEnter number of requests");
    scanf("%d",&n);
    printf("\nEnter head position");
    int a[n];
    scanf("%d",&head);
    printf("\nEnter requests:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    fcfs(a,head,n);
}