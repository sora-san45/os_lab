#include<stdio.h>
struct process{
    int id;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
}p[20],temp;
struct grant{
    int id;
    int start;
}g[100];
void main(){
    int n;
    printf("Enter number of processes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        printf("\n Enter at : ");
        scanf("%d",&p[i].at);
        printf("\nEnter bt : ");
        scanf("%d",&p[i].bt);
        p[i].rt=p[i].bt;
    }

    int current=0;
    int done=0;
    int m=0;
    int index=-1;
    int total_tat=0;
    int total_wt=0;
    while(done<n){
        int shortest=9999;
        int shortestjob=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=current && p[i].rt<shortest && p[i].rt>0){
                shortest=p[i].rt;
                shortestjob=i;
                g[++index].start=current;
                m++;
                g[index].id=p[shortestjob].id;
            }
        }
        if(shortestjob==-1){
            current++;
        }
        else{
            p[shortestjob].rt--;
            current++;
        }
        if(p[shortestjob].rt==0){
            p[shortestjob].ct=current;
            p[shortestjob].tat=p[shortestjob].ct-p[shortestjob].at;
            p[shortestjob].wt=p[shortestjob].tat-p[shortestjob].bt;
            total_tat+=p[shortestjob].tat;
            total_wt+=p[shortestjob].wt;
            done++;
        }
    }
    printf("Pno\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("Average tat : %f\n",(float)total_tat/n);
    printf("Average WT : %f\n",(float)total_wt/n);
    printf("|");
    for(int i=0;i<m;i++){
        printf("%d P%d |",g[i].start,g[i].id);
    }
}