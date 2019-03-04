
//字符串的hash操作

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
using namespace std;
struct node{
    string id;
    int score;
};
bool cmp(node a,node b){
    return a.score==b.score?a.id < b.id:a.score>b.score;
}

int main(){
    int n,m;
    int i;
    cin>>n>>m;
    vector<node> students;
    for(i=0;i<n;i++){
        string name;
        int score;
        struct node temp;
        cin>>name>>score;
        temp.id = name;
        temp.score = score;
        students.push_back(temp);
    }
    int choice,j,sum;
    sort(students.begin(),students.end(),cmp);
    string index;
    vector<node> out;
    map<string,int> f;
    vector<string> l;
    int flag[1000];
    int c[1000];
    vector<int> a;
    for(i=0;i<m;i++){
        cin>>choice;
        cin>>index;
        out.clear();
        f.clear();
        sum = 0;
        int count = 0;
        memset(flag,0,sizeof(flag));
        memset(c,0,sizeof(c));
        for(j=0;j<n;j++){
            if(choice==1){
                if(students[j].id.substr(0,1) == index){
                    out.push_back(students[j]);
                }
            }
            if(choice==2){
                if(students[j].id.substr(1,3)==index){
                    count++;
                    sum += students[j].score;
                }
            }
            if(choice==3){
                if(students[j].id.substr(4,6)==index){
                   int in = (students[j].id[1]-'0')*100+  (students[j].id[2]-'0')*10+ (students[j].id[3]-'0')*1;
                   c[in]++;
                    a.push_back(in);
                }

            } 
        }
        printf("Case %d: ",i+1);
        cout<<choice<<" "<<index<<endl;
        if(choice==1){
            if(out.size()==0){
                cout<<"NA"<<endl;
                continue;
            }
            for(j=0;j<out.size();j++){
                cout<<out[j].id<<" "<<out[j].score<<endl;
            }
        }
        if(choice==2){
            if(count==0){
                cout<<"NA"<<endl;
                continue;
            }
            cout<<count<<" "<<sum<<endl;
        }
        if(choice==3){
            if(a.size()==0){
                cout<<"NA"<<endl;
                continue;
            }
            else{
                for(j=0;j<a.size();j++){
                    if(flag[a[j]]==0){
                        cout<<a[j]<<" "<<c[a[j]]<<endl;
                        flag[a[j]] = 1;
                    }
                    else
                        continue;
                }
            }
        }
    }
    
    system("pause");
    return 0;
}