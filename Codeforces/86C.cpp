#include <bits/stdc++.h>
using namespace std;
const int N=1000+10;
const int M=100+10;
const int P=1000000009;
int n,m,status,i,j,k,l,num,tot,fail[M],cnt[M],dp[N][M][12],son[M][4],q[2000000];
char s[N];
int getId(char ch){
	switch (ch){
		case 'A':return 0;
		case 'C':return 1;
		case 'G':return 2;
		case 'T':return 3;
	}
}
void ins(char* s,int len){
	int p=0;
	for (int i=0;s[i];++i){
		int idx=getId(s[i]);
		if (!son[p][idx]) son[p][idx]=++tot;
		p=son[p][idx];
	}
	cnt[p]=len;
}
void getFail(){
	int head=0,tail=0;
	for (i=0;i<4;++i){
		if (son[0][i]) q[tail++]=son[0][i];
	}
	for (;head!=tail;){
		int u=q[head++];
		for (i=0;i<4;++i){
			if (!son[u][i]) son[u][i]=son[fail[u]][i];
			else{
				fail[son[u][i]]=son[fail[u]][i];
				cnt[son[u][i]]=max(cnt[son[u][i]],cnt[fail[son[u][i]]]);
				q[tail++]=son[u][i];
			}
		}
	}
}
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
void solve(){
	int ans=0;
	for (dp[0][0][0]=1,i=0;i<n;++i) for (k=0;k<10;++k) for (j=0;j<=tot;++j) for (l=0;l<4;++l){
		if (cnt[son[j][l]]>=k+1) up(dp[i+1][son[j][l]][0],dp[i][j][k]);
		else up(dp[i+1][son[j][l]][k+1],dp[i][j][k]);
	}
	for (i=0;i<=tot;++i) up(ans,dp[n][i][0]);
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&m);
	for (num=0,i=1;i<=m;++i){
		scanf("%s",s);
		ins(s,strlen(s));
	}
	getFail();
	solve();
	return 0;
}