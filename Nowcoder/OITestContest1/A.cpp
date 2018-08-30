#include <cstdio>
#include <cstring>
char s[1000010];
int main(){
	scanf("%s",s);
	puts((s[strlen(s)-1]-'0')&1?"-1":"1");
	return 0;
}