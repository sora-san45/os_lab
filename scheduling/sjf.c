#include <stdio.h>
struct process{
    int pid;
    int bt;
    int ct;
    int tat;
    int wt;
}p[20],temp;

void sjf(struct process *p,int n){
    //sorting based on burst time
    int swapped=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].bt>p[j+1].bt){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=p[i].bt;
        p[i].ct=sum;
        p[i].tat=p[i].ct;
        p[i].wt=p[i].tat-p[i].bt;
    }
}
void main(){
    int n;
    printf("Enter number of process :");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter bt: ");
        scanf("%d",&p[i].bt);
        p[i].pid=i+1;
    }
    sjf(p,n);
    printf("\nPID\tBT\tCT\tTAT\tWT");
    int total_tat=0;
    int total_wt=0;
    for(int i=0;i<n;i++){
        total_tat+=p[i].tat;
        total_wt+=p[i].wt;
        printf("\n%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("\nAverage TAT : %f\n",(float)total_tat/n);
    printf("Average WT : %f\n",(float)total_wt/n);
}