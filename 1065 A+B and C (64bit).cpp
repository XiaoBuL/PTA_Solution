#include<iostream>
using namespace std;


//这题有点坑，要考虑到溢出的情况

int main(){
    long long a,b,c;
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a>>b>>c;
        printf("Case #%d: ",i);
        long long sum = a + b;
        int flag;
        if(a>0 && b> 0 && sum<=0)
            flag = 1;
        else if(a<0&&b<0&&sum>=0)
            flag = -1;
        else 
            flag = a + b - c;
        if(flag>0)
            printf("true\n");
        else
            printf("false\n");
    }
    system("pause");
    return 0;
}