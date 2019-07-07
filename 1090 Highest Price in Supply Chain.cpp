#include<iostream>
#include<vector>
using namespace std;
//3个运行超时

vector<int> q[100002];
vector<int> out[100002];

int main(){
    int n,i,root,out_num;
    double original,r;
    cin>>n>>original>>r;
    vector<int> Hash;
    vector<double> price(n);
    
    for(i=0;i<n;i++){
        int temp;
        cin>>temp;
        Hash.push_back(temp);
        if(temp == -1){
            root = i;
            price[i] = original;
        }
        else
            q[temp].push_back(i);    
    }
    //不超时算法;
    int k = 0;
    out[0].push_back(root);
    while(!out[k].empty()){
        for(i=0;i<out[k].size();i++){
            int index = out[k][i];
            for(int j = 0;j<q[index].size();j++){
                out[k+1].push_back(q[index][j]);
                price[q[index][j]] = price[index] * (1+r/100);
            }            
        }
        k++;
    }

    out_num = out[k-1].size();
    double max = price[out[k-1][0]];
    // //超时的算法
    // for(i=0;i<n;i++){
    //     int index = Hash[i];
    //     double p = original;
    //     while(index != -1){
    //         index = Hash[index];
    //         p *= (1+r/100);
    //     }
    //     price.push_back(p);
    //     if(max < p){
    //         max = p;
    //         out_num = 1;
    //     }
    //     else if(max == p){
    //         out_num++;
    //     }
    // }
    printf("%.2f %d\n",max,out_num);
    system("pause");
    return 0;
}