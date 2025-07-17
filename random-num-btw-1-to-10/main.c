#include<stdio.h>

int main(){
    srand(getpid());
    for(int i=0;i<5;i++){
        printf("%d\n",rand()%10+1);
    }
    for(int i=0;i<5;i++){
        printf("%d\n",rand()%1000+1);
    }
}