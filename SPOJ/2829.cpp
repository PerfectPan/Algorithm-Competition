#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=50+10;
const int P=1e9;
int T,n,m,i,j,ans,bit,status,c[N],dp[N][(1<<15)+10];
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int main(){
	for (read(T);T--;){
		read(n),read(m);
		for (i=1;i<=n;i++) read(c[i]);
		memset(dp,0,sizeof(dp));
		for (ans=0,i=0;i<(1<<m);i++){
			if (i%c[1]) dp[1][i]=1;
		}
		for (i=2;i<=n;i++){
			for (status=0;status<(1<<m);status++) dp[i][status]=dp[i-1][status^((1<<m)-1)];
			for (bit=0;bit<m;bit++){
				for (status=0;status<(1<<m);status++){
					if (!(status&(1<<bit))) up(dp[i][status],dp[i][status|(1<<bit)]);
				}
			}
			for (status=0;status<(1<<m);status++){
				if (status%c[i]==0) dp[i][status]=0;
			}
		}
		for (i=0;i<(1<<m);i++) up(ans,dp[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}