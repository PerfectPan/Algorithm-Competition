#include<bits/stdc++.h>
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
const int N=3e5+10;
int n,i,u,v;
ll c,ans,w[N];
pair<ll,ll>dp[N];
vector<pair<int,ll> >G[N];
inline void up(pair<ll,ll>& a,ll b){
	if (a.first<=b){
		a.second=a.first;
		a.first=b;
	}
	else if (a.second<=b){
		a.second=b;
	}
}
void dfs(int u,int f){
	dp[u].first=dp[u].second=w[u];
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i].first;
		ll wi=G[u][i].second;
		if (v==f) continue;
		dfs(v,u);
		up(dp[u],w[u]-wi+dp[v].first);
	}
}
void dfs2(int u,int f){
	ans=max(ans,dp[u].first);
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i].first;
		ll wi=G[u][i].second;
		if (v==f) continue;
		if (dp[u].first==w[u]-wi+dp[v].first){
			auto t=dp[v];
			up(dp[v],w[v]-wi+dp[u].second);
			dfs2(v,u);
			dp[v]=t;
		}
		else{
			auto t=dp[v];
			up(dp[v],w[v]-wi+dp[u].first);
			dfs2(v,u);
			dp[v]=t;
		}
	}
}
int main(){
	read(n);
	for (i=1;i<=n;++i) read(w[i]);
	for (i=1;i<n;++i){
		read(u),read(v),read(c);
		G[u].PB(MP(v,c));
		G[v].PB(MP(u,c));
	}
	dfs(1,0);
	dfs2(1,0);
	printf("%lld\n",ans);
 	return 0;
}