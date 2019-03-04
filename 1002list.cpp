#include<stdio.h>

typedef struct Base *Poly;

struct Base{
	double Coe;
	int Exp;
	Poly *Next;
};

int main(){
	Poly pa,pb;
	int Ka,Kb,i;
	if(scanf("%d",&Ka)==0){
		printf("Input Error!\n");
		return 0;
	}		
	pa = (Poly)malloc(sizeof(struct Base));
	pb = (Poly)malloc(sizeof(struct Base));
}





