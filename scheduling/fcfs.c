#include<stdio.h>
struct process{
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
}p[20],temp;

void main(){
    int n;
    printf("\nEnter number of processes : ");
    scanf("%d",&n);
    printf("\nEnter arrival time and burst time for each process : ");
    for(int i=0;i<n;i++){
        printf("\nEnter at : ");
        scanf("%d",&p[i].at);
        printf("\nEnter bt : ");
        scanf("%d",&p[i].bt);
    }
    //sorting with respect to arrival time
    int swapped=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                swapped=1;
                temp = p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
        if(swapped==0){
            break;
        }
    }

    int sum=0;
    int total_wt=0;
    int total_tat=0;
    for(int i=0;i<n;i++){
        while(sum<p[i].at){
            sum++;
        }
        sum+=p[i].bt;
        p[i].ct=sum;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        total_tat+=p[i].tat;
        total_wt+=p[i].wt;
    }
    printf("Pno\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("Total turn around time : %f",(float)total_tat/n);
    printf("\nTotal waiting time : %f",(float)total_wt/n);
}
