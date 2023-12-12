#include<stdio.h>
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
    printf("\nEnter number of processes :");
    int n;
    scanf("%d",&n);
    int check[n];
    printf("\nEnter processes : ");
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        check[i]=0;
        printf("\nEnter at bt prio : ");
        scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].prio);
    }
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
    int total_tat=0;
    int total_wt=0;
    int sum=0;
    int done=0;
    while(done<n){
        int high=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=sum && (high==-1 || p[i].prio<p[high].prio) && check[i]==0){
                high=i;
            }
        }
        if(high==-1){
            sum++;
        }
        sum+=p[high].bt;
        check[high]=1;
        p[high].ct=sum;
        p[high].tat=p[high].ct-p[high].at;
        total_tat+=p[high].tat;
        p[high].wt=p[high].tat-p[high].bt;
        total_wt+=p[high].wt;
        done++;
    }
    printf("Pno\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("total tat : %f",(float)total_tat/n);
    printf("\ntotal wt : %f",(float)total_wt/n);
}
