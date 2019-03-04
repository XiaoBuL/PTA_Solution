#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    vector<int> distance;
    int i,j,k;
    cin>>n;
    int d;
    for(i=0;i<n;i++){
        cin>>d;
        distance.push_back(d);
    }
    cin>>m;
    int c1,c2,min1,min2;
    for(i=0;i<m;i++){
        min1 = min2 = 0;
        cin>>c1>>c2;
        if(c1>c2){
            int temp = c2;
            c2 = c1;
            c1 = temp;
        }
        for(j=c1;j<c2;j++){
            min1 += distance[j-1];
        }
        for(j=0;j<c1-1;j++)
            min2 += distance[j];
        for(j=c2;j<=distance.size();j++)
            min2 += distance[j-1];
        if(min1>min2)
            cout<<min2<<endl;
        else 
            cout<<min1<<endl;
    }
    system("pause");
    return 0;
}