#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int c,p,i,num;
    cin>>c;
    long long sum=0;
    vector<int> coupons,product;
    for(i=0;i<c;i++){
        cin>>num;
        coupons.push_back(num);
    }
    cin>>p;
    for(i=0;i<p;i++){
        cin>>num;
        product.push_back(num);
    }
    sort(coupons.begin(),coupons.end());
    sort(product.begin(),product.end());
    int size = product.size()-1;
    i = 0;
    while(i<c&&i<p&&coupons[i]<0&&product[i]<0){
        sum += coupons[i]*product[i];
        i++;
    }
    i = c - 1;
    int j = p - 1;
    while(i>=0&&j>=0&&coupons[i]>0&&product[j]>0){
        sum += coupons[i--]*product[j--];
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}