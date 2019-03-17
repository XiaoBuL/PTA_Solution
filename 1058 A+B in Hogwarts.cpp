#include<iostream>
using namespace std;

//没啥好说的，送分

int main(){
    int g1,g2,g;
    int s1,s2,k1,k2,s,k;
    scanf("%d.%d.%d",&g1,&s1,&k1);
    scanf("%d.%d.%d",&g2,&s2,&k2);
    k = (k1+k2)%29;
    int carry = (k1+k2)/29;
    s = (s1+s2+carry) %17;
    carry = (s1+s2+carry)/17;
    g = g1+g2 +carry;
    printf("%d.%d.%d\n",g,s,k);
    system("pause");
    return 0;
}