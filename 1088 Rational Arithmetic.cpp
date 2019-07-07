#include<iostream>
#include<math.h>
using namespace std;
//分数的加减乘除
//参考柳神

long long a1,a2,b1,b2;

long long  gcd(long long a,long long b){
    return b == 0?abs(a):gcd(b,a%b);
}

void func(long long m,long long n){
    if(n == 0){
        cout<<"Inf"<<endl;
        return ;
    }
    if(m==0){
        cout<<"0";
        return;
    }
    long long k;
    long long g = gcd(m,n);
    int flag = (m<0&&n>0)||(n<0&&m>0)?0:1;
    m = abs(m/g);
    n = abs(n/g);
    k = m/n;
    if(k>0){
        m = m - k*n;
        if(m==0){
            if(flag==0)
                printf("(-%lld)",k);
            else
                printf("%lld",k);
        }
        else{
            if(flag==0)
                printf("(-%lld %lld/%lld)",k,m,n);
            else
                printf("%lld %lld/%lld",k,m,n);
        }
    }
    else{
        if(flag==0)
            printf("(-%lld/%lld)",m,n);
        else
            printf("%lld/%lld",m,n);
    }
}

int main(){
    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    func(a1,b1); cout<<" + ";func(a2,b2);cout<<" = ";func(a1*b2+a2*b1,b1*b2);cout<<endl;
    func(a1,b1); cout<<" - ";func(a2,b2);cout<<" = ";func(a1*b2-a2*b1,b1*b2);cout<<endl;
    func(a1,b1); cout<<" * ";func(a2,b2);cout<<" = ";func(a1*a2,b1*b2);cout<<endl;
    func(a1,b1); cout<<" / ";func(a2,b2);cout<<" = ";func(a1*b2,a2*b1);
    system("pause");
    return 0;

}