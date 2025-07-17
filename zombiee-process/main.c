#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t pid=fork();
    
    if(pid==0){
        printf("Child: Running and exiting..\n");
        exit(0);
    }else{
        printf("Parent: Sleeping, not calling wait()\n");
        sleep(30);//During this time child is ZOMBIEE
    }
}