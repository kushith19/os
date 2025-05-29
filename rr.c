#include<stdio.h>
int main(){
    int n,p[10],i,bt[10],wt[10],tat[10],rt[10],quantum,time=0,remain; 
float twt=0,ttat=0;
printf("enter the number of process\n");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("enter the burst time\n");
    scanf("%d",&bt[i]);
    rt[i]=bt[i];
    p[i]=i+1;
}
remain=n;
printf("enter quantum");
scanf("%d",&quantum);

while(remain){
    for(i=0;i<n;i++){
        if(rt[i]>0){
            if(rt[i]>quantum){
                time=time+quantum;
                rt[i]=rt[i]-quantum;
            }else{
                time=time+rt[i];
                tat[i]=time;
                rt[i]=0;
                remain--;
            }
        }
    }
}

for(i=0;i<n;i++){
    wt[i]=tat[i]-bt[i];
    twt+=wt[i];
}
for(i=0;i<n;i++){
    ttat+=tat[i];
}

printf("\nProcess\t bt\t\t  wt\t\t tat\t\t \n ");
for(i=0;i<n;i++){
    printf("\n %d\t %d\t\t %d\t\t %d\t\t\n",p[i],bt[i],wt[i],tat[i]);
}

printf("average waiting time:%.2f",(float)twt/n);
printf("average turn around  time:%.2f",(float)ttat/n);


}