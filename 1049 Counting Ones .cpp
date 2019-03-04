#include<iostream>
#include<string>
using namespace std;


int main(){
    int n;
    cin>>n;
    int count = 0;
    int high=0,low=0,factor = 1;
    while(n/factor){
        high = n/(factor*10);
        low = n - (n/factor)*factor;
        int a  = (n/factor) %10;
        if(a==0){
            count += high*factor;
        }
        else if(a==1){
            count+= high * factor + low + 1;
        }
        else {
            count+= (high+1)*factor;
        }
        factor *= 10;
    }
    cout<<count<<endl;
    system("pause");
    return 0;
}