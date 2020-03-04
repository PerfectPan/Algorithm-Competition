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
const int N=1000+10;
int n,u,v,i,s,rt,a,b,dfs_clock,mx,L[N],R[N];
bool vis[N];
vector<int>G[N];
void dfs(int u,int f,int dis){
    L[u]=++dfs_clock;
    if (dis>mx){
        mx=dis;
        s=u;
    }
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (v==f || vis[v]) continue;
        dfs(v,u,dis+1);
    }
    R[u]=dfs_clock;
}
void dfs2(int u,int f){
    vis[u]=1;
    for (int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if (v==f || vis[v]) continue;
        if (L[v]<=L[b] && R[b]<=R[v]) dfs2(v,u);
    }
}
int main(){
    read(n);
    for (i=1;i<n;++i){
        read(u),read(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rt=1;
    for (;;){
        dfs_clock=0,mx=-1;
        dfs(rt,-1,0);
        // if (rt==4) printf("%d\n",s);
        a=s;
        dfs_clock=0,mx=-1;
        dfs(s,-1,0);
        b=s;
        dfs2(a,-1);
        if (a==b){
            printf("! %d\n",a);
            fflush(stdout);
            break;
        }
        printf("? %d %d\n",a,b);
        fflush(stdout);
        scanf("%d",&rt);
        if (rt==a || rt==b){
            printf("! %d\n",rt);
            fflush(stdout);
            break;
        }
        vis[rt]=0;
    }
    return 0;
}