#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
struct node{
    string id;
    string title;
    string author;
    string key[5];
    string publisher;
    string year;
    int k;
};

bool cmp(node a,node b){
    return a.id < b.id;
}
int main(){
    int n,m,j,i,k;
    string temp;
    cin>>n;
    cin.get();
    vector<node> library(n+1);
    for(i=0;i<n;i++){
        getline(cin,library[i].id);
        getline(cin,library[i].title);
        getline(cin,library[i].author);
        getline(cin,temp);
        k = 0;
        for(j=0;j<temp.size();j++){
            if(temp[j]!=' ')
                library[i].key[k] += temp[j];
            else
                k++;
        }
        library[i].k = k+1;
        getline(cin,library[i].publisher);
        getline(cin,library[i].year);
    }
    sort(library.begin(),library.end(),cmp);
    cin>>m;
    int flag;
    int index;
    string num,key;
    for(i=0;i<m;i++){
        cin>>num;
        cin.get();
        getline(cin,key);
        flag = 0;
        index = num[0] - '0';
        cout<<index<<": "<<key<<endl;
        for(j=1;j<=n;j++){
            switch (index)
            {
                case 1:
                    if(library[j].title==key){
                        cout<<library[j].id<<endl;
                        flag = 1;
                    }
                    break;
                case 2:
                    if(library[j].author == key){
                        cout<<library[j].id<<endl;
                        flag = 1;
                    }
                    break;
                case 3:
                    for(k=0;k<library[j].k;k++){
                        if(library[j].key[k]==key){
                            cout<<library[j].id<<endl;
                            flag = 1;
                        }
                    }
                    break;
                case 4:
                    if(library[j].publisher == key){
                        cout<<library[j].id<<endl;
                        flag = 1;
                    }
                    break;
                default:
                    if(library[j].year==key){
                        cout<<library[j].id<<endl;
                        flag = 1;
                    }
                    break;
            }
        }
        if(flag==0)
            cout<<"Not Found"<<endl;
    }
    system("pause");
    return 0;
}