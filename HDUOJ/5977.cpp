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
const int N=50000+10;
const int M=1024+10;
const int INF=2000000000;
int n,k,i,u,v,root,sum,tp[N],sz[N],f[N],cnt[M],num[M];
ll ans;
bool vis[N];
vector<int>G[N];
void getroot(int u,int p){
    sz[u]=1,f[u]=0;
    for (int i=0;i<(int)G[u].size();++i){
        int v=G[u][i];
        if (v==p || vis[v]) continue;
        getroot(v,u);
        sz[u]+=sz[v];
        f[u]=max(f[u],sz[v]);
    }
    f[u]=max(f[u],sum-sz[u]);
    if (f[u]<f[root]) root=u;
}
void getdeep(int u,int p,int now){
    now|=(1<<tp[u]);
    ++cnt[now],++num[now];
    for (int i=0;i<(int)G[u].size();++i){
        int v=G[u][i];
        if (v==p || vis[v]) continue;
        getdeep(v,u,now);
    }    
}
ll cal(int u,int now){
    for (int status=0;status<(1<<k);++status) num[status]=cnt[status]=0;
    getdeep(u,0,now);
    for (int i=0;i<k;++i){
        for (int status=0;status<(1<<k);++status){
            if (!(status&(1<<i))) cnt[status]+=cnt[status|(1<<i)];
        }
    }
    ll res=0,det=0;
    for (int status=0;status<(1<<k);++status){
    	int complement=((1<<k)-1)^status;
    	res+=1LL*num[status]*cnt[complement];
    }
    return res;
}
void solve(int u){
    ans+=cal(u,0);
    vis[u]=1;
    for (int i=0;i<(int)G[u].size();++i){
        int v=G[u][i];
        if (vis[v]) continue;
        ans-=cal(v,(1<<tp[u]));
        sum=sz[v],root=0;
        getroot(v,root);
        solve(root);
    }
}
int main(){
    while (~scanf("%d%d",&n,&k)){
        for (i=1;i<=n;++i){
            read(tp[i]),--tp[i];
            G[i].clear(),vis[i]=0;
        }
        for (i=1;i<n;++i){
            read(u),read(v);
            G[u].PB(v);
            G[v].PB(u);
        }
        root=0,sum=n,f[0]=INF;
        getroot(1,0);
        ans=0,solve(root);
        printf("%lld\n",ans);
    }    
    return 0;
}