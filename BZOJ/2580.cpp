#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=300+10;
const int M=1000+10;
const int SIGMA_SIZE=3;
char s[N];
int n,k,i,j,l,tot,dp[N*SIGMA_SIZE][M],fail[N*SIGMA_SIZE],cnt[N*SIGMA_SIZE],son[N][SIGMA_SIZE];
queue<int>Q;
void ins(char* s){
	int p=0;
	for (int i=0;s[i];++i){
		int c=s[i]-'A';
		if (!son[p][c]) son[p][c]=++tot;
		p=son[p][c];
	}
	cnt[p]++;
}
void getfail(){
	for (int i=0;i<SIGMA_SIZE;++i){
		if (son[0][i]) Q.push(son[0][i]);
	}
	while (!Q.empty()){
		int u=Q.front();Q.pop();
		for (int i=0;i<SIGMA_SIZE;++i){
			if (!son[u][i]) son[u][i]=son[fail[u]][i];
			else{
				fail[son[u][i]]=son[fail[u]][i];
				Q.push(son[u][i]);
			}
		}
		cnt[u]+=cnt[fail[u]];
	}
}
void solve(){
	int res=0;
	memset(dp,-127,sizeof(dp));
	dp[0][0]=0;
	for (i=0;i<k;++i){
		for (j=0;j<=tot;++j){
			for (l=0;l<SIGMA_SIZE;++l){
				dp[son[j][l]][i+1]=max(dp[son[j][l]][i+1],dp[j][i]+cnt[son[j][l]]);
			}
		}
	}
	for (i=0;i<=tot;++i) res=max(res,dp[i][k]);
	printf("%d\n",res);
}
int main(){
	read(n),read(k);
	for (i=1;i<=n;++i){
		scanf("%s",s);
		ins(s);
	}
	getfail();
	solve();
	return 0;
}