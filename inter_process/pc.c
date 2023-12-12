#include<stdio.h>
#include<stdlib.h>
int full=0;
int empty=4;
int mutex=1;
int num=0;
int wait(int s){
    while(s<=0);
    return --s;
}
int signal(int s){
    return ++s;
}
void producer(){
    mutex=wait(mutex);
    full=signal(full);
    printf("produces item %d",++num);
    empty=wait(empty);
    mutex=signal(mutex);
}
void consumer(){
    mutex=wait(mutex);
    empty=signal(empty);
    printf("consumes item %d",num--);
    full=wait(full);
    mutex=signal(mutex);
}
void main(){
    while(1){
        printf("\nEnter choice :");
        printf("\n1.Produce");
        printf("\n2.Consume");
        printf("\n3.Exit");
        int n;
        scanf("%d",&n);
        switch(n){
            case 1:
            if(mutex==1 && empty!=0)
            producer();
            else
            printf("Buffer full\n");
            break;
            case 2:
            if(mutex==1 && full!=0)
            consumer();
            else
            printf("Buffer empty\n");
            break;
            case 3:
            exit(1);
        }
    }
}