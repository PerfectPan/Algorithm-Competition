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
const int N=1e5+10;
struct Edge{int u,v,d;};
int n,m,i,u,v,w,q,fa[N],bel[N],son[N],sz[N],dep[N];
bool vis[N<<1],vis2[N];
ll dis[45][N],d[N];
vector<int>G[N];
vector<Edge>edges;
void addEdge(int u,int v,int w){
	edges.PB((Edge){u,v,w});
	edges.PB((Edge){v,u,w});
	int m=edges.size();
	G[u].PB(m-2);
	G[v].PB(m-1);
}
void dfs(int u,int f){
	fa[u]=f,sz[u]=1,dep[u]=dep[f]+1,son[u]=-1,vis2[u]=1;
	for (int i=0;i<(int)G[u].size();++i){
		Edge& e=edges[G[u][i]];
		int u=e.u,v=e.v,w=e.d;
		if (vis2[v] || v==f) continue;
		vis[G[u][i]]=vis[G[u][i]^1]=1;
		d[v]=d[u]+w;
		dfs(v,u);
		sz[u]+=sz[v];
		if (son[u]==-1 || sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int f){
	bel[u]=f;vis2[u]=0;
	if (son[u]==-1) return;
	dfs2(son[u],f);
	for (int i=0;i<(int)G[u].size();++i){
		Edge& e=edges[G[u][i]];
		if (e.v==fa[u] || e.v==son[u] || !vis2[e.v]) continue;
		dfs2(e.v,e.v);
	}
}
int lca(int u,int v){
	for (;bel[u]!=bel[v];dep[bel[u]]>dep[bel[v]]?u=fa[bel[u]]:v=fa[bel[v]]);
	return dep[u]>dep[v]?v:u;
}
ll getDis(int u,int v){return d[u]+d[v]-2LL*d[lca(u,v)];}
void dijkstra(int S,int u){
	priority_queue<pair<ll,int> >Q;
	for (int i=1;i<=n;++i) dis[S][i]=1000000000000000000LL;
	dis[S][u]=0LL;
	Q.push(MP(0LL,u));
	while (!Q.empty()){
		auto cur=Q.top();Q.pop();
		if (dis[S][cur.second]!=-cur.first) continue;
		for (int i=0;i<(int)G[cur.second].size();++i){
			Edge& e=edges[G[cur.second][i]];
			int v=e.v,w=e.d;
			if (dis[S][v]>dis[S][cur.second]+w){
				dis[S][v]=dis[S][cur.second]+w;
				Q.push(MP(-dis[S][v],v));
			}
		}
	}
}
int main(){
	read(n),read(m);
	for (i=1;i<=m;++i){
		read(u),read(v),read(w);
		addEdge(u,v,w);
	}
	dfs(1,0),dfs2(1,1);
	vector<int>point;
	for (i=0;i<(int)edges.size();i+=2)if(!vis[i]){
		point.PB(edges[i].u);
		point.PB(edges[i].v);
	}	
	sort(point.begin(),point.end());
	point.erase(unique(point.begin(),point.end()),point.end());
	for (i=0;i<(int)point.size();++i) dijkstra(i,point[i]);
	for (read(q);q--;){
		read(u),read(v);
		ll ans=getDis(u,v);
		for (i=0;i<(int)point.size();++i) ans=min(ans,dis[i][u]+dis[i][v]);
		printf("%lld\n",ans);
	}
	return 0;
}