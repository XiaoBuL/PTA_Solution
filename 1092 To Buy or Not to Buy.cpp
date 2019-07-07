#include<iostream>
#include<string>
using namespace std;


int Hash[256];
int main(){
    string shop;
    string eva;
    cin>>shop;
    cin>>eva;
    int miss = 0;
    for(int i = 0;i<shop.size();i++){
        Hash[shop[i]] ++;
    }
    for(int i = 0;i<eva.size();i++){
        int index = eva[i];
        if(Hash[index] == 0)
            miss++;
        else
            Hash[index] --;
    }
    if(miss==0){
        printf("Yes %d\n",shop.size()-eva.size());   
    }
    else{
        printf("No %d\n",miss);
    }
    system("pause");
    return 0;
}