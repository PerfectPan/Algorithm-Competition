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
int n,mx,i,a,b,c,u,v,ans,dfs_clock,L[N],R[N],dis[N];
vector<int>G[N];
bool vis[N];
queue<int>Q;
void dfs(int u,int f,int dis){
    if (dis>mx){
        mx=dis;
        a=u;
    }
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (v==f) continue;
        dfs(v,u,dis+1);
    }
}
void dfs2(int u,int f){
    L[u]=++dfs_clock;
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (v==f) continue;
        dfs2(v,u);
    }
    R[u]=++dfs_clock;
}
void dfs3(int u,int f){
    Q.push(u);
    vis[u]=1;
    for (int i=0;i<(int)G[u].size();++i){
        int v=G[u][i];
        if (v==f) continue;
        if (L[v]<=L[a] && R[a]<=R[v]){
            dfs3(v,u);
        }
    }
}
int main(){
    read(n);
    for (i=1;i<n;++i){
        read(u),read(v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1,-1,0);b=a;mx=a=0;
    dfs(b,-1,0);
    ans+=mx;
    dfs2(b,-1);
    dfs3(b,-1);
    while (!Q.empty()){
        int x=Q.front();Q.pop();
        for (int i=0;i<(int)G[x].size();++i){
            int v=G[x][i];
            if (!vis[v]){
                dis[v]=dis[x]+1;
                Q.push(v);
                vis[v]=1;
            }
        }
    }
    int xx=-1;c=-1;
    for (int i=1;i<=n;++i)if(i!=a && i!=b){
        if (dis[i]>xx){
            xx=dis[i];
            c=i;
        }
    }
    ans+=xx;
    printf("%d\n",ans);
    printf("%d %d %d\n",a,b,c);
    return 0;
}