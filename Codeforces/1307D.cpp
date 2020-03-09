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
struct Node{
    int x,d;
    bool operator<(const Node&rhs)const{
        return d<rhs.d;
    }
}b[N];
int n,m,k,i,j,x,y,a[N],rev[N],dis[N],dis2[N];
bool vis[N],vis2[N];
vector<int>G[N],G2[N];
void dfs(int u){
    vis2[u]=1;
    for (int i=0;i<(int)G2[u].size();++i){
        int v=G2[u][i];
        if (vis2[v]) continue;
        dfs(v);
    }
}
inline bool cmp(const int&A,const int&B){
    return dis[A]<dis[B];
}
inline bool cmp2(const int&A,const int&B){
    return dis2[A]<dis2[B];
}
int main(){
    read(n),read(m),read(k);
    for (i=1;i<=k;++i) read(a[i]),rev[i]=a[i];
    for (i=1;i<=m;++i){
        read(x),read(y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    queue<int>Q;
    Q.push(1);vis2[1]=1;
    while (!Q.empty()){
        int x=Q.front();Q.pop();
        for (i=0;i<(int)G[x].size();++i){
            int v=G[x][i];
            if (vis2[v]) continue;
            dis[v]=dis[x]+1;
            Q.push(v);
            vis2[v]=1;
        }
    }

    // for (i=1;i<=n;++i){
    //     for (j=0;j<(int)G[i].size();++j){
    //         int u=i,v=G[i][j];
    //         if (dis[u]==dis[v]+1) G2[u].push_back(v);
    //         // else if (dis[v]==dis[u]+1) G2[v].push_back(u);
    //     }
    // }
    // for (i=1;i<=n;++i) vis2[i]=0;
    // dfs(n);
    // for (i=1;i<=k;++i){
    //     if (!vis2[a[i]]) return printf("%d\n",dis[n]),0;
    //     b[i]=(Node){a[i],dis[a[i]]};
    // }
    
    // sort(b+1,b+1+k);
    // // for (i=1;i<=k;++i) cout<<a[i]<<endl;
    // int ans=dis[n]+1;
    // for (i=1;i<k;++i){
    //     ans=min(ans,dis[b[i+1].x]-dis[b[i].x]);
    // }
    // for (i=1;i<k;++i){
    //     if (ans==dis[b[i+1].x]-dis[b[i].x]){
    //         G[b[i+1].x].push_back(b[i].x);
    //         G[b[i].x].push_back(b[i+1].x);
    //         break;
    //     }
    // }
    Q.push(n);
    for (i=1;i<=n;++i) vis2[i]=0,dis2[i]=0;
    vis2[n]=1;
    while (!Q.empty()){
        int x=Q.front();Q.pop();
        for (i=0;i<(int)G[x].size();++i){
            int v=G[x][i];
            if (vis2[v]) continue;
            dis2[v]=dis2[x]+1;
            Q.push(v);
            vis2[v]=1;
        }
    }
    sort(a+1,a+1+k,cmp);
    sort(rev+1,rev+1+k,cmp2);
    int res=0;
    for (i=1,j=k;i<=k;++i){
        vis[a[i]]=1;
        for (;j && vis[rev[j]];j-=1);

        if (j>0){
            res=max(res,dis[a[i]]+dis2[rev[j]]+1);
        } 
        else break;
    }
    res=min(res,dis[n]);
    printf("%d\n",res);
    return 0;
}