#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    if(fork()==0){
        printf("child 1 pid=%d ppid=%d\n",getpid(),getppid());
        //exit(0);
    }
    else{
        if(fork()==0){
            printf("child 2 pid=%d ppid=%d\n",getpid(),getppid());
            //exit(0);
        }
        else{
            if(fork()==0){
                printf("child 3 pid=%d ppid=%d\n",getpid(),getppid());
            }
            else{
                sleep(1);
                printf("parent id=%d\n",getpid());
            }
        }
    }
}
