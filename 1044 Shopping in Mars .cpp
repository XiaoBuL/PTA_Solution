#include<iostream>
#include<vector>
using namespace std;
//动态规划问题，子序列
int inf = 999999999;
int main(){
    int n,m,i,num;
    cin>>n>>m;
    vector<int> sum(n+1);
    for(i=0;i<n;i++){
        cin>>num;
        sum[i+1] = sum[i] + num;
    }
    vector<int> res(n+1);
	for(int i=1;i<=n;i++)
	{
		int left=i,right=n;
		int mid;
		while(left<right)
		{
			mid=(left+right)/2;
			if(sum[mid]-sum[i-1] >= m)
			{
				right=mid;
			}
			else
			{
				left=mid+1;
			}
		}
		if(sum[right]-sum[i-1] >=m)
		{
			if(sum[right]-sum[i-1] <inf)
				inf=sum[right]-sum[i-1];
			res[i]=right;
		}
		else
			break;
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[res[i]]-sum[i-1] == inf)
			printf("%d-%d\n",i,res[i]);
	}
    system("pause");
    return 0;
}