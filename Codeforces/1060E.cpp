#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=2e5+10;
int n,u,v,i,dep[N],sz[N],dp[N][2];
ll ans,res;
vector<int>G[N];
void dfs(int u,int f){
	dep[u]=dep[f]+1,sz[u]=1;
	ans+=dep[u];
	dp[u][0]++;
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		if (v==f) continue;
		dfs(v,u);
		dp[u][0]+=dp[v][1];
		dp[u][1]+=dp[v][0];
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int f){
	res+=ans+dp[u][1];
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		if (v==f) continue;
		ans=ans-sz[v]+n-sz[v];
		int a=dp[v][0],b=dp[v][1];
		dp[v][0]+=dp[u][1]-a;
		dp[v][1]+=dp[u][0]-b;
		dfs2(v,u);
		ans=ans+sz[v]-n+sz[v];
		dp[v][0]=a;
		dp[v][1]=b;
	}
}
int main(){
	read(n);
	for (i=1;i<n;++i){
		read(u),read(v);
		G[u].PB(v);
		G[v].PB(u);
	}
	dep[0]=-1;
	dfs(1,0);
	dfs2(1,0);
	printf("%lld\n",res/4LL);
	return 0;
}