#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//第一次 第四个测试点没有AC过,看了柳神的 这是因为在输出的时候 排序函数没有传参
//排序函数一定要有cmp函数！！！
//排序函数一定要有cmp函数！！！
//排序函数一定要有cmp函数！！！


struct node{
    int Ge;
    int Gi;
    double total;
    int id;
    vector<int> choice;
};

bool cmp2(int a,int b){
    return a<b;
}

bool cmp(node a,node b){
    if(a.total == b.total){
        return a.Ge > b.Ge;
    }
    return a.total>b.total;
}



vector<int> out[102];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> school(m);
    vector<node> student(n);
    vector<node> temp(n);

    int i,j;

    for(i=0;i<m;i++){
        cin>>school[i];
    }

    for(i=0;i<n;i++){
        cin>>student[i].Ge>>student[i].Gi;
        student[i].id = i;
        student[i].total = (student[i].Ge + student[i].Gi)/2;
        for(j=0;j<k;j++){
            int num;
            cin>>num;
            student[i].choice.push_back(num);
        }
        temp[i].total = student[i].total;
        temp[i].Ge = student[i].Ge;
    }

    sort(student.begin(),student.end(),cmp);

    for(i=0;i<n;i++){
        for(j=0;j<student[i].choice.size();j++){
            int index = student[i].choice[j];
            if(school[index] == 0){
                if(temp[out[index].back()].total == student[i].total && temp[out[index].back()].Ge == student[i].Ge){
                    out[index].push_back(student[i].id);
                    break;
                }
            }
            else{
                out[index].push_back(student[i].id);
                school[index]--;
                break;
            }
        }
    }

    for(i=0;i<m;i++){
        if(out[i].size()!=0){
            sort(out[i].begin(),out[i].end(),cmp2);
            for(j=0;j<out[i].size()-1;j++){
                cout<<out[i][j]<<" ";
            }
            cout<<out[i][j];
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}