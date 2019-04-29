#include<iostream>
#include<math.h>
using namespace std;

//分数的相加减
//这题好难 是20分的题目嘛？？？
//柳神还是牛逼
//两个问题：输入格式的问题、求最大公约数


long long get(long long a,long long b){
    return b==0?abs(a):get(b,a%b);
}


int main(){
    long long n,a,b,suma=0,sumb =1,value;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%lld/%lld",&a,&b);
        value = get(a,b);
        a = a/ value;
        b = b / value;
        suma = a*sumb + suma *b;
        sumb = b*sumb;
        value = get(suma,sumb);
        sumb = sumb/value;
        suma = suma/value;
    }
    long long out = suma/sumb;
    suma = suma - (sumb*out);
    if(out!=0){
        printf("%lld",out);
        if(suma!=0) printf(" ");
    }
    if(suma!=0)
        printf("%lld/%lld",suma,sumb);
    if(out==0 && suma == 0)
        printf("0");
    system("pause");
    return 0;

}