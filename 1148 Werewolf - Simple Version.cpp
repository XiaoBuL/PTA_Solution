#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> state(n+1);
    vector<int> wolf;
    int i,j,k;
    for(i=1;i<=n;i++)
        cin>>state[i];
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            wolf.clear();
            vector<int> judge(n+1,1);
            judge[i] = judge[j] = -1;
            for(k=1;k<=n;k++){
                if(state[k]*judge[abs(state[k])] < 0) 
                    wolf.push_back(k);
            }
            if(wolf.size()==2&&judge[wolf[0]] + judge[wolf[1]] == 0){
                cout<<i<<" "<<j<<endl;
                system("pause");
                return 0;
            }
        }
    }
    cout<<"No Solution"<<endl;
    system("pause");
    return 0;  
}

