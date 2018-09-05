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
const int N=1e5+10;
const int INF=2000000000;
int n,m,i,q,u,v,w,sz,cnt,k,dfs_clock,pre[N],point[N],dfn[N],rk[N],siz[N],bel[N],son[N],fa[N],dep[N];
bool vis[N];
ll ans,tmp,dis[N];
set<int>S;
vector<pair<int,int> >G[N];
inline bool cmp(const int&a,const int&b){return dfn[a]<dfn[b];}
void dfs(int u,int f){
    dep[u]=dep[f]+1,siz[u]=1,fa[u]=f,son[u]=-1,dfn[u]=++dfs_clock,rk[dfs_clock]=u;
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i].first,w=G[u][i].second;
        if (v==f) continue;
        dis[v]=dis[u]+w;
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
ll dist(int u,int v){
    return dis[u]+dis[v]-2LL*dis[lca(u,v)];
}
int main(){
    read(n),read(m);
    for (i=1;i<n;i++){
        read(u),read(v),read(w);
        G[u].PB(MP(v,w));
        G[v].PB(MP(u,w));
    }
    dfs(1,0),dfs2(1,1);
    int coff,l,r;
    S.insert(-INF),S.insert(INF);
    for (;m--;){
        read(k);
        if (vis[k]){
            S.erase(dfn[k]);
            coff=-1;
        }
        else{
            S.insert(dfn[k]);
            coff=1;
        }
        vis[k]^=1,l=*--S.lower_bound(dfn[k]),r=*S.upper_bound(dfn[k]);
        if (l!=-INF) ans+=1LL*coff*dist(rk[l],k);
        if (r!=INF) ans+=1LL*coff*dist(rk[r],k);
        if (l!=-INF && r!=INF) ans-=1LL*coff*dist(rk[l],rk[r]);
        if (S.size()>3) tmp=dist(rk[*S.upper_bound(-INF)],rk[*--S.lower_bound(INF)]);
        else tmp=0;
        printf("%lld\n",ans+tmp);
    }
    return 0;
}