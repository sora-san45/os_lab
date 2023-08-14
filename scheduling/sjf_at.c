#include <stdio.h>
struct process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
}p[20],temp;

void sjf(struct process *p,int n){
    //sorting based on arrival time
    int swapped=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
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
    int done=0;
    int check[n];
    for(int i=0;i<n;i++){
        check[i]=0;
    }
    while(done<n){
        int low=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=sum && (p[i].bt<p[low].bt||low==-1) && check[i]!=1){
                low=i;
            }
        }
        sum+=p[low].bt;
        p[low].ct=sum;
        p[low].tat=p[low].ct-p[low].at;
        p[low].wt=p[low].tat-p[low].bt;
        check[low]=1;
        done++;
    }
}
void main(){
    int n;
    printf("Enter number of process :");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter at: ");
        scanf("%d",&p[i].at);
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