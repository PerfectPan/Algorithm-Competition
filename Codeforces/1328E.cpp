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
int n,m,u,v,dfs_clock,i,k,a[N],L[N],R[N],fa[N];
vector<int>G[N];
void dfs(int u,int f){
    L[u]=R[u]=++dfs_clock;
    fa[u]=f;
    for (auto v:G[u]){
        if (v==f) continue;
        dfs(v,u);
    }
    R[u]=dfs_clock;
}
inline bool cmp(const int&A,const int&B){
    return L[A]<L[B];
}
int main(){
    read(n),read(m);
    for (i=1;i<n;++i){
        read(u),read(v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1,1);
    for (;m--;){
        read(k);
        for (i=1;i<=k;++i) read(a[i]),a[i]=fa[a[i]];
        sort(a+1,a+1+k,cmp);
        bool flag=1;
        for (i=2;i<=k;++i){
            if (!(L[a[i-1]]<=L[a[i]] && R[a[i]]<=R[a[i-1]])){
                flag=0;
                break;
            }
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}