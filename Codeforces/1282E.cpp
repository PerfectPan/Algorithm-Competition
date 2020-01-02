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
const int N=1e5+10;
struct Tri{
    int a[3];
}p[N];
int T,n,i,j,deg[N],ans[N],ans2[N];
bool vis[N],vis2[N];
vector<int>be[N],G[N];
map<pair<int,int>,int>mp;
void dfs(int u){
    vis[u]=1;
    ans[++ans[0]]=u;
    for (int i=0;i<(int)G[u].size();++i){
        int v=G[u][i];
        if (vis[v]) continue;
        dfs(v);
    }
}
int main(){
    for (read(T);T--;){
        read(n);
        mp.clear();
        for (i=1;i<=n;++i) be[i].clear(),deg[i]=vis[i]=vis2[i]=0,G[i].clear();
        for (i=1;i<=n-2;++i){
            for (j=0;j<3;++j){
                read(p[i].a[j]);
                be[p[i].a[j]].push_back(i);
                deg[p[i].a[j]]+=1;
            }
            for (j=0;j<3;++j){
                int l=p[i].a[j],r=p[i].a[(j+1)%3];
                if (l>r) swap(l,r);
                mp[MP(l,r)]++; 
            }
        }
        for (i=1;i<=n-2;++i){
            for (j=0;j<3;++j){
                int l=p[i].a[j],r=p[i].a[(j+1)%3];
                if (l>r) swap(l,r);
                if (mp[MP(l,r)]==1){
                    G[l].PB(r);
                    G[r].PB(l);
                }
            }
        }
        ans[0]=ans2[0]=0,dfs(1);
        queue<int>Q;
        for (i=1;i<=n;++i)if(deg[i]==1)Q.push(i);
        while (!Q.empty()){
            int x=Q.front();Q.pop();
            for (i=0;i<(int)be[x].size();++i){
                int v=be[x][i];
                if (vis2[v]) continue;
                ans2[++ans2[0]]=v;
                vis2[v]=1;
                for (j=0;j<3;++j){
                    if (--deg[p[v].a[j]]==1) Q.push(p[v].a[j]);
                }
            }
        }
        for (i=1;i<=ans[0];++i) printf("%d%c",ans[i],i==ans[0]?'\n':' ');
        for (i=1;i<=ans2[0];++i) printf("%d%c",ans2[i],i==ans2[0]?'\n':' ');
    }
    return 0;
}