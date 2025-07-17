#include<iostream>
using namespace std;

int main(){
    int a[5];
    srand(10);
    for(int i=0;i<5;i++)
        a[i]=rand();
    for(int i=0;i<5;i++)
        cout<<a[i]<<endl;
}