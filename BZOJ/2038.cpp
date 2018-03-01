#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return _f?-x:x;
}
const int N=50000+10;
int n,m,sz,i,l,r,Q,f[N],c[N];
ll a,b,g;
pair<ll,ll>ans[N];
struct Query{
    int l,r,id,pos;
    bool operator<(const Query&rhs)const{
        return pos^rhs.pos?pos<rhs.pos:pos&1?r<rhs.r:r>rhs.r;
    }
}q[N];
void ins(int&x){a+=f[x]*2LL;f[x]++;}
void dec(int&x){a-=f[x]*2LL-2LL;f[x]--;}
int main(){
    read(n),read(m);
    sz=n/sqrt((m>>1)/3);
    for (i=1;i<=n;i++) read(c[i]);
    for (i=1;i<=m;i++){
        read(q[i].l),read(q[i].r);
        q[i].id=i;
        q[i].pos=(q[i].l-1)/sz+1;
    }
    sort(q+1,q+1+m);
    for (i=l=1,r=0;i<=m;i++){
        int L=q[i].l,R=q[i].r;
        while (r<R) ins(c[++r]);
        while (l>L) ins(c[--l]);
        while (r>R) dec(c[r--]);
        while (l<L) dec(c[l++]);
        if (L^R){
            b=1LL*(R-L+1)*(R-L),g=__gcd(a,b);
            ans[q[i].id]=make_pair(a/g,b/g);
        }
        else ans[q[i].id]=make_pair(0LL,1LL);
    }
    for (i=1;i<=m;i++) printf("%lld/%lld\n",ans[i].first,ans[i].second);
    return 0;
}
