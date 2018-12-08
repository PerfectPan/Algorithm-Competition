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
const int N=3e5+10;
int n,u,v,i,k;
ll ans=-1000000000000000000LL,a[N],dp[N];
vector<int>G[N];
void dfs(int u,int f,bool flag){
    dp[u]=a[u];
    for (int i=0;i<(int)G[u].size();++i){
        int v=G[u][i];
        if (v==f) continue;
        dfs(v,u,flag);
        dp[u]+=max(dp[v],0LL);
    }
    if (flag) ans=max(ans,dp[u]);
    else if (dp[u]==ans){
        dp[u]=0;
        k++;
    }
}
int main(){
    read(n);
    for (i=1;i<=n;++i) read(a[i]);
    for (i=1;i<n;++i){
        read(u),read(v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1,0,1);
    dfs(1,0,0);
    printf("%lld %d\n",ans*k,k);
    return 0;
}