#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=3e4+10;
int n,i,u,v,s;
ll w,mx=-1,dep[N];
vector<pair<int,ll> >G[N];
void dfs(int u,int f){
	if (mx<dep[u]){
		mx=dep[u];
		s=u;
	}
	for (int i=0;i<(int)G[u].size();i++){
		int v=G[u][i].first;
		ll w=G[u][i].second;
		if (v==f) continue;
		dep[v]=dep[u]+w;
		dfs(v,u);
	}
}
int main(){
	read(n);
	for (i=1;i<n;i++){
		read(u),read(v),read(w);
		G[u].PB(MP(v,w));
		G[v].PB(MP(u,w));
	}
	dfs(1,0);
	for (mx=0,i=1;i<=n;i++) dep[i]=0;
	dfs(s,0);
	printf("%lld\n",mx*10LL+(1LL+mx)*mx/2LL);
	return 0;
}