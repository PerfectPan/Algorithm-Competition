#include<bits/stdc++.h>
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
const int N=5000+10;
struct Edge{
    int u,v,w;
    bool operator<(const Edge&rhs)const{
        return w>rhs.w;
    }
}e[N];
int n,m,u[N],v[N],i,sz[N],bel[N],fa[N],son[N],dep[N],ans[N],id[N];
vector<int>G[N];
void dfs(int u,int f){
    sz[u]=1,fa[u]=f,son[u]=-1,dep[u]=dep[f]+1;
    for (int i=0;i<(int)G[u].size();++i){
        int v=G[u][i];
        if (v==f) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if (son[u]==-1 || sz[son[u]]<sz[v]) son[u]=v;
    }
}
void dfs2(int u,int f){
    bel[u]=f;
    if (son[u]==-1) return;
    dfs2(son[u],f);
    for (int i=0;i<(int)G[u].size();++i){
        int v=G[u][i];
        if (v==fa[u] || v==son[u]) continue;
        dfs2(v,v);
    }
}
int lca(int u,int v){
    for (;bel[u]!=bel[v];dep[bel[u]]>dep[bel[v]]?u=fa[bel[u]]:v=fa[bel[v]]);
    return dep[u]>dep[v]?v:u;
}
int main(){
    read(n);
    for (i=1;i<n;++i){
        read(u[i]),read(v[i]);
        G[u[i]].PB(v[i]);
        G[v[i]].PB(u[i]);
    }
    dfs(1,0),dfs2(1,1);
    for (i=1;i<n;++i){
        if (dep[u[i]]>dep[v[i]]) id[u[i]]=i;
        else id[v[i]]=i;
    }
    read(m);
    for (i=1;i<=m;++i) read(e[i].u),read(e[i].v),read(e[i].w);
    sort(e+1,e+1+m);
    for (i=1;i<=m;++i){
        int LCA=lca(e[i].u,e[i].v),W=e[i].w;
        int U=e[i].u,V=e[i].v;
        bool flag=0;

        while (U!=LCA){
            if (!ans[id[U]]) ans[id[U]]=W,flag=1;
            else flag|=ans[id[U]]==W;
            U=fa[U];
        }

        while (V!=LCA){
            if (!ans[id[V]]) ans[id[V]]=W,flag=1;
            else flag|=ans[id[V]]==W;
            V=fa[V];
        }
        if (!flag) return puts("-1");
    }
    for (i=1;i<n;++i){
        printf("%d%c",ans[i]?ans[i]:1,i==n-1?'\n':' ');
    }
    return 0;
}