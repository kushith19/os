 #include<stdio.h>
 #include<string.h>
 struct file
 {
    char name[20];
    int sb;
    int nob;
 }f[10];
 
 int main(){
    int i,j,n;
    char str[20];
    printf("enter the number of files\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("enter file name\n");
        scanf("%s",&f[i].name);
        printf("enter starting block number\n");
        scanf("%d",&f[i].sb);

        printf("enter nummber of blocks\n");
        scanf("%d",&f[i].nob);
    }

    printf("enter the file to search \n");
    scanf("%s",&str);

    for(i=0;i<n;i++){
        if(strcmp(str,f[i].name)==0)
        break;
    }
    if(i==n){
        printf("file not found");
    }else{
        printf("file name:%s\n",f[i].name);
        printf("starting block:%d\n",f[i].sb);
        printf("number of blocks:%d\n",f[i].nob);

        printf("block occupied:\n");
        for(j=0;j<f[i].nob;j++){
            printf("%d\t",f[i].sb+j);
        }
    }
    return 0;
 }