#include<stdio.h>
#include<string.h>
struct directory{
    char dname[10];
    char fname[10][10];
    int fcnt;
}dir;
void main(){
    int ch,i;
    char f[10];
    printf("Enter directory name : ");
    scanf("%s",dir.dname);
    while(1){
        printf("\n1.Create file\n2.Delete file\n3.Search file\n4.Display files\n5. Exit");
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        if(ch==1){
            printf("\nEnter file name : ");
            scanf("%s",dir.fname[dir.fcnt]);
            dir.fcnt++;
        }else if(ch==2){
            printf("\nEnter file to be deleted : ");
            scanf("%s",f);
            for(i=0;i<dir.fcnt;i++){
                if(strcmp(f,dir.fname[i])==0){
                    strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
                    dir.fcnt--;
                    break;
                }
            }
            if(i==dir.fcnt){
                printf("\nfile not found");
            }
        }else if(ch==3){
            printf("\nEnter file to be searched : ");
            scanf("%s",f);
            for(i=0;i<dir.fcnt;i++){
                if(strcmp(f,dir.fname[i])==0){
                    printf("\nfile %s found",f);
                    break;
                }
            }
            if(i==dir.fcnt){
                printf("\nfile not found");
            }
        }else if(ch==4){
            if(dir.fcnt==0){
                printf("\nEmpty directory");
                continue;
            }
            for(i=0;i<dir.fcnt;i++){
                printf("%s\n",dir.fname[i]);
            }
        }else{
            break;
        }
    }
}