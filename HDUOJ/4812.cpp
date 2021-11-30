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
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define Key_Value ch[ch[root][1]][0]
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
//const int INF=1000000000;
//const int P=1000003;
//下面这种写法快500ms
#define P 1000003
#define INF 1000000000
const double PI=acos(-1.0);
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
int n,k,u,v,ans1,ans2,root,sum,sz[maxn],mp[maxn],f[maxn],id[maxn];
ll inv[maxn],val[maxn],dis[maxn],deep[maxn];
vector<int>G[maxn];
bool vis[maxn];
void pre(){
    inv[1]=1;
    for (int i=2;i<P;i++){
        inv[i]=(((-(P/i))*inv[P%i])%P+P)%P;
    }
}
void getroot(int u,int p){
    sz[u]=1;f[u]=0;
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (v==p || vis[v]) continue;
        getroot(v,u);
        sz[u]+=sz[v];
        f[u]=max(f[u],sz[v]);
    }
    f[u]=max(f[u],sum-f[u]);
    if (f[u]<f[root]) root=u;
}
void query(int x,int id){
    x=inv[x]*k%P;
    int y=mp[x];
    if (!y) return;
    if (y>id) swap(y,id);
    if (y<ans1||(y==ans1&&id<ans2))
        ans1=y,ans2=id;
}
void getdeep(int u,int p){
    deep[++deep[0]]=dis[u];id[deep[0]]=u;
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (v==p || vis[v]) continue;
        dis[v]=(dis[u]*val[v])%P;
        getdeep(v,u);
    }
}
void solve(int u){
    vis[u]=true;
    mp[val[u]]=u;
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (vis[v]) continue;
        deep[0]=0;dis[v]=val[v];
        getdeep(v,u);
        for (int j=1;j<=deep[0];j++) query(deep[j],id[j]);
        deep[0]=0;dis[v]=(val[u]*val[v])%P;
        getdeep(v,u);
        for (int j=1;j<=deep[0];j++){
            if (!mp[deep[j]]) mp[deep[j]]=id[j];
            else mp[deep[j]]=min(mp[deep[j]],id[j]);
        }
    }
    mp[val[u]]=0;
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (vis[v]) continue;
        deep[0]=0;dis[v]=(val[u]*val[v])%P;
        getdeep(v,u);
        for (int j=1;j<=deep[0];j++) mp[deep[j]]=0;
    }
   for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (vis[v]) continue;
        sum=sz[v];root=0;
        getroot(v,root);
        solve(root);
    }
}
int main(){
    pre();
    while (~scanf("%d%d",&n,&k)){
        for (int i=1;i<=n;i++) read(val[i]),vis[i]=false,G[i].clear();
        for (int i=1;i<n;i++){
            read(u),read(v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        sum=n,root=0,f[0]=ans1=ans2=INF;
        getroot(1,0);
        solve(root);
        if (ans1==INF) puts("No solution");
        else printf("%d %d\n",ans1,ans2);
    }
    return 0;
}

