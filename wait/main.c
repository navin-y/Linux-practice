#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid=fork();
    
    if(pid==0){
        printf("Child process on-going\n");
        sleep(2);
        printf("Child process exiting..\n");
    }
    else{
        printf("Parent process waiting for child to exit\n");
        wait(NULL);
        printf("Child exiting so parent also exited");
    }
}