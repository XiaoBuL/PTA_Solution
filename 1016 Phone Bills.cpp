#include <bits/stdc++.h>
using namespace std;
struct phone{
    string name;
    int status,month,time,day,hour,minute;
};

vector<int> bill;

bool cmp(phone a,phone b){
    return a.name!=b.name?a.name<b.name:a.time<b.time;
}

double  billFromZero(phone a){
    double total = 0.0;
    total = a.day*bill[24] + bill[a.hour] * a.minute;
    for (int i = 0; i < a.hour; i++)
        total += bill[i] * 60;
    total /= 100;
    return total;
}
int main(){
    int i,n;
    struct phone temp;
    int sum = 0;
    for(i=0;i<24;i++){
        int temp;
        cin>>temp;
        sum += temp;
        bill.push_back(temp);
    }
    bill.push_back(sum);
    cin>>n;
    vector<phone> customer;
    map<string,vector<phone> > match;
    for(i=0;i<n;i++){
        cin>>temp.name;
        scanf("%d:%d:%d:%d",&temp.month,&temp.day,&temp.hour,&temp.minute);
        string a;
        cin>>a;
        temp.status = (a=="on-line")?1:0;
        temp.time = temp.day*24*60 + temp.hour * 60 + temp.minute;
        customer.push_back(temp);
    }
    sort(customer.begin(),customer.end(),cmp);
    for(i=1;i<n;i++){
        if(customer[i].name==customer[i-1].name && customer[i].status == 0&&customer[i].status==1){
            match[customer[i-1].name].push_back(customer[i-1]);
            match[customer[i].name].push_back(customer[i]);
        }
    }
    auto val = matc
    for(auto val : match){
        double total = 0;
        cout<<val.first<<" ";
        vector<phone> t = val.second;
        printf("02%d\n",t[0].month);
        for(i=1;i<t.size;i++){
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",t[i - 1].day, t[i - 1].hour, t[i - 1].minute, t[i].day, t[i].hour, t[i].minute, t[i].time - t[i - 1].time, billFromZero(t[i]) - billFromZero(t[i - 1]));
            total += (billFromZero(t[i])-billFromZero(t[i-1]));
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
    //system("pause");
}