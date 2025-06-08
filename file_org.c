#include<stdio.h>
#include<string.h>
struct{
  char dname[10],fname[10][10];
  int fcnt;
}dir;
int main(){
  char f[10];
  int ch,i;
  dir.fcnt=0;
  printf("enter name of the directory\n");
  scanf("%s",dir.dname);

  while(1){
    printf("\n1.create a file\n2.delete file\n3.search file\n4.display\n5.exit");
    printf("enter your choice");
    scanf("%d",&ch);

    switch(ch){
      case 1:
        printf("enter the name of the file\n");
        scanf("%s",dir.fname[dir.fcnt]);
        dir.fcnt++;
        break;
      
        case 2:
        printf("enter the file to delete\n");
        scanf("%s",f);
        for(i=0;i<dir.fcnt;i++){
          if(strcmp(f,dir.fname[i])==0){
            printf("file deleted\n");
            strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
            break;
          }
        }
        if(i==dir.fcnt){
          printf("file not found");
        }else{
          dir.fcnt--;
        }
        break;

        case 3:
        printf("enter the file to search\n");
        scanf("%s",f);
        for(i=0;i<dir.fcnt;i++){
          if(strcmp(f,dir.fname[i])==0){
            printf("file found\n");
            break;
          }
        }
        if(i==dir.fcnt){
          printf("file not found\n");
        }
        break;

        case 4:
        if(dir.fcnt==0){
          printf("directory is empty\n");
        }else{
          printf("files are:\n");
          for(i=0;i<dir.fcnt;i++){
            printf("%s",dir.fname[i]);
          }
        }
        break;
        case 5: return 0;
        default:printf("invalid input");
    }
  }
  return 1;
}