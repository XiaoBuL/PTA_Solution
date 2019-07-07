#include<iostream>
#include<vector>
#include<string>
using namespace std;
int inf = 1000000007;

//因为循环导致三个运行超时错误

// vector<int> p_hash[100002];
// int a_hash[100002];


// int main(){
//     string input;    
//     vector<int> a;
//     vector<int> p;
//     int i,j,k;
//     char ch;
//     int index = 0;
//     cin>>input;
//     int num_p = 0;  //P的数目
//     int num_a = 0;  //A的数目
//     //第二种算法还是超时

//     for(int num = 0;num<input.size();num++){
//         ch = input[num];
//         if(ch == 'P'){
//             num_p ++;     
//         }
//         else if(ch == 'A'){
//             num_a++;
//             for(i = 0;i<num_p;i++){
//                 p_hash[i].push_back(index);     //index = a的位置
//             }
//             a.push_back(index);
//         } 
//         else{
//             for(i=0;i<num_a;i++){
//                 a_hash[a[i]]++;       
//             }
//         }
//         index++;
//     }
//     long long  count = 0;
//     for(i=0;i<num_p;i++){
//         for(j=0;j<p_hash[i].size();j++){
//             index = p_hash[i][j];
//             count = (count + a_hash[index]) % inf;
//         }
//     }
//     printf("%ld\n",count);
    
//     //超时，循环太多了 不知道如何修改
//     //取中间的判断似乎也不行

//     // for(i=0;i<a.size();i++){
//     //     int index_a = a[i];
//     //     for(j=0;j<p.size();j++){
//     //         int index_p = p[j];
//     //         if(index_p > index_a)
//     //             break;
//     //         else{
//     //             for(k=0;k<t.size();k++){
//     //                 int index_t = t[k];
//     //                 if(index_t > index_a){
//     //                     count = (j+1) * (t.size() - k + 1) + count;
//     //                     break;
//     //                 }
//     //             }
//     //             break;
//     //         }
//     //     }
//     // }
    
//     system("pause");
//     return 0;
// }



const int maxn=100010;
const int mod=1000000007;
string str;
int leftnum[maxn]={0};
int main(){
	getline(cin,str);
	int len=str.length();
	int rightnum=0;
	int ans=0;
	for (int i=0;i<len;i++)
	{
		if (i>0)
			leftnum[i]=leftnum[i-1];
		if(str[i]=='P')
			leftnum[i]++;
	}
	for (int i=len-1;i>=0;i--)
	{
		if (str[i]=='T')rightnum++;
		else if (str[i]=='A')
		{
			ans=(ans+rightnum*leftnum[i])%mod;
		}
	}
	printf("%d",ans);
	return 0;
}
