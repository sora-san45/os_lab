#include <stdio.h>
void main(){
    struct process{
        int id;
        int at;
        int bt;
        int ct;
        int tat;
        int wt;
    }p[10],temp;
    int n;
    printf("Enter number of processes : \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p.id=i+1;
        printf("arrival time: ");
        scanf("%d",&p.at[i]);
        printf("burst time: ");
        scanf("%d",&p.bt[i]);
    }
    //sorting based on burst time
    //bubble sort
    int swapped=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].bt>p[j+1].bt){
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
    printf("PROCESS \t\t AT \t\t BT \t\t CT \t\t TAT \t\t WT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    }
    printf("average tat: %f\n",total_tat/n);
    printf("average wt: %f",total_wt/n);
}