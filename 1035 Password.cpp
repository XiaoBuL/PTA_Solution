#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    vector<string> name;
    vector<string> passwd;
    vector<string> nname;
    vector<string> npasswd;
    int i,n;
    cin>>n;
    string team,wd;
    for(i=0;i<n;i++){
        cin>>team>>wd;
        name.push_back(team);
        passwd.push_back(wd);
    }
    int flag;
    int j;
    int count = 0;
    for(i=0;i<n;i++){
        flag = 0;
        wd = passwd[i];
        for(j=0;j<wd.size();j++){
            if(wd[j]=='1'||wd[j]=='0'||wd[j]=='l'||wd[j]=='O'){
                flag = 1;
                if(wd[j]=='1')
                    wd[j] = '@';
                else if(wd[j]=='0')
                    wd[j] = '%';
                else if(wd[j]=='O')
                    wd[j] = 'o';
                else if(wd[j]=='l')
                    wd[j] = 'L';
            }
        }
        if(flag==1){
            count++;
            nname.push_back(name[i]);
            npasswd.push_back(wd);
        }
    }
    if(count==0&&n==1){
        cout<<"There is 1 account and no account is modified"<<endl;
    }
    else if(count==0){
        printf("There are %d accounts and no account is modified\n",n);
    }
    else{
        cout<<count<<endl;
        for(i=0;i<count;i++){
            cout<<nname[i]<<" "<<npasswd[i]<<endl;
        }
    }
    system("pause");
    return 0;
}