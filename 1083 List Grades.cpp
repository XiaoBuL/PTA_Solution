#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct node{
    string name;
    string id;
    int grade;
};

bool cmp(node a,node b){
    return a.grade > b.grade;
}

int main(){
    
    int n;
    cin>>n;
    vector<node> student(n);
    for(int i=0;i<n;i++){
        cin>>student[i].name>>student[i].id>>student[i].grade;
    }
    int low,high;
    cin>>low>>high;
    vector<node> out;
    for(int i=0;i<n;i++){
        if(student[i].grade >= low &&student[i].grade <= high)
            out.push_back(student[i]);
    }
    if(out.size()==0)
        cout<<"NONE"<<endl;
    else{
        sort(out.begin(),out.end(),cmp);
        for(int i=0;i<out.size();i++){
            cout<<out[i].name<<" "<<out[i].id<<endl;
        }
    }
    system("pause");
    return 0;
}