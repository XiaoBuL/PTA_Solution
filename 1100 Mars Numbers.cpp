#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

string num1[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string num2[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}; 

void change(string s){
    int sum = 0;
    for(int i= 0;i<s.size();i++){
        sum  = sum*10 + (s[i] - '0'); 
    }
    if(sum>12){
        int index1 = sum %13;
        int index2 = sum /13;
        if(index2>0){
            cout<<num2[index2-1]<<" ";
        }    
        cout<<num1[index1]<<endl;
    }
    else{
        int index1 = sum %13;
        cout<<num1[index1]<<endl;
    }
}


int change2(string s,int n){
    if(n==1){
        if(s == num1[0])
            return 0;
        else if(s == num1[1])
            return 1;
        else if(s == num1[2])
            return 2;
        else if(s == num1[3])
            return 3;
        else if(s == num1[4])
            return 4;
        else if(s == num1[5])
            return 5;
        else if(s == num1[6])
            return 6;
        else if(s == num1[7])
            return 7;
        else if(s == num1[8])
            return 8;
        else if(s == num1[9])
            return 9;
        else if(s == num1[10])
            return 10;
        else if(s == num1[11])
            return 11;
        else if(s == num1[12])
            return 12;
    }
    else{       
        if(s == num2[0])
            return 1;
        else if(s == num2[1])
            return 2;
        else if(s == num2[2])
            return 3;
        else if(s == num2[3])
            return 4;
        else if(s == num2[4])
            return 5;
        else if(s == num2[5])
            return 6;
        else if(s == num2[6])
            return 7;
        else if(s == num2[7])
            return 8;
        else if(s == num2[8])
            return 9;
        else if(s == num2[9])
            return 10;
        else if(s == num2[10])
            return 11;
        else if(s == num2[11])
            return 12;
    }
}

int main(){
    int n;
    int i,j;
    string input;
    cin>>n;
    getline(cin,input);
    for(i=0;i<n;i++){
        getline(cin,input);
        if(input[0] >= '0' && input[0] <= '9')
            change(input);     
        else{
            if(input.size()>4){
                string s1 = input.substr(0,3);
                string s2 = input.substr(4,3);
                int a1 = change2(s2,1);
                int a2 = change2(s1,2);
                cout<<a2*13+a1<<endl;
            }
            else{
                string s1 = input.substr(0,3);
                if(s1 == "tam"){
                    cout<<13<<endl;
                    continue;
                }
                int a1 = change2(s1,1);
                cout<<a1<<endl;             
            }
        }        
    }
        
    system("pause");
    return 0;
}