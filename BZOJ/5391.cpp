#include <cstdio>
int i,res,ans,cnt[26];
char s[1000000+10];
int main(){
	scanf("%s",s);
	for (i=0;s[i];i++) cnt[s[i]-'a']++;
	for (i=0;i<26;i++) res+=cnt[i]==0;
	if (res>0) puts("0");
	else{
		for (res=1000001,i=0;i<26;i++) res=res<=cnt[i]?res:cnt[i];
		printf("%d\n",res);
	}
	return 0;
}