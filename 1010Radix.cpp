#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int change_demical(int index,char a[]);

int main(){
	char N1[11],N2[11],in[11],out[11];
	int tag,index,len,i,j;
	int demical1,demical2,temp,flag;
	cin>>N1>>N2>>tag>>index;
	if(tag==1){
		strcpy(in,N1);
		strcpy(out,N2);
	}
	else{
		strcpy(in,N2);
		strcpy(out,N1);
	}
	demical1 = change_demical(index,in);
	cout<<demical1<<endl;
	i = 2;
	temp = 0;
	while(1){
		demical2 = change_demical(i,out);
		if(demical2<demical1&&demical2>temp){
			flag = -1;
			break;
		}
		if(demical2 == demical1)
			break;
		i++;
	}
	if(flag==-1)
		cout<<"Impossible";
	else
		cout<<i;
	system("pause");
	return 0;
}

int change_demical(int index,char a[]){
	int sum,i,j,len;
	sum = 0;
	len = strlen(a);
	j = 0;
	for(i=len-1;i>=0;i--){
		if(a[j]>='a'&&a[j]<='z'){
			sum += (a[j]-'a'+10) * pow(index,i); 	
		}
		else 
			sum += (a[j]-'0') * pow(index,i); 
		j++;
	}
	return sum;
}


