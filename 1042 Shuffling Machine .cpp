#include<iostream>
#include<vector>
using namespace std;

void print(int number){
    int ch,num;
    if(number>0&&number<=13)
        cout<<"S"<<number;
    else if(number>13&&number<=26)
        cout<<"H"<<number-13;
    else if(number>26&&number<=39)
        cout<<"C"<<number-26;
    else if(number>39&&number<=52)
        cout<<"D"<<number-39;
    else
    {
        cout<<"J"<<number-52;
    }
    return ;
}
int main(){
    int k,i,num,j;
    int card[55];
    int change[55];
    cin>>k;
    vector<int> seq;
    for(i=0;i<54;i++){
        cin>>num;
        card[i+1] = change[i+1] = i+1;
        seq.push_back(num);
    }
    for(i=0;i<k;i++){
        for(j=1;j<=54;j++){
            card[seq[j-1]] = change[j];
        }
        for(j=1;j<=54;j++){
            change[j] = card[j];
        }
    }
    for(i=1;i<=53;i++){
        print(card[i]);
        cout<<" ";
    }
    print(card[i]);
    system("pause");
    return 0;
}