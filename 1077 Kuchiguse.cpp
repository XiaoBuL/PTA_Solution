#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//查找n个字符串之间最长的公共后缀


int main(){
    int n;
    scanf("%d",&n);
    string out;
    getline(cin,out);
    for(int i = 0;i<n;i++){
        string temp;
        getline(cin,temp);
        reverse(temp.begin(),temp.end());
        int len = temp.length();
        if(i == 0){
            out = temp;
        }
        else{
            int len2 = out.length();
            int less = min(len,len2);
            for(int j = 0;j<less;j++){
                if(out[j]!=temp[j]){
                    out = out.substr(0,j);
                    break;
                }
            }
        }
        
    }
    reverse(out.begin(),out.end());
    if(out.length()==0) out = "nai";
    cout<<out<<endl;    
    system("pause");
    return 0;
}