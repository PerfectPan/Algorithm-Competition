#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N = 2e5 + 10;
int n,m,i,u,v,cnt,deg[N],vis[N];
bool flag;
vector<int> G[N];
void dfs(int u, int f) {
    vis[u]=1;
    cnt+=1;
    flag= flag && (deg[u]==2);
    for (auto& v: G[u]) {
        if (v==f) continue;
        if (vis[v]) continue;
        dfs(v,u);
    }
}
int main() {
    read(n),read(m);
    for (i=1;i<=m;++i){
        read(u),read(v);
        deg[u]+=1;
        deg[v]+=1;
        G[u].PB(v);
        G[v].PB(u);
    }
    int x=0;
    for (i=1;i<=n;++i)if (!vis[i]) {
        flag=true;
        cnt=0;
        dfs(i,-1);
        if (flag && cnt > 2) x+=1;
    }
    printf("%d\n",x);
    return 0;
}

