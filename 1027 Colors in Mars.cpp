#include<iostream>
#include<string>
using namespace std;
void change(int a){
    char ch;
    if(a<13){
        cout<<"0";
        if(a>9){
            ch = a + 'A' -10 ;
            cout<<ch;
        }
        else
            cout<<a;
    }
    else{
        int temp = a%13;
        a /= 13;
        if(a>9){
            ch = a + 'A' -10 ;
            cout<<ch;
        }
        else
            cout<<a;
        if(temp>9){
            ch = temp + 'A' -10;
            cout<<ch;
        }
        else 
            cout<<temp;
    }
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<"#"; 
    change(a);
    change(b);
    change(c);
    system("pause");
    return 0;
}