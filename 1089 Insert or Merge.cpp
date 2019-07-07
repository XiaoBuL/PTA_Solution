#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//排序方法 insertion sort 和 merge sort 
//暴力方法解决: insertion 比较简单，merge 搞了有点久 merge 的部分参考了网上的写法，如果按照传统的写法还需要用到递归之后判断 很复杂
//直接用sort函数比较简单.


int JudgeEqual(vector<int> s1,vector<int> s2){
    int n = s1.size();
    for(int i = 0;i<n;i++){
        if(s1[i] != s2[i])
            return 0;
    }
    return 1;
}

void JudgeInsertion(vector<int> s1,vector<int> s2){
    int size = s1.size();
    int j;
    int flag = 0;
    for(int i = 1;i < size;i++){
        int temp = s1[i];
        for(j=i;j>0 && s1[j-1] > temp ;j--)
            s1[j] = s1[j-1];
        s1[j] = temp;
        flag = JudgeEqual(s1,s2);
        if(flag == 1){
            if(i==size-1){
                cout<<"Insertion Sort\n";
                for(i = 0; i<size-1;i++){
                    cout<<s1[i]<<" ";
                }
                cout<<s1[i]<<endl;
            }
            int temp = s1[i+1];
            for(j = i + 1;j>0 && s1[j-1] > temp;j--)
                s1[j] = s1[j-1];
            s1[j] = temp;
            cout<<"Insertion Sort\n";
            for(i = 0; i<size-1;i++){
                cout<<s1[i]<<" ";
            }
            cout<<s1[i]<<endl;
            return;
        }
    }
}

void JudgeMerge(vector<int> s1,vector<int> s2){
    int n = s1.size();
    int i,j;
    int flag = 0;
    for(int step = 2; step /2 <= n; step *= 2){
        for(i=0;i<n;i+=step){
            sort(s1.begin() + i,s1.begin() + min(n,i+step));
        }
        if(flag){
            cout<<"Merge Sort"<<endl;
            for(i=0;i<n-1;i++){
                cout<<s1[i]<<" ";
            }
            cout<<s1[i]<<endl;
            return;
        }
        flag = JudgeEqual(s1,s2);
    }
    
}

int main(){
    int n,num;
    vector <int> in1;
    vector <int> in2;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>num;
        in1.push_back(num);
    }
    for(int i = 0;i<n;i++){
        cin>>num;
        in2.push_back(num);
    }
    JudgeInsertion(in1,in2);
    JudgeMerge(in1,in2);
    system("pause");
    return 0;
}