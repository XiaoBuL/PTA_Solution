#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main(){
    string a;
    vector<char> s;
    int store[10] = {0};
    int mul[10] = {0};
    int i;
    cin>>a;
    int sum,carry=0;
    for(i=a.size()-1;i>=0;i--){
        sum = a[i] - '0';
        store[sum]++;
        sum = ((a[i] - '0')*2 + carry) %10;
        mul[sum]++;
        carry =  ((a[i] - '0')*2 + carry)/10;
        s.push_back(sum+'0');
    }
    int flag = 1;
    for(i=0;i<10;i++){
        if(store[i]!=mul[i]){
            flag = 0;
            break;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    for(i=s.size()-1;i>=0;i--){
        cout<<s[i];
    }
    system("pause");
    return 0;
}
