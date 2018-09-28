#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e6+10;
const ll INF=2000000000000000000LL;
int n,i,u,v,q,k,s,top,dfs_clock,dfn[N],points[N],bel[N],fa[N],son[N],sz[N],dep[N];
bool isVirtual[N];
ll res,dis[N],dp[N][2];
vector<int>G[N],G2[N];
void dfs(int u,int f){
    fa[u]=f,dep[u]=dep[f]+1,sz[u]=1,son[u]=-1,dfn[u]=++dfs_clock;
    for (int i=0;i<(int)G[u].size();i++){
    	int v=G[u][i];
        if (v==f) continue;
        dis[v]=dis[u]+1;
        dfs(v,u);
        sz[u]+=sz[v];
        if (son[u]==-1 || sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int f){
    bel[u]=f;
    if (son[u]==-1) return;
    dfs2(son[u],f);
    for (int i=0;i<(int)G[u].size();i++){
    	int v=G[u][i];
        if (v==fa[u] || v==son[u]) continue;
        dfs2(v,v);
    }
}
int lca(int u,int v){
    for (;bel[u]!=bel[v];dep[bel[u]]>dep[bel[v]]?u=fa[bel[u]]:v=fa[bel[v]]);
    return dep[u]>dep[v]?v:u;
}
void addEdge(int u,int v){
    G2[u].PB(v);
    G2[v].PB(u);
}
void dfs(int u,int f,int tot,ll &mn,ll &mx){
	dp[u][0]=INF,dp[u][1]=0;
	for (int i=0;i<(int)G2[u].size();i++){
    	int v=G2[u][i];
		if (v==f) continue;
		dfs(v,u,tot,mn,mx);
		ll d=abs(dis[u]-dis[v]);
		mn=min(mn,dp[u][0]+dp[v][0]+d);
		mx=max(mx,dp[u][1]+dp[v][1]+d);
		dp[u][0]=min(dp[u][0],dp[v][0]+d);
		dp[u][1]=max(dp[u][1],dp[v][1]+d);
		sz[u]+=sz[v],sz[v]=0;
	}
	if (f) res+=abs(dis[u]-dis[f])*sz[u]*(tot-sz[u]);
	if (isVirtual[u]){
		mn=min(mn,dp[u][0]);
		mx=max(mx,dp[u][1]);
		dp[u][0]=0;
	}
	G2[u].clear();
}
inline bool cmp(const int&a,const int&b){return dfn[a]<dfn[b];}
void build(int points[],int k){
    static int stk[N];
    sort(points,points+k,cmp);

    ll mn=200000000000000000LL,mx=0;
    res=0,top=0,stk[top++]=0;
    bool flag=0;
    for (int i=0;i<k;i++){
        int u=points[i],f=lca(u,stk[top-1]);
        if (f==stk[top-1]) stk[top++]=u;
        else{
            while (top-2>=0 && dep[stk[top-2]]>=dep[f]){
                addEdge(stk[top-1],stk[top-2]);
                top--;
            }
            if (f!=stk[top-1]){
                addEdge(f,stk[top-1]);
                stk[top-1]=f,sz[f]=0;
            }
            stk[top++]=u;
        }
    }
    for (int i=top-2;i>=1;i--) addEdge(stk[i],stk[i+1]);

    dfs(stk[1],0,k,mn,mx),sz[stk[1]]=0;
    printf("%lld %lld %lld\n",res,mn,mx);
}
int main(){
    read(n);
    for (i=1;i<n;i++){
        read(u),read(v);
        G[u].PB(v);
        G[v].PB(u); 
    }
    dfs(1,0),dfs2(1,1);
    for (read(q);q--;){
        read(k);
        for (i=0;i<k;i++){
        	read(points[i]);
        	sz[points[i]]=1;
        	isVirtual[points[i]]=1;
        }
        build(points,k);
        for (i=0;i<k;i++) isVirtual[points[i]]=0;
    }
    return 0;
}