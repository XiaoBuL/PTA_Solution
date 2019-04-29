#include<iostream>
#include<vector>
using namespace std;
int Hash[1000001];
int n;

//卡在了中间两个要超时的点

int IsRight(){
    int i;
    for(i=0;i<n;i++){
        if(Hash[i]!=i)
            return 0;
    } 
    return 1;
}
int main(){
    int i,index;
    cin>>n;
    for(i=0;i<n;i++){
        int num;
        cin>>num;
        Hash[i] = num;
        if(num == 0)
            index = i;      //0所在的位置
    }
    int index2,count = 0;
    while(!IsRight()){
        if(index == 0 ){
            for(i=1;i<n;i++){
                if(Hash[i]!=i){
                    index = i;
                    Hash[0] = Hash[i];
                    Hash[i] = 0;
                    count++;
                    break;
                }
            }
        }
        for(i=0;i<n;i++){
            if(Hash[i] == index){
                index2 = i;
                break;
            }                
        }
        Hash[index] = index;
        Hash[index2] = 0;
        index = index2;
        count++;
    }
    cout<<count<<endl;
    system("pause");
    return 0;
}