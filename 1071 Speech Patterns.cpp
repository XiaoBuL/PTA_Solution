#include<iostream>
#include<string>
#include<map>
using namespace std;

int Judge(char ch){
    if(ch>='0' && ch<='9')
        return 1;
    if(ch>='a' && ch<= 'z')
        return 1;
    if(ch >='A' && ch<= 'Z')
        return 1;
    return 0;
}

string change(string word){
    int i;
    for(i=0;i<word.size();i++){
        if(word[i]>='A'&&word[i]<='Z')
            word[i] = word[i] - 'A' +'a';
    }
    return word;
}

int main(){
    char ch;
    int begin = 0,end = 0;
    string word;
    ch = getchar();
    map<string,int> out;
    while(ch!='\n'){
        if(Judge(ch))
            word.push_back(ch);
        if(!Judge(ch) && begin ==0){
            begin = 1;
        }
        if(begin == 1 && !Judge(ch)){
            if(word.size()!=0)
                end = 1;
        }
        if(end == 1){
            word = change(word);
            out[word]++;
            word.clear();
            begin = end = 0;
        }
        ch = getchar();
    }
    if(word.size()!=0){
        word = change(word);
        out[word] ++ ;
    }
    string a;
    map<string,int>::iterator iter;
    int max = 0;
    for(iter=out.begin();iter!=out.end();iter++){
        if(max < iter->second){
            max = iter->second;
            a = iter->first;
        }
        if(max == iter->second){
            if(iter->first < a)
                a = iter->first;
        }
    }
    cout<<a<<" "<<max<<endl;
    system("pause");
    return 0;
}
