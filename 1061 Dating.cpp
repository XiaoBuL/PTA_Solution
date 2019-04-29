#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string d1,d2;
    string s1,s2;
    cin>>d1>>d2>>s1>>s2;
    int min_size = min(d1.size(),d2.size());
    int count = 0;
    char day,hour;
    int minute;
    for(int i=0;i<min_size;i++){
        if(((d1[i]>='a'&&d1[i]<='z')||(d1[i]>='A'&&d1[i]<='Z'))&&d1[i] == d2[i] ){
            if(count==0)
                day = d1[i];
            else{
                hour = d1[i];
                break;
            }
            count++;
        }
    }
    min_size = min(s1.size(),s2.size());
    for(int i = 0;i<min_size;i++){
        if(((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z'))&&s1[i]==s2[i]){
            minute = i;
            break;
        }
    }
    if(day=='A')
        cout<<"MON ";
    else if(day=='B')
        cout<<"TUE ";
    else if(day=='C')
        cout<<"WED ";
    else if(day=='D')
        cout<<"THU ";
    else if(day=='E')
        cout<<"FRI ";
    else if(day=='F')
        cout<<"SAT ";
    else if(day=='G')
        cout<<"SUN ";
    int h;
    if(hour>='A')
        h = hour-'A'+10;
    else
        h = hour - '0';
    printf("%2d:%02d\n",h,minute);
    system("pause");
    return 0;
}
