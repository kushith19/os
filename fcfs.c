#include<stdio.h>
int main(){
    int n,i,bt[10],p[10],wt[10],tat[10];
    float avgwt=0,avgtat=0,wtsum=0,tatsum=0;

    printf("enter the no of processes");
    scanf("%d",&n);
    printf("enter the burst time");
    for(int i=0;i<n;i++){
        p[i]=i+1;
        scanf("%d",bt[i]);
    }
    wt[0]=0;
    for(int i=0;i<n;i++){
        wt[i+1]=wt[i]+bt[i];
        wtsum+=wt[i];
        tat[i]=wt[i]+bt[i];
        tatsum+=tat[i];
    }
}