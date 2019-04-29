#include<stdio.h>
void upcase(char *str);

void upcase(char *str){
    char dst;
    char *dp = &dst;
    while(*str){
        char c  = *str++;
        if(c>='a'&& c <='z')
            c+='A' - 'a';
        *dp-- = c;
    }
    printf("%s",dp);
}
int main(){
    upcase("aaaa123");
    int i;
    scanf("%d",&i);
    return 0;
}