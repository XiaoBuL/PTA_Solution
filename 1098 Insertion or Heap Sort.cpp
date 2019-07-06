#include<iostream>
#include<vector>
using namespace std;

vector<int> in1;
vector<int> in2;
int n;

int JudgeEqual(vector<int> out){
    for(int i = 0;i<out.size();i++){
        if(in2[i]!=out[i])
            return 0;
    }
    return 1;
}

void JudgeInsertion(){
    int flag = 0;
    int i,j;
    vector<int> t;
    for(i=0;i<in1.size();i++){
        t.push_back(in1[i]);
    }
    for(i=1;i<t.size();i++){
        int temp = t[i];
        for(j=i;j>0&&t[j-1]>temp;j--)
            t[j] = t[j-1]; 
        t[j] = temp;
        if(flag == 1){
            cout<<"Insertion Sort"<<endl;
            for(i=0;i<t.size()-1;i++){
                cout<<t[i]<<" ";
            }
            cout<<t[i]<<endl;
            return;
        }
        flag = JudgeEqual(t);
    }
}

void MaxHeapSet(int start,int end){
    int dad = start;
    int son = dad*2+1;
    while(son <= end){
        if(son+1 <= end && in1[son] < in1[son+1])
            son++;
        if(in1[dad] > in1[son])
            return;
        int temp = in1[dad];
        in1[dad] = in1[son];
        in1[son] = temp;
        dad = son;
        son = dad*2 + 1;
    }
}

void JudgeHeap(){
    int flag = 0;
    int i,j;
    int size = in1.size();
    for(i= size/2 - 1;i>=0;i--){
        MaxHeapSet(i,size-1);
    }
    for(i=size-1;i>0;i--){
        flag = JudgeEqual(in1);
        int temp = in1[0];
        in1[0] = in1[i];
        in1[i] = temp;
        MaxHeapSet(0,i-1);
        if(flag == 1){
            cout<<"Heap Sort"<<endl;
            for(i=0;i<size-1;i++){
                cout<<in1[i]<<" ";
            }
            cout<<in1[i]<<endl;
            return;
        }
    }
}

int main(){
    cin>>n;
    int i,j,num;
    for(i=0;i<n;i++){
        cin>>num;
        in1.push_back(num);
    }
    for(i=0;i<n;i++){
        cin>>num;
        in2.push_back(num);
    }  
    JudgeInsertion();
    JudgeHeap();
    system("pause");
    return 0;
}
