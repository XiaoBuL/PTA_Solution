#include<iostream>
#include<string>
#include<memory.h>
using namespace std;
int sys[1005][1005] = {0};
int main(){
    string s;
    getline(cin,s);
    int size = s.size();
    int i,j;
    int max = 0;
    for(i=size-1;i>=0;i--){
        for(j=i;j<size;j++){
            if(s[i]==s[j]&&(j-i+1<3||sys[i+1][j-1])){
                sys[i][j] = 1;
                if(max<j-i+1)
                    max = j-i+1;
            }
        }
    }
    cout<<max<<endl;
    system("pause");
    return 0;
}