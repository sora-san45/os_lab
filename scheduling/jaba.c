#include<stdio.h>
struct process{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
}p[10];
struct grantt{
    int id;
    int end;
}g[50];
void srtf(struct process * p,int n){
    int done=0;
    int current=0;
    int index=0;
    int total_tat=0;
    int total_wt=0;
    while(done<n){
        int job=-1;
        int shortest=99999;
        for(int i=0;i<n;i++){
            if(p[i].at<=current && p[i].rt>0 && p[i].rt<shortest){
                job=i;
                shortest=p[i].rt;
            }
        }
        if(job==-1){
            current++;
        }
        else{
            p[job].rt--;
            current++;
        }
        if(p[job].rt==0){
            p[job].ct=current;
            p[job].tat=p[job].ct-p[job].at;
            total_tat+=p[job].tat;
            p[job].wt=p[job].tat-p[job].bt;
            total_wt+=p[job].wt;
            done++;
        }
        if(index==0){
            g[index++].id=p[job].id;
        }
        if(g[index-1].id!=p[job].id){
            g[index].id=p[job].id;
            g[index-1].end=current;
            index++;
        }
    }
    g[index-1].end=current;
     printf("Pno\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("Average tat : %f\n",(float)total_tat/n);
    printf("Average WT : %f\n",(float)total_wt/n);
    printf("|");
    for(int i=0;i<index;i++){
        printf("  P%d  |",g[i].id);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        if(p[i].id==g[0].id){
            printf("%d",p[i].at);
            break;
        }
    }
    
    for(int i=0;i<index;i++){
       if(g[index].end>9){
         printf("     %d",g[i].end);
       }else{
         printf("      %d",g[i].end);
       }
    }

}
void main(){
    int n;
    printf("Enter number of processes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        printf("\nEnter at and bt: ");
        scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].rt=p[i].bt;
    }
    srtf(p,n);
}