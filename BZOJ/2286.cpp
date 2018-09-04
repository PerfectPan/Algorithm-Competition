#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=3e5+10;
int n,i,q,u,v,w,sz,cnt,k,dfs_clock,point[N],dfn[N],siz[N],mn[N],bel[N],son[N],dis[N],fa[N],dep[N];
ll sum[N];
vector<pair<int,int> >G[N];
inline bool cmp(const int&a,const int&b){return dfn[a]<dfn[b];}
void dfs(int u,int f){
	dep[u]=dep[f]+1,siz[u]=1,fa[u]=f,son[u]=-1,dfn[u]=++dfs_clock;
	for (int i=0;i<(int)G[u].size();i++){
		int v=G[u][i].first,w=G[u][i].second;
		if (v==f) continue;
		dis[v]=dis[u]+w;
		mn[v]=min(mn[u],w);
		dfs(v,u);
		siz[u]+=siz[v];
		if (son[u]==-1 || siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int f){
	bel[u]=f;
	if (son[u]==-1) return;
	dfs2(son[u],f);
	for (int i=0;i<(int)G[u].size();i++){
		int v=G[u][i].first;
		if (v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
 	}
}
int lca(int u,int v){
	for (;bel[u]!=bel[v];dep[bel[u]]>dep[bel[v]]?u=fa[bel[u]]:v=fa[bel[v]]);
	return dep[u]>dep[v]?v:u;
}
void update(int a,int b){
	sum[a]+=min(1LL*mn[b],sum[b]);
	sum[b]=0;
}
void build(int points[],int k){
	static int stk[N];
	sort(points,points+k,cmp);

	cnt=k,sz=0,stk[sz++]=1;
	for (int i=0;i<k;i++){
		int u=points[i],f=lca(u,stk[sz-1]);
		if (f==stk[sz-1]) stk[sz++]=u;
		else{
			while (sz-2>=0 && dep[stk[sz-2]]>=dep[f]){
				update(stk[sz-2],stk[sz-1]);
				sz--;
			}
			if (stk[sz-1]!=f){
				update(f,stk[--sz]);
				stk[sz++]=f,points[cnt++]=f;
			}
			stk[sz++]=u;
		}
	}

	for (int i=sz-2;i>=0;i--) update(stk[i],stk[i+1]);
	printf("%lld\n",sum[1]);
	sum[1]=0;
}
int main(){
	read(n);
	for (i=1;i<n;i++){
		read(u),read(v),read(w);
		G[u].PB(MP(v,w));
		G[v].PB(MP(u,w));
	}
	mn[1]=2000000000;
	dfs(1,0),dfs2(1,1);
	for (read(q);q--;){
		read(k);
		for (i=0;i<k;i++) read(point[i]),sum[point[i]]=mn[point[i]];
		build(point,k);
	}
	return 0;
}
