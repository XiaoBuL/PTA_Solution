#include<iostream>
#include<string>
#include<map>
using namespace std;


int main(){
    int m,n;
    int i,j;
    string num;
    map<string,int> count;
    cin>>m>>n;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>num;
            count[num]++;
        }
    }
    map<string,int>::iterator iter;
    for(iter=count.begin();iter!=count.end();iter++){
        if(iter->second *2 >= n * m ){
            cout<<iter->first<<endl;
            break;
        }
    }    
    system("pause");
    return 0;
}