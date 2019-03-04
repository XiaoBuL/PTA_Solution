#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
struct student{
    string id;
    int c,m,e,a;
    int rc,rm,re,ra;
}s[2001];
int flag = 1;
 int n,m;
bool cmp(student a,student b){
    switch(flag){
        case 1: return a.c>b.c;
        case 2: return a.m>b.m;
        case 3: return a.e>b.e;
        default: return a.a>b.a;
    }
}
void Rank(){
    int i;
    switch(flag){
        case 1:
        for(i=0;i<n;i++){
            if(i>0&&s[i].c==s[i-1].c)
                s[i].rc = s[i-1].rc;
            else 
                s[i].rc = i+1;
        }
        break;
        case 2:
        for(i=0;i<n;i++){
            if(i>0&&s[i].m==s[i-1].m)
                s[i].rm = s[i-1].rm;
            else 
                s[i].rm = i+1;
        }
        break;
        case 3:
        for(i=0;i<n;i++){
            if(i>0&&s[i].e==s[i-1].e)
                s[i].re = s[i-1].re;
            else 
                s[i].re = i+1;
        }
        break;
        default:
        for(i=0;i<n;i++){
            if(i>0&&s[i].a==s[i-1].a)
                s[i].ra = s[i-1].ra;
            else 
                s[i].ra = i+1;
        }
        break;
    }   
}

void print(student a){
    char ch = 'A';
    int rank = a.ra;
    if(rank>a.rc){
        ch = 'C';
        rank = a.rc;
    }
    if(rank>a.rm){
        ch = 'M';
        rank = a.rm;
    }   
    if(rank>a.re){
        ch = 'E';
        rank = a.re;
    }
    cout<<rank<<" "<<ch<<endl;
}
int main(){ 
    int i;
    string name;
    map<string,int> match;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>s[i].id>>s[i].c>>s[i].m>>s[i].e;
        s[i].a = s[i].c + s[i].m + s[i].e;
    }
    for(flag=1;flag<=4;flag++){
        sort(s,s+n,cmp);
        for(i=0;i<n;i++){
            Rank();
            match[s[i].id] = i+1;
        }
    }
    for(i=0;i<m;i++){
        cin>>name;
        if(match[name])
            print(s[match[name]-1]);
        else 
            cout<<"N/A"<<endl;
    }
    system("pause");

}