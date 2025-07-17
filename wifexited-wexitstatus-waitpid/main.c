#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
    pid_t pid=fork();
    int status;
    
    if(pid==0){
        printf("Child: Running and exited with exit code 33\n");
        exit(33);
    }else{
        waitpid(pid,&status,0);
        if(WIFEXITED(status)){
            printf("Parent: Child exited normally with exit code: %d\n",WEXITSTATUS(status));    
        }else{
            printf("Parent: Child doesnt exited normally");   
        }
    }
}
