#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//堆栈里的排序,被抽掉以后栈的数目发生改变
//读入含有空格的字符串
//三个运行超时的错误

int string_int(string a){
    int len = a.length();
    int i;
    int sum = 0;
    for(i=0;i<len;i++){
        char ch = a[i];
        sum = sum * 10 + ch - '0';
    }
    return sum;
}


int main(){
    int n,i;
    cin>>n;
    n = n + 1;
    vector<int> Stack;
    vector<int> out;
    while(n--){
        string test;
        getline(cin,test);
        if(test.substr(0,2) == "Pe"){
            if(Stack.size()==0)
                cout<<"Invalid\n";
            else{
                out.clear();
                for(i=0;i<Stack.size();i++){
                    out.push_back(Stack[i]);
                }
                sort(out.begin(),out.end());
                int len = out.size();
                if(len%2==0)
                    cout<<out[len/2-1]<<endl;
                else
                    cout<<out[(len+1)/2-1]<<endl;
            }
        }
        else if(test.substr(0,2) == "Po"){
            if(Stack.size()==0)
                cout<<"Invalid\n";
            else{
                int num = Stack.back();
                Stack.pop_back();
                cout<<num<<endl;
            }
        }
        else if(test.substr(0,2) == "Pu"){
            int len = test.length();
            string temp = test.substr(5,len-5);
            int num = string_int(temp);
            Stack.push_back(num);
        }
    }
    system("pause");
    return 0;
}