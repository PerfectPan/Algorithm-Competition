#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define MOD 1e9+7
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define Key_Value ch[ch[root][1]][0]
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
template<typename T> inline T gcd(T&a,T&b){return b==0?a:gcd(b,a%b);}
template<typename T> inline T lcm(T&a,T&b){return a/gcd(a,b)*b;}
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
int T,n,m;
ll sum[maxn<<2];
int mx[maxn<<2],se[maxn<<2],mc[maxn<<2];
void pushUp(int root){
    sum[root]=sum[root<<1]+sum[root<<1|1];
    mx[root]=max(mx[root<<1],mx[root<<1|1]);
    se[root]=max(se[root<<1],se[root<<1|1]);mc[root]=0;
    if (mx[root<<1]!=mx[root<<1|1]) se[root]=max(se[root],min(mx[root<<1],mx[root<<1|1]));
    if(mx[root]==mx[root<<1]) mc[root]+=mc[root<<1];
    if(mx[root]==mx[root<<1|1]) mc[root]+=mc[root<<1|1];
}
void decTag(int root,int v){
    if (v>=mx[root]) return;
    sum[root]+=1LL*(v-mx[root])*mc[root];
    mx[root]=v;
}
void pushDown(int root){
    decTag(root<<1,mx[root]);
    decTag(root<<1|1,mx[root]);
}
void build(int root,int l,int r){
    if (l==r){
        read(mx[root]);
        sum[root]=mx[root];
        mc[root]=1;
        se[root]=-1;
        return;
    }
    int mid=l+((r-l)>>1);
    build(lson);
    build(rson);
    pushUp(root);
}
void update(int root,int l,int r,int L,int R,int v){
    if (v>=mx[root]) return;
    if (L<=l && r<=R && v>se[root]){
        decTag(root,v);
        return;
    }
    pushDown(root);
    int mid=l+((r-l)>>1);
    if (L<=mid) update(lson,L,R,v);
    if (mid<R) update(rson,L,R,v);
    pushUp(root);
}
int queryMax(int root,int l,int r,int L,int R){
    if (L<=l && r<=R) return mx[root];
    pushDown(root);
    int mid=l+((r-l)>>1);
    int ret=0;
    if (L<=mid) ret=max(ret,queryMax(lson,L,R));
    if (mid<R) ret=max(ret,queryMax(rson,L,R));
    pushUp(root);
    return ret;
}
ll querySum(int root,int l,int r,int L,int R){
    if (L<=l && r<=R) return sum[root];
    pushDown(root);
    int mid=l+((r-l)>>1);
    ll ret=0;
    if (L<=mid) ret+=querySum(lson,L,R);
    if (mid<R) ret+=querySum(rson,L,R);
    pushUp(root);
    return ret;
}
int main(){
    for (read(T);T--;){
        read(n),read(m);
        build(1,1,n);
        for (int i=1,op,x,y,z;i<=m;i++){
            read(op),read(x),read(y);
            if (op==0){
                read(z);
                update(1,1,n,x,y,z);
            }
            if (op==1) printf("%d\n",queryMax(1,1,n,x,y));
            if (op==2) printf("%I64d\n",querySum(1,1,n,x,y));
        }
    }
    return 0;
}

