#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=1e5+10;
int T,n,q,i,j,l,r,cas=1,cnt[N][26];
char s[N];
int main(){
	for (read(T);T--;){
		read(n),read(q);
		scanf("%s",s+1);
		for (i=1;i<=n;i++){
			for (j=0;j<26;j++) cnt[i][j]=0;
			cnt[i][s[i]-'A']++;
		}
		for (i=1;i<=n;i++){
			for (j=0;j<26;j++) cnt[i][j]+=cnt[i-1][j];
		}
		printf("Case #%d:\n",cas++);
		for (;q--;){
			read(l),read(r);
			for (j=0;j<26;j++){
				if (cnt[r][j]-cnt[l-1][j]>0){
					printf("%d\n",cnt[r][j]-cnt[l-1][j]);
					break;
				}
			}
		}
	}
	return 0;
}
