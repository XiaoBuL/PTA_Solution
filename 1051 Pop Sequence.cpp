#include<iostream>
#include<vector>
using namespace std;

//记得DS平时练习有做过，之前不是很会做，现在感觉很熟练了

int main(){
    int m,n,k,num;
    vector<int> stack;
    vector<int> pop(n);
    cin>>m>>n>>k;
    int flag,i,j,t;
    for(i=0;i<k;i++){
        pop.clear();
        stack.clear();
        flag = 1;
        for(j=0;j<n;j++){
            cin>>num;
            pop.push_back(num);
        }
        int top = pop[0];

        for(j=1;j<=top;j++)
            stack.push_back(j);

        if(stack.size()>m){
            cout<<"NO"<<endl;
            continue;
        }
        stack.pop_back();
        int max = top;
        for(j=1;j<n;j++){
            num = pop[j];
            if(num<max){
                // cout<<pop[j]<<" ";
                if(stack.back()!=num){
                    flag = 0;
                    break;
                }
                stack.pop_back();
            }
            else{
                for(t=max+1;t<=num;t++){
                    stack.push_back(t);
                }
                max = num;
                if(stack.size()>m){
                    flag =0 ;
                    break;
                }
                stack.pop_back();
            }
        }
        if(flag == 0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    system("pause");
    return 0;
}