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
const int N=2e5+10;
int n,i,u,v,col[N],dp[N],ans[N];
vector<int>G[N];
void dfs(int u,int f){
    dp[u]=col[u]?1:-1;
    for (int v:G[u]){
        if (v==f) continue;
        dfs(v,u);
        dp[u]=max(dp[u],dp[u]+dp[v]);
    }
}
void dfs2(int u,int f){
    ans[u]=dp[u];
    int x=col[u]?1:-1;
    vector<int>pre,suff;
    pre.clear(),suff.clear();
    for (int i=0;i<(int)G[u].size();++i){
        int v=G[u][i];
        pre.PB(max(0,dp[v]));
        if (pre.size()>1) pre[(int)pre.size()-1]+=pre[(int)pre.size()-2];
    }
    for (int i=(int)G[u].size()-1;i>=0;--i){
        int v=G[u][i];
        suff.PB(max(0,dp[v]));
        if (suff.size()>1) suff[(int)suff.size()-1]+=suff[(int)suff.size()-2];
    }

    for (int i=0;i<(int)G[u].size();++i){
        int v=G[u][i];
        if (v==f) continue;
        int x=0,y=0;
        if (i>0) x=pre[i-1];
        if (i+1<(int)G[u].size()) y=suff[(int)G[u].size()-i-2];

        int tmpu=dp[u],tmpv=dp[v];
        dp[u]=x+y+(col[u]?1:-1);
        dp[v]=max(dp[v],dp[v]+dp[u]);
        dfs2(v,u);
        dp[u]=tmpu,dp[v]=tmpv;
    }
}
int main(){
    read(n);
    for (i=1;i<=n;++i) read(col[i]);
    for (i=1;i<n;++i){
        read(u),read(v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1,0);
    dfs2(1,0);
    for (i=1;i<=n;++i) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}