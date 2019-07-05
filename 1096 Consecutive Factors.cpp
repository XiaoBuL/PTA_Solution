#include<iostream>
#include<math.h>
using namespace std;

//运行超时和输出超限
//long int 必须定义在外面？？？

long int num,factor,i;
long int n;


int main(){
    cin>>n;
    num = 0;
    for(i=2;i<=sqrt(n)+1;i++){
        int index = i;
        int count = 0;
        int f = i;
        while(n%f==0){
            count++;
            index++;
            f *= index; //这里有一个小坑
        }   
        if(num<count){
            num = count;
            factor = i;
        }
    }
    if(num!=0){
        cout<<num<<endl;
        for(i=0;i<num-1;i++)
            cout<<(factor+i)<<"*";
        cout<<(factor+i)<<endl;
    }
    else{
        cout<<1<<endl;
        cout<<n;
    }
    system("pause");
    return 0;
}