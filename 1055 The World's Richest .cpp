#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//运行超时

struct node{
    string name;
    int age;
    int net;
};

bool cmp(node a,node b){
    if(a.net!=b.net)
        return a.net>b.net;
    else{
        if(a.age!=b.age)
            return a.age<b.age;
        else
            return a.name < b.name;
    }
}

int main(){
    int n,k,i,j;
    string name;
    int age,net;
    vector<node> out;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>name>>age>>net;
        struct node temp;
        temp.name = name;
        temp.age = age;
        temp.net = net;
        out.push_back(temp);   
    }

    int m,Amin,Amax;
    vector<node> print;

    for(i=1;i<=k;i++){
        print.clear();
        cin>>m>>Amin>>Amax;
        printf("Case #%d:\n",i);
        
        for(j=0;j<out.size();j++){
            if(out[j].age<= Amax && out[j].age>=Amin)
                print.push_back(out[j]);
        }

        if(print.size()==0){
            cout<<"None"<<endl;
            continue;
        }
        else{
            sort(print.begin(),print.end(),cmp);
            if(print.size()<m)
                for(j=0;j<print.size();j++){
                    cout<<print[j].name<<" "<<print[j].age<<" "<<print[j].net<<endl;
            }
            else{
                for(j=0;j<m;j++)
                    cout<<print[j].name<<" "<<print[j].age<<" "<<print[j].net<<endl;
            }
        }
    }
    system("pause");
    return 0;
}