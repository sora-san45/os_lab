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
    //sorting based on arrival time
    //bubble sort
    int swapped=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
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
    int current=0;
    int done=0;
    int check[n];
    for(int i=0;i<n;i++){
        check[i]=-1;
    }
    while(done<n){
            int visit=-1;
            int highestprio=-1;
            for(int i=0;i<n;i++){
                if(p[i].at<=current && check[i]!=1){
                    if(visit==-1){
                        visit=1;
                        highestprio=i;
                    }
                    if(p[i].prio<p[highestprio].prio){
                        highestprio=i;
                    }
                }
            }
            sum+=p[highestprio].bt;
            current=sum;
            p[highestprio].ct=sum;
            p[highestprio].tat=p[highestprio].ct-p[highestprio].at;
            total_tat+=p[highestprio].tat;
            p[highestprio].wt=p[highestprio].tat-p[highestprio].bt;
            total_wt+=p[highestprio].wt;
            check[highestprio]=1;
            done++;
    }
    printf("PROCESS \t AT \t Priority \t BT \t CT \t TAT \t\t WT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].prio,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    }
    printf("average tat: %f\n",(float)total_tat/n);
    printf("average wt: %f",(float)total_wt/n);
}