#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int is_prime(int n){
    int i;
    if(n==2)
        return 1;
    for(i=2;i<=sqrt(n);i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int find_prime(int n){
    while(!is_prime(n)){
        n++;
    }
    return n;
}

int main(){
    int msize,n;
    cin>>msize>>n;
    msize = find_prime(msize);
    int num,j;
    vector<int> Hash(msize);
    for(int i = 0;i<n;i++){
        cin>>num;
        if(i!=0)
            cout<<" ";
        if(Hash[num%msize] == 0){
            cout<<num%msize;
            Hash[num%msize] = 1;
        }
        else{
            int flag = 0;
            for(j = (num%msize)*(num%msize); j < msize/2;j = (j+1)*(j+1)){
                if(Hash[j%msize]==0){
                    Hash[j%msize] = 1;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                cout<<"-";
            else
                cout<<j%msize;
        }
    }
    system("pause");
    return 0;
}