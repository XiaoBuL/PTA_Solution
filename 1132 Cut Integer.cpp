#include<iostream>
#include<string>
using namespace std;

int change(string a){
    int sum =0 ;
    for(int i=0;i<a.size();i++){
        sum = sum *10 + a[i]-'0';
    }    
    return sum;
}

int main(){
    int n;
    string temp;
    cin>>n;
    int num1,num2,sum;
    for(int i=0;i<n;i++){
        cin>>temp;
        sum = change(temp);
        string a = temp.substr(0,temp.size()/2);
        string b = temp.substr(temp.size()/2,temp.size()/2);
        num1 = change(a);
        num2 = change(b);
        if(num1*num2!=0&&sum%(num1*num2) ==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    system("pause");
    return 0;
}