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
const ll INF=1LL<<60;
struct E{
    int l,r,dl,dr;
    E(){}
    E(int _l,int _r,int _dl,int _dr){l=_l;r=_r;dl=_dl;dr=_dr;}
}q[N];
int n,k,i,j,o,L,R,h,t,a[N],cnt[N];
ll cur,f[2][N];
inline void ext(int l,int r,int dl,int dr){
    if (l>r) return;
    q[++t]=E(l,r,dl,dr);
}
inline void ins(int x){cur+=cnt[x]++;}
inline void dec(int x){cur-=--cnt[x];}
inline ll ask(int l,int r){
    while (R<r) ins(a[++R]);
    while (L>l) ins(a[--L]);
    while (R>r) dec(a[R--]);
    while (L<l) dec(a[L++]);
    return cur;
}
// 得到mid的最优决策点 然后分治递归下去
inline void solve(int l,int r,int dl,int dr){
    int mid=l+((r-l)>>1),dm=dl;
    ll&t=f[o][mid];
    for (int i=dl;i<=dr && i<=mid;++i){
        ll now=ask(i,mid)+f[o^1][i-1];
        if (now<t) t=now,dm=i;
    }
    ext(l,mid-1,dl,dm);
    ext(mid+1,r,dm,dr);
}
int main(){
    read(n),read(k);
    for (i=1;i<=n;++i) read(a[i]);
    for (i=1;i<=n;++i){
        cur+=cnt[a[i]];
        cnt[a[i]]++;
        f[o][i]=cur;
    }
    for (j=2;j<=k;++j){
        o^=1;
        for (i=1;i<=n;++i) f[o][i]=INF;
        for (i=1;i<=n;++i) cnt[i]=0;
        cur=0;
        L=1,R=0;
        h=1,t=0;
        ext(j,n,j,n);
        while (h<=t){
            solve(q[h].l,q[h].r,q[h].dl,q[h].dr);
            h++;
        }
    }
    printf("%lld\n",f[o][n]);
    return 0;
}
