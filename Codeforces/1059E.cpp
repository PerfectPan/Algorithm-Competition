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
const int N=1e5+10;
int n,i,j,L,v[N],dep[N],in[N],p[N],parent[N][18];
ll S,w[N],ss[N][18];
bool vis[N];
vector<int>G[N];
priority_queue<pair<int,int> >Q;
void dfs(int u,int f){
    dep[u]=dep[f]+1;
    for (int i=0;i<(int)G[u].size();++i){
        int v=G[u][i];
        if (v==f) continue;
        dfs(v,u);
    }
}
void preprocess(){
    for (i=1;i<=n;++i){
        parent[i][0]=p[i];
        ss[i][0]=w[p[i]];
    }
    for (j=1;j<18;++j){
        for (i=1;i<=n && i+(1<<j)<=n;++i){
            parent[i][j]=parent[parent[i][j-1]][j-1];
            ss[i][j]=ss[i][j-1]+ss[parent[i][j-1]][j-1];
        }
    }
}
int main(){
    read(n),read(L),read(S);
    for (i=1;i<=n;++i){
        read(w[i]);
        if (w[i]>S) return puts("-1"),0;
    }
    for (i=2;i<=n;++i){
        read(p[i]);
        G[p[i]].PB(i);
        in[p[i]]++;
    }
    dfs(1,0);
    preprocess();
    for (i=1;i<=n;++i){
        ll limit=L-1,slimit=S-w[i];
        int ins=17,x=i;
        while (ins>=0){
            if (parent[x][ins]==0) ins--;
            else if ((1<<ins)>limit) ins--;
            else if (ss[x][ins]<=slimit){
                slimit-=ss[x][ins];
                limit-=(1<<ins);
                x=parent[x][ins];
            }
            else ins--;
        }
        v[i]=x;
    }
    for (i=1;i<=n;++i)if(in[i]==0)Q.push(MP(dep[i],i));
    int ans=0;
    while (!Q.empty()){
        int u=Q.top().second;Q.pop();
        if (vis[u]) continue;
        int bel=v[u];
        int mid=p[u],pre=u;
        while (dep[mid]>dep[bel]){
            vis[pre]=1;
            p[pre]=bel;
            pre=mid;
            mid=p[mid];
        }
        vis[pre]=vis[bel]=1;
        if (pre!=bel) p[pre]=bel;
        ans++;
        if (p[bel]>0 && !vis[p[bel]]){
            Q.push(MP(dep[p[bel]],p[bel]));
        }
    }
    printf("%d\n",ans);
    return 0;
}