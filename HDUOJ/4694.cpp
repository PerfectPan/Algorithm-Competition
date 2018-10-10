#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=5e4+10;
int n,m,i,j,k,u,v,p,dfs_clock,mn[N],dfn[N],f[N],rk[N],fa[N],sdom[N],idom[N];
ll ans[N];
vector<int>G[N],pre[N],bucket[N],G2[N];
void dfs(int u){
	dfn[u]=++dfs_clock,rk[dfs_clock]=u,sdom[u]=dfs_clock;
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		if (dfn[v]) continue;
		dfs(v);
		fa[v]=u;
	}
}
int Find(int p){
	if (f[p]==p) return p;
	int root=Find(f[p]);
	if (sdom[mn[f[p]]]<sdom[mn[p]]) mn[p]=mn[f[p]];
	return f[p]=root;
}
inline int eval(int p){
	Find(p);
	return mn[p];
}
void LengauerTarjan(){
	dfs(n);
	for (i=dfs_clock;i>=2;--i){
		p=rk[i];
		for (int k:pre[p]){
			if (dfn[k]){
				sdom[p]=min(sdom[p],sdom[eval(k)]);
			}
		}
		bucket[rk[sdom[p]]].PB(p);
		int anc=fa[p];f[p]=fa[p];
		for (int v:bucket[anc]){
			int u=eval(v);
			idom[v]=sdom[u]==sdom[v]?anc:u;
		}
		bucket[anc].clear();
	}
	for (i=2;i<=dfs_clock;++i) p=rk[i],idom[p]=idom[p]==rk[sdom[p]]?idom[p]:idom[idom[p]];
	for (i=2;i<=dfs_clock;++i) p=rk[i],sdom[p]=rk[sdom[p]];
}
void dfs2(int u,int f){
	ans[u]+=u;
	for (int i=0;i<(int)G2[u].size();++i){
		int v=G2[u][i];
		if (v==f) continue;
		ans[v]+=ans[u];
		dfs2(v,u);
	}
}
void solve(){
	for (i=1;i<=n-1;++i) G2[idom[i]].PB(i);
	dfs2(n,0);
	for (i=1;i<=n;++i) printf("%lld%c",ans[i],i==n?'\n':' ');
}
int main(){
	while (~scanf("%d%d",&n,&m)){
		for (dfs_clock=0,i=1;i<=n;++i){
			G[i].clear(),G2[i].clear(),pre[i].clear();
			idom[i]=sdom[i]=dfn[i]=ans[i]=0,f[i]=mn[i]=i;
		} 
		for (i=1;i<=m;++i){
			read(u),read(v);
			G[u].PB(v);
			pre[v].PB(u);
		}
		LengauerTarjan();
		solve();
	}
	return 0;
}