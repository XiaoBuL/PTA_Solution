#include<iostream>
#include<math.h>
using namespace std;

int IsPrime(int n){
    int i;
    if(n==0||n==1)
        return 0;
    if(n==2)
        return 1;
    for(i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

void judge(int n,int d){
    int sum = 0;
    int temp = n;
    while(temp!=0){
        sum = sum*d + temp%d;
        temp/=d;
    }
    if(IsPrime(n)&&IsPrime(sum))
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
}

int main(){
    int n,d;
    while(1){
        cin>>n;
        if(n<0)
            break;
        cin>>d;
        judge(n,d);
    }    
}