#include <bits/stdc++.h>
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,q,t,g,op;
ll mod,c,sum[maxn<<2],add[maxn<<2],mul[maxn<<2];
inline void paint(int root,int len,ll d,ll v){
    add[root]=(add[root]*v%mod+d)%mod;
    mul[root]=(mul[root]*v)%mod;
    sum[root]=(sum[root]*v%mod+d*len%mod)%mod;
}
inline void pushup(int root){
    sum[root]=(sum[root<<1]+sum[root<<1|1])%mod;
}
inline void pushdown(int root,int len){
    if (add[root]||mul[root]!=1){
        paint(root<<1,len-(len>>1),add[root],mul[root]);
        paint(root<<1|1,len>>1,add[root],mul[root]);
        add[root]=0,mul[root]=1;
    }
}
inline void build(int root,int l,int r){
    add[root]=0,mul[root]=1;
    if (l==r){
        scanf("%lld",&sum[root]);
        sum[root]%=mod;
        return;
    }
    int mid=l+((r-l)>>1);
    build(lson);
    build(rson);
    pushup(root);
}
inline void update(int root,int l,int r,int L,int R,ll a,ll m){
    if (L<=l && r<=R){
        paint(root,r-l+1,a,m);
        return;
    }
    pushdown(root,r-l+1);
    int mid=l+((r-l)>>1);
    if (L<=mid) update(lson,L,R,a,m);
    if (mid<R) update(rson,L,R,a,m);
    pushup(root);
}
inline ll query(int root,int l,int r,int L,int R){
    if (L<=l && r<=R) return sum[root];
    pushdown(root,r-l+1);
    int mid=l+((r-l)>>1);
    ll ret=0;
    if (L<=mid) ret=query(lson,L,R)%mod;
    if (mid<R) ret=(ret+query(rson,L,R))%mod;
    pushup(root);
    return ret;
}
int main(){
    scanf("%d%lld",&n,&mod);
    build(1,1,n);
    for (scanf("%d",&q);q--;){
        scanf("%d%d%d",&op,&t,&g);
        if (op==1){
            scanf("%lld",&c);
            update(1,1,n,t,g,0,c);
        }
        else if (op==2){
            scanf("%lld",&c);
            update(1,1,n,t,g,c,1);
        }
        else printf("%lld\n",query(1,1,n,t,g));
    }
    return 0;
}
