#include<iostream>
#include<string>
using namespace std;

int main(){
    string s1,s2;
    int hash[128] = {0};
    getline(cin,s1);
    getline(cin,s2);
    int len1 = s1.size();
    int len2 = s2.size();
    int i;
    for(i=0;i<len2;i++){
        hash[s2[i]] = 1;
    }
    for(i=0;i<len1;i++){
        if(hash[s1[i]]==0)
            cout<<s1[i];
    }
    system("pause");
    return 0;
}