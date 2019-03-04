#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    int n1,n2,n3;
    int i;
    n1 = n2 = (n+2)/3;
    n3 = n- n1 - n2;
    string space;
    for(i=0;i<n3;i++){
        char c = ' ';
        space += c;
    }
    for(i=0;i<n1;i++){
        if(i!=n1-1){
           cout<<s[i]<<space<<s[n-i-1];
        } 
        else{
           for(int j=i;j<n1+n3+1;j++){
               cout<<s[j];
           }
        }
       cout<<endl;
    }
    system("pause");
}