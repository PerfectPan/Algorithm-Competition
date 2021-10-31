#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define MOD 1e9+7
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
template<typename T> inline T gcd(T&a,T&b){return b==0?a:gcd(b,a%b);}
template<typename T> inline T lcm(T&a,T&b){return a/gcd(a,b)*b;}
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
struct Edge{
    int u,v,val;
}a[maxn];
struct _{
    int id,v,k;
}ask[maxn];
int T,n,dfs_clock,q;
vector<int>G[maxn];
int dep[maxn],ans[maxn],fa[maxn],son[maxn],id[maxn],bel[maxn],sz[maxn];
inline bool cmp1(const _&a,const _&b){
    return a.k<b.k;
}
inline bool cmp2(const Edge&a,const Edge&b){
    return a.val<b.val;
}
void dfs1(int u,int f){
    dep[u]=(f==-1?1:dep[f]+1);
    fa[u]=f;
    son[u]=-1;
    sz[u]=1;
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (v==f) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if (son[u]==-1 || sz[v]>sz[son[u]]){
            son[u]=v;
        }
    }
}
void dfs2(int u,int f){
    bel[u]=f;
    id[u]=++dfs_clock;
    if(son[u]==-1) return;
    dfs2(son[u],f);
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (v!=fa[u] && v!=son[u]){
            dfs2(v,v);
        }
    }
}
int Max[maxn<<2];
void update(int root,int l,int r,int id,int v){
    if (l==r){
        Max[root]=v;
        return;
    }
    int mid=l+((r-l)>>1);
    if (id<=mid) update(lson,id,v);
    else update(rson,id,v);
    Max[root]=max(Max[root<<1],Max[root<<1|1]);
}
int query(int root,int l,int r,int L,int R){
    if (L<=l && r<=R){
        return Max[root];
    }
    int mid=l+((r-l)>>1);
    int ret=0;
    if (L<=mid) ret=max(ret,query(lson,L,R));
    if (mid<R) ret=max(ret,query(rson,L,R));
    return ret;
}
int query2(int x){
    int ans=0;
    while (bel[x]!=1){
        ans=max(ans,query(1,1,n,id[bel[x]],id[x]));
        x=fa[bel[x]];
    }
    if (x==1) return ans==0?-1:ans;
    ans=max(ans,query(1,1,n,1,id[x]));
    return ans==0?-1:ans;
}
int main(){
    for (read(T);T;T--){
        read(n);
        for (int i=1;i<=n;i++) G[i].clear();
        memset(Max,0,sizeof(Max));
        for (int i=1;i<n;i++){
            read(a[i].u),read(a[i].v),read(a[i].val);
            G[a[i].u].push_back(a[i].v);
            G[a[i].v].push_back(a[i].u);
        }
        dfs1(1,-1);
        dfs_clock=0;
        dfs2(1,1);
        read(q);
        for(int i=1;i<=q;i++){
            read(ask[i].v),read(ask[i].k);
            ask[i].id=i;
        }
        sort(ask+1,ask+1+q,cmp1);
        sort(a+1,a+n,cmp2);
        int tot=1,c;
        for (int i=1;i<=q;i++){
            while(tot<n && a[tot].val<=ask[i].k){
                update(1,1,n,max(id[a[tot].u],id[a[tot].v]),a[tot].val),tot++;
            }
            ans[ask[i].id]=query2(ask[i].v);
        }
        for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
    }
    return 0;
}