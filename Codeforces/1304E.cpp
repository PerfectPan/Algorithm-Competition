#include<bits/stdc++.h>
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
const int N=1e5+10;
int n,q,i,rt,op,u,v,x,dfs_clock,a[N],rk[N],L[N],R[N],fa[N],son[N],sz[N],dep[N],bel[N];
vector<int>G[N];
void dfs(int u,int f){
    dep[u]=dep[f]+1,son[u]=-1,sz[u]=1,fa[u]=f;
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (v==f) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if (son[u]==-1 || sz[son[u]]<sz[v]) son[u]=v;
    }
}
void dfs2(int u,int f){
    bel[u]=f;
    L[u]=R[u]=++dfs_clock;
    rk[dfs_clock]=u;
    if (son[u]==-1) return;
    dfs2(son[u],f);
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
    R[u]=dfs_clock;
}
int lca(int u,int v){
    for (;bel[u]!=bel[v];dep[bel[u]]>dep[bel[v]]?u=fa[bel[u]]:v=fa[bel[v]]);
    return dep[u]>dep[v]?v:u;
}
int main(){
    read(n);
    for (i=1;i<n;++i){
        read(u),read(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0),dfs2(1,1);
    for (read(q);q--;){
        int x,y,a,b,k;
        read(x),read(y),read(a),read(b),read(k);

        int LCA=lca(a,b);
        int tot=dep[b]+dep[a]-dep[LCA]*2;
        if (tot%2==k%2){
            if (tot<=k) puts("YES");
            else{
                int LCA2=lca(a,x);
                int LCA3=lca(b,y);

                int tot2=dep[a]+dep[x]-dep[LCA2]*2;
                int tot3=dep[b]+dep[y]-dep[LCA3]*2;

                if ((tot2+tot3+1)%2==k%2 && (tot2+tot3+1)<=k) puts("YES");
                else{
                    LCA2=lca(a,y);
                    LCA3=lca(b,x);

                    tot2=dep[a]+dep[y]-dep[LCA2]*2;
                    tot3=dep[b]+dep[x]-dep[LCA3]*2;
                    if ((tot2+tot3+1)%2==k%2 && (tot2+tot3+1)<=k) puts("YES");
                    else puts("NO");
                }
            }
        }
        else{
            int LCA2=lca(a,x);
            int LCA3=lca(b,y);

            int tot2=dep[a]+dep[x]-dep[LCA2]*2;
            int tot3=dep[b]+dep[y]-dep[LCA3]*2;

            if ((tot2+tot3+1)%2==k%2 && (tot2+tot3+1)<=k) puts("YES");
            else{
                LCA2=lca(a,y);
                LCA3=lca(b,x);

                tot2=dep[a]+dep[y]-dep[LCA2]*2;
                tot3=dep[b]+dep[x]-dep[LCA3]*2;
                if ((tot2+tot3+1)%2==k%2 && (tot2+tot3+1)<=k) puts("YES");
                else puts("NO");
            }
        }
    }
    return 0;
}