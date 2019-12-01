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
const int N=2000+10;
int n,a,i,j,p,dp[N],val[2][N][N],L[2][N],R[2][N],sz[2][N];
vector<int> G[2][N];
void dfs(int u,int tp){
    if (u>1) sz[tp][u]=1;
    for (int i=0;i<(int)G[tp][u].size();++i){
        int v=G[tp][u][i];
        dfs(v,tp);
        L[tp][u]=min(L[tp][u],L[tp][v]);
        R[tp][u]=max(R[tp][u],R[tp][v]);
        sz[tp][u]+=sz[tp][v];
    }
    val[tp][L[tp][u]][R[tp][u]]=sz[tp][u];
}
int main(){
    read(n);
    for (i=0;i<2;++i){
        read(a);
        for (j=2;j<=a;++j){
            read(p);
            G[i][p].push_back(j);
        }
        for (j=1;j<=a;++j) L[i][j]=a+1,R[i][j]=0;
        for (j=1;j<=n;++j){
            read(p);
            L[i][p]=R[i][p]=j;
        }
    }
    dfs(1,0),dfs(1,1);
    for (i=1;i<=n;++i){
        for (j=0;j<i;++j){
            dp[i]=max(dp[i],dp[j]+max(val[0][j+1][i],val[1][j+1][i]));
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}