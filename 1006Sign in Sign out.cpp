#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int M,i;
	char open[16],close[16];
	char Open_Time[] = "23:59:59",Close_Time[]= "00:00:00";
	char id[16],In[9],Out[9];
	cin>>M;
	for(i=0;i<M;i++){
		cin>>id>>In>>Out;
		if(strcmp(Open_Time,In)>0){
			strcpy(open,id);
			strcpy(Open_Time,In);
		}
		if(strcmp(Close_Time,Out)<0){
			strcpy(close,id);
			strcpy(Close_Time,Out);
		}
	}
	cout<<open<<" "<<close;
	return 0;
}
