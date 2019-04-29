#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int Is_Prime(long int n){
    int i;
    if(n==2)
        return 1;
    else {
        for(i=2;i<=sqrt(n);i++){
            if(n%i==0)
                return 0;
        }
    }
    return 1;
}

long int Next_Prime(long int n){
    n++;
    while(1){
        if(Is_Prime(n)==1)
            break;
        n++;
    }
    return n;
}

int main(){
    vector<int> factor;
    long int N,temp;
    cin>>N;
    temp = N;
    if(N==1){
        cout<<N<<"=1"<<endl;
        system("pause");
        return 0;
    }
    while(1){
        if(N%2!=0)
            break;
        else{
            N = N/2;
            factor.push_back(2);
        }
    }       //如果能够一直被2整除
    long int i = 3;
    while(1){
        while(1){
            if(N%i!=0)
                break;
            else{
                N = N / i;
                factor.push_back(i);
            }
        }  
        if(N==1)
            break;
        i = Next_Prime(i);
    }
    long int count = 1;
    cout<<temp<<"=";
    for(i=0;i<factor.size()-1;i++){
        if(factor[i]!=factor[i+1]){
            if(count==1)
                cout<<factor[i]<<"*";
            else
                cout<<"^"<<count<<"*";
            count=1;
        }
        else{
            if(count==1)
                cout<<factor[i];
            count++;
        }
    }
    if(count==1)
        cout<<factor[i]<<endl;
    else
        cout<<"^"<<count;
    system("pause");
    return 0;
}