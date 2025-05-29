#include<stdio.h>
int main(){
    int n, p,f[10],pos=0,i,j,k;
   int fault=0,hit;

   printf("enter frame size:\n");
   scanf("%d",&n);

   printf("enter page reference :\n");
   scanf("%d",&p);

   int page[10]={1,2,3,4,1,2,5,1,2};

   for(i=0;i<n;i++){
    f[i]=-1;
   }
   

   for(i=0;i<p;i++){
    hit=0;
    for(j=0;j<n;j++){
        if(f[j]==page[i]){
            hit=1;
            break;
        }
    }
     if(hit==0){
        f[pos]=page[i];
        pos=(pos+1)%n;
        fault++;
   }
   printf("frames:\n");
   for(k=0;k<n;k++){
    if(f[k]!=-1) printf("%d\t",f[k]);
    else printf("-");
   }
   printf("\n");
   }

   printf("total page faults:%d\n",fault);
   return 0;
  

}