#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//这题贼坑 好多个坑

int main(){
    int n;
    vector<int> num;
    cin>>n;
    int a,b;
    if(n==6174){
        cout<<"7641 - 1467 = 6174"<<endl;
        return 0;
    }
    while(n!=6174){
        if(n%1111 == 0){
            printf("%04d - %04d = 0000\n",n,n);
            break;
        }
        num.clear();
        if(n<1000 && n>=100)
            num.push_back(0);
        else if(n<100 && n>=10){
            num.push_back(0);
            num.push_back(0);
        }
        else if(n<10){
            num.push_back(0);
            num.push_back(0);
            num.push_back(0);
        }
        while(n!=0){
            num.push_back(n%10);
            n/=10; 
        }
        sort(num.begin(),num.end());
        a = b = 0;
        for(int i = 0 ;i<4;i++){
            b = b * 10 + num[i];
        }
        for(int i = 3;i>=0;i--){
            a = a * 10 + num[i];
        }
        n = a - b;
        printf("%04d - %04d = %04d\n",a,b,n);
    }
    system("pause");
    return 0;
}

