#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m,k,q,t,i,j;
    cin>>n>>m>>k>>q;
    vector<int> ProcessTime;
    vector<int> window[21];
    int serve[1001]={0},ans[1001]={0};

    for(i=0;i<k;i++){
        cin>>t;
        ProcessTime.push_back(t);
    }
    int que = 0;
    for(j=0;j<m;j++){
        for(i=0;i<n;i++)
            window[i].push_back(que++);
    }
    for(t=1;t<=540;t++){
        for(i=0;i<n;i++){
            int index = ans[i];
            ProcessTime[window[i][index]]--;
            if(ProcessTime[window[i][index]]==0){
                ans[i]++;
                window[i].push_back(que++);
                serve[window[i][index]+1] = t;
            }
        }
    }
    int test;
    for(i=0;i<q;i++){
        cin>>test;
        if(serve[test]!=0){
            int hour,minute;
            hour = 8 + serve[test]/60;
            minute = serve[test]%60;
            printf("%02d:%02d\n",hour,minute);
        }
        else 
            cout<<"Sorry"<<endl;
    }
    system("pause");
    return 0;
}