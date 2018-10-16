#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=2e5+10;
const int INF=2000000000+10;
struct P{
	int u,v,w;
	bool operator<(const P&rhs)const{
		return w>rhs.w;
	}
};
int T,n,m,tot,ans,i,j,q,p,u,v,w,l,a,k,s,v0,p0,dep[N<<1],dis[N],f[N<<1],dp[N<<1],fa[N<<1],val[N<<1],parent[N<<1][18];
vector<pair<int,int> >G[N];
vector<int>G2[N<<1];
vector<P>edge;
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
void dijkstra(){
	priority_queue<pair<int,int> >Q;
	for (i=1;i<=n;++i) dis[i]=INF;
	dis[1]=0;
	Q.push(MP(-dis[1],1));
	while (!Q.empty()){
		pair<int,int> cur=Q.top();Q.pop();
		if (-cur.first!=dis[cur.second]) continue;
		for (int i=0;i<(int)G[cur.second].size();++i){
			int v=G[cur.second][i].first,w=G[cur.second][i].second;
			if (dis[v]>dis[cur.second]+w){
				dis[v]=dis[cur.second]+w;
				Q.push(MP(-dis[v],v));
			}
		}
	}
} 
void dfs(int u,int F){
	f[u]=F,dep[u]=dep[F]+1;
	dp[u]=u<=n?dis[u]:INF;
	for (int i=0;i<(int)G2[u].size();++i){
		int v=G2[u][i];
		dfs(v,u);
		dp[u]=min(dp[u],dp[v]);
	}
}
void preprocess(){
	memset(parent,0,sizeof(parent));
	for (i=1;i<=tot;++i) parent[i][0]=f[i];
	for (j=1;j<18;++j){
		for (i=1;i<=tot && i+(1<<j)<=tot;++i)if(parent[i][j-1]){
			parent[i][j]=parent[parent[i][j-1]][j-1];
		}
	}
}
int main(){
	for (read(T);T--;){
		read(n),read(m);
		for (i=1;i<=n;++i) G[i].clear(),fa[i]=i,val[i]=INF;
		edge.clear();
		for (i=1;i<=m;++i){
			read(u),read(v),read(l),read(a);
			G[u].PB(MP(v,l));
			G[v].PB(MP(u,l));
			edge.PB((P){u,v,a});
		}
		sort(edge.begin(),edge.end());
		dijkstra();
		for (tot=n,i=0;i<(int)edge.size();++i){
			int u=edge[i].u,v=edge[i].v,w=edge[i].w;
			int fu=Find(u),fv=Find(v);
			if (fu^fv){
				fa[fu]=fa[fv]=++tot;
				fa[tot]=tot;
				val[tot]=w;
				G2[tot].PB(fu),G2[tot].PB(fv);
			}
		}
		f[tot]=0,dfs(tot,0);
		preprocess();
		for (ans=0,read(q),read(k),read(s);q--;){
			read(v0),read(p0);
			v=(v0+k*ans-1)%n+1;
			p=(p0+k*ans)%(s+1);
			for (i=17;i>=0;--i){
				if (parent[v][i] && val[parent[v][i]]>p) v=parent[v][i];
			}
			ans=dp[v];
			printf("%d\n",ans);
		}
		for (i=1;i<=tot;++i) G2[i].clear();
	} 
	return 0;
}