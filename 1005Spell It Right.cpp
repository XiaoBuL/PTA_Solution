#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
void change(int a);

int main(){
	char s[101];
	int sum,len,i,temp,count,a,b;
	cin>>s;
	len = strlen(s);
	sum = 0;
	for(i=0;i<len;i++){
		sum  = sum + s[i] - '0';
	}
	temp = sum;
	count  = 0;
	while(temp!=0){
		temp = temp/10;
		count++;			
	}
	for(i=count-1;i>0;i--){
		b = pow(10,i);
		a = sum/b;
		change(a);
		sum = sum%b;
		cout<<" ";	
	}
	change(sum);
	//for(i=pow(10,temp);i>0;i--){
		
	//}
	return 0;
}

void change(int a){
	switch(a){
		case 0: cout<<"zero";break;
		case 1: cout<<"one";break;
		case 2: cout<<"two";break;
		case 3: cout<<"three";break;
		case 4: cout<<"four";break;
		case 5: cout<<"five";break;
		case 6: cout<<"six";break;
		case 7: cout<<"seven";break;
		case 8: cout<<"eight";break;
		case 9: cout<<"nine";break;
	}
	return ;
}
