#include<stdio.h>
#define MAX_RESOURCES 10
#define MAX_PROCESSES 20

int main(){
    int alloc[MAX_PROCESSES][MAX_RESOURCES],request[MAX_PROCESSES][MAX_RESOURCES];
    int avail[MAX_RESOURCES],total[MAX_RESOURCES],work[MAX_RESOURCES];
    int mark[MAX_PROCESSES]={0};
    int np,nr;

    printf("enter the number of resources");
    scanf("%d",&nr);
    printf("enter number of process");
    scanf("%d",&np);

    for(int i=0;i<nr;i++){
        printf("total amount of respurces R%d",i+1);
        scanf("%d",&total[i]);
    }

    printf("enter the request matrix\n");
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            scanf("%d",&request[i][j]);
        }
    }

    printf("enter the allocation matrix\n");
     for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            scanf("%d",&alloc[i][j]);
        }
    }

    for(int j=0;j<nr;j++){
        avail[j]=total[j];
        for(int i=0;i<np;i++){
            avail[j]-=alloc[i][j];
        }
        work[j]=avail[j];
    }

    for(int i=0;i<np;i++){
        int zeroalloc=1;
        for(int j=0;j<nr;j++){
            if(alloc[i][j]!=0){
                zeroalloc=0;
                break;
            }
        }
        if(zeroalloc) mark[i]=1;
    }

    for(int i=0;i<np;i++){
        if(!mark[i]){
            int canproceed=1;
            for(int j=0;j<nr;j++){
                if(request[i][j]>work[j]){
                    canproceed=0;
                    break;
                }
            }
            if(canproceed){
                mark[i]=1;
                for(int j=0;j<nr;j++){
                    work[j]+=alloc[i][j];
                }
            }
        }
    }

    int deadlock=0;
    for(int i=0;i<np;i++){
        if(!mark[i]){
            deadlock=1;
            break;
        }
    }

    if(deadlock){
        printf("\nDeadlock is present\n");
    }else{
        printf("\nDeadlock is not present");
    }

    return 0;
    

}
