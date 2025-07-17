#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
    int ret;
    if(argc!=3){
        printf("./a.out sig pid");
        return 0;
    }
    
    ret=kill(atoi(argv[2]),atoi(argv[1]));
    if(ret==-1)
        printf("kill failed");
}