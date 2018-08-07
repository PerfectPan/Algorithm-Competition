#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=1000+10;
int T,n,m,k,i,j,status,cas=1,cnt[2200];
char s[N][20];
int main(){
	for (read(T);T--;){
		read(n),read(m),read(k);
		for (i=1;i<=n;i++) scanf("%s",s[i]);
		printf("Case #%d: ",cas++);
		if (n*(n-1)/2<k){
			puts("0");
			continue;
		}
		memset(cnt,0,sizeof(cnt));
		int limit=1<<m;
		int res=0;
		for (status=1;status<limit;status++){
			int tot=n*(n-1)/2;
			for (i=1;i<=n;i++){
				int num=0;
				for (j=0;j<m;j++)if(status&(1<<j)){
					if (s[i][j]=='B') num^=1<<j;
				}
				cnt[num]++;
			}
			for (i=0;i<=2048;i++)if(cnt[i]){
				tot-=cnt[i]*(cnt[i]-1)/2;
				cnt[i]=0;
			}
			if (tot>=k) res++;
		}
		printf("%d\n",res);
	}
	return 0;
}