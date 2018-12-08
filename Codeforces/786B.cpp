#include <bits/stdc++.h>
#define PB emplace_back
#define MP make_pair
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
int n,q,s,i,t,u,v,w,l,r,tot,id[N<<2][2];
ll dis[N*5];
vector<pair<int,int> >G[N*5];
vector<int>vec;
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
inline void add(int u,int v,int w){G[u].PB(MP(v,w));}
void build(int root,int l,int r){
    id[root][0]=++tot,id[root][1]=++tot;
    if (l==r){
        add(id[root][0],l,0);
        add(l,id[root][1],0);
        return;
    }
    int mid=l+((r-l)>>1);
    build(lson);
    build(rson);

    add(id[root][0],id[root<<1][0],0);
    add(id[root][0],id[root<<1|1][0],0);
    add(id[root<<1][1],id[root][1],0);
    add(id[root<<1|1][1],id[root][1],0);
}
void query(int root,int l,int r,int L,int R,int p){
    if (L<=l && r<=R){
        vec.PB(id[root][p]);
        return;
    }
    int mid=l+((r-l)>>1);
    if (L<=mid) query(lson,L,R,p);
    if (mid<R) query(rson,L,R,p);
}
void dijkstra(int s){
    priority_queue<pair<ll,int> >Q;
    for (int i=1;i<=tot;++i) dis[i]=1LL<<60;
    dis[s]=0,Q.push(MP(-dis[s],s));
    while (!Q.empty()){
        auto x=Q.top();Q.pop();
        int u=x.second;
        if (dis[u]!=-x.first) continue;
        for (int i=0;i<(int)G[u].size();++i){
            int v=G[u][i].first,w=G[u][i].second;
            if (dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                Q.push(MP(-dis[v],v));
            }
        }
    }
}
int main(){
    read(n),read(q),read(s);
    tot=n,build(1,1,n);
    for (i=1;i<=q;++i){
        read(t),read(v);
        if (t==1){
            read(u),read(w);
            add(v,u,w);
        }
        else{
            read(l),read(r),read(w);
            vec.clear();
            query(1,1,n,l,r,t-2);
            if (t==2) for (auto x:vec) add(v,x,w);
            else for (auto x:vec) add(x,v,w);
        }
    }
    dijkstra(s);
    for (i=1;i<=n;++i){
        if (dis[i]>=1LL<<50) printf("-1%c",i==n?'\n':' ');
        else printf("%lld%c",dis[i],i==n?'\n':' ');
    }
    return 0;
}