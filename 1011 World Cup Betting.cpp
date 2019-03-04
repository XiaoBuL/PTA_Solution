#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    vector<double> m;
    vector<char> s;
    int i;
    double max;
    double a,b,c;
    double sum;
    for(i=0;i<3;i++){
        cin>>a;
        max = a;
        s.push_back('W');
        cin>>b;
        if(max<b){
            max = b;
            s.pop_back();
            s.push_back('T');
        }
        cin>>c;
        if(max<c){
            max = c; 
            s.pop_back();
            s.push_back('L');
        }
        m.push_back(max);
    }
    sum = 1;
    for(i=0;i<m.size();i++){
        cout<<s[i]<<" ";
        sum *= m[i];
    }
    sum = (sum*0.65-1)*2;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum;
    //system("pause");
    return 0;
}