#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

//这道题 要求我们输出学校的分数排名（最后的输出排名的方式有点奇特）
//首先我们需要将输入的信息存进数据结构里，如何存储学校的信息
//transform()函数的使用
//map.count() ---  判断某个 key 是否有在 map中出现
//最后一个测试点没过

struct node{
	string name;
	int num;
	int total;
};

bool cmp(node a,node b){
	if(a.total == b.total){
		if(a.num == b.num)
			return a.name < b.name;
		else 
			return a.num < b.num;
	}
	else 
		return a.total>b.total;
}

int main(){
	int n,i;
	cin>>n;
	string id,school;
	int score;
	map<string,struct node> rank;
	vector<node> out;
	struct node temp;
	for(i=1;i<=n;i++){
		cin>>id;
		cin>>score;
		cin>>school;
		transform(school.begin(),school.end(),school.begin(),::tolower);
		temp.name = school;
		temp.num = 1;
		if(id[0] == 'B'){
			temp.total = score/1.5;
		}
		else if(id[0]== 'A')
			temp.total = score;
		else 
			temp.total = score*1.5;
		if(rank.count(school)==1){
			rank[school].total += temp.total;
			rank[school].num++;
		}
		else{
			rank[school] = temp;
		}
	}

	map<string,struct node>::iterator iter;
	for(iter = rank.begin();iter!=rank.end();iter++){
		out.push_back(iter->second);
	}

	sort(out.begin(),out.end(),cmp);
	int r = 0;
	cout<<out.size()<<endl;

	for(i=0;i<out.size();i++){
		if(i!=0){
			if(out[i-1].total!=out[i].total)
				r = 0;
		}
		if(r!=0){
			cout<<r<<" "<<out[i].name<<" "<<out[i].total<<" "<<out[i].num<<endl;
		}
		else{
			cout<<i+1<<" "<<out[i].name<<" "<<out[i].total<<" "<<out[i].num<<endl;
			r = i+1;
		} 
	}
	
	return 0;
}
