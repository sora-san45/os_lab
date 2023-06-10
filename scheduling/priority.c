#include <stdio.h>
struct process{
        int id;
        int prio;
        int at;
        int bt;
        int ct;
        int tat;
        int wt;
    }p[20],temp;
void main(){
    int n;
    printf("Enter number of processes : \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        printf("arrival time: ");
        scanf("%d",&p[i].at);
        printf("priority: ");
        scanf("%d",&p[i].prio);
        printf("burst time: ");
        scanf("%d",&p[i].bt);
    }
    //sorting based on priority
    //bubble sort
    int swapped=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].prio>p[j+1].prio){
                swapped=1;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
        if(swapped==0){
            break;
        }
    }
    int sum=0;
    int total_tat=0;
    int total_wt=0;
    for(int i=0;i<n;i++){
        sum+=p[i].bt;
        p[i].ct=sum;
        p[i].tat=p[i].ct-p[i].at;
        total_tat+=p[i].tat;
        p[i].wt=p[i].tat-p[i].bt;
        total_wt+=p[i].wt;
    }
    printf("PROCESS \t\t AT \t\t Priority \t\t BT \t\t CT \t\t TAT \t\t WT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i].id,p[i].prio,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    }
    printf("average tat: %f\n",(float)total_tat/n);
    printf("average wt: %f",(float)total_wt/n);
}