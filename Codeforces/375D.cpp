#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
using namespace std;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=100000+10;
int n,m,i,u,v,k,skip,tot=-1,c[N],sz[N],son[N],ans[N],cnt[N],sum[N],head[N],to[N*2],nxt[N*2];
vector<pair<int,int> >q[N];
void addedge(int u,int v){to[++tot]=v,nxt[tot]=head[u],head[u]=tot;}
inline int lowbit(int x){return x&(-x);}
int get(int x){
    int res=0;
    for (;x>0;x-=lowbit(x)) res+=sum[x];
    return res;
}
void update(int x,int val){for (;x<=N-10;x+=lowbit(x)) sum[x]+=val;}
void dfs(int u,int f){
    sz[u]=1,son[u]=-1;
    for (int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if (v==f) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if (son[u]==-1 || sz[v]>sz[son[u]]) son[u]=v;
    }
}
void add(int u,int f,int val){
    if (val>0){
        if (cnt[c[u]]>0) update(cnt[c[u]],-1);
        cnt[c[u]]+=val;
        update(cnt[c[u]],1);
    }
    else{
        update(cnt[c[u]],-1);
        cnt[c[u]]+=val;
        if (cnt[c[u]]>0) update(cnt[c[u]],1);
    }
    for (int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if (v==f || v==skip) continue;
        add(v,u,val);
    }
}
void dfs(int u,int f,bool keep){
    for (int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if (v==f || v==son[u]) continue;
        dfs(v,u,0);
    }
    if (son[u]!=-1) dfs(son[u],u,1),skip=son[u];
    add(u,f,1);
    for (int i=0;i<(int)q[u].size();i++){
        pair<int,int> cur=q[u][i];
        int id=cur.first,k=cur.second;
        ans[id]=get(N-10)-get(k-1);
    }
    skip=-1;
    if (!keep) add(u,f,-1);
}
int main(){
    memset(head,-1,sizeof(head));
    read(n),read(m);
    for (i=1;i<=n;i++) read(c[i]);
    for (i=1;i<n;i++){
        read(u),read(v);
        addedge(u,v),addedge(v,u);
    }
    for (i=1;i<=m;i++){
        read(v),read(k);
        q[v].pb(MP(i,k));
    }
    dfs(1,0);
    dfs(1,0,0);
    for (i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}
