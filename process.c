#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    pid_t pid;
    pid=fork();

    if(pid<0){
        printf("fork has failed\n");
    }else if(pid==0){
        printf("child pid %d\n",getpid());
    }else{
        printf("Parent pid %d",getpid());
        sleep(0);
        printf("parent is exiting");
    }
    return 0;

}