#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main(){
    int n;
    int i;
    string name;
    char gender;
    string id;
    int grade;
    int low=999,high=-1;
    string male,femal;
    string id1,id2;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>name;
        cin>>gender;
        cin>>id;
        cin>>grade;
        if(gender=='M'){
            if(low>grade){
                low = grade;
                male = name;
                id1 = id;
            }
        }
        else if(gender=='F'){
            if(high<grade){
                high = grade;
                femal = name;
                id2 = id;
            }
        }
    }
    if(low==999&&high==-1){
        cout<<"Absent"<<endl;
        cout<<"Absent"<<endl;
        system("pause");
        return 0;
    }
    else if(low==999){
        cout<<femal<<" "<<id2<<endl;
        cout<<"Absent"<<endl;
        cout<<"NA"<<endl;
        return 0;
    }
    else if(high==-1){
        cout<<"Absent"<<endl;
        cout<<male<<" "<<id1<<endl;
        cout<<"NA"<<endl;
        return 0;
    }
    cout<<femal<<" "<<id2<<endl;
    cout<<male<<" "<<id1<<endl;
    cout<<high-low;
    system("pause");
    return 0;
}