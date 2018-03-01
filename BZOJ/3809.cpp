#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
const int N=100000+10;
const int M=1000000+10;
int n,m,sz,i,l,r,a,b,ans[M],s[N],block[N],cnt[N],res[N];
struct Query{
    int l,r,a,b,id;
    bool operator<(const Query&rhs)const{
        return block[l]^block[rhs.l]?block[l]<block[rhs.l]:block[l]&1?r<rhs.r:r>rhs.r;
    }
}q[M];
void ins(int x){if(++cnt[x]==1)res[block[x]]++;}
void dec(int x){if(--cnt[x]==0)res[block[x]]--;}
#define umin(a,b) (a>b?b:a)
int query(int a,int b){
    int ret=0,i;
    for (i=a;i<=umin(block[a]*sz,b);i++) ret+=cnt[i];
    if (block[a]!=block[b]){
        for (i=(block[b]-1)*sz+1;i<=b;i++) ret+=cnt[i];
    }
    for (i=block[a]+1;i<=block[b]-1;i++) ret+=res[i];
    return ret;
}
int main(){
    read(n),read(m);
    sz=sqrt(n+0.5);
    for (i=1;i<=n;i++) read(s[i]),block[i]=(i-1)/sz+1;
    for (i=1;i<=m;i++){
        read(q[i].l),read(q[i].r),read(q[i].a),read(q[i].b);
        q[i].id=i;
    }
    sort(q+1,q+1+m);
    for (l=i=1,r=0;i<=m;i++){
        int L=q[i].l,R=q[i].r;
        while (r<R) ins(s[++r]);
        while (l>L) ins(s[--l]);
        while (r>R) dec(s[r--]);
        while (l<L) dec(s[l++]);
        ans[q[i].id]=query(q[i].a,q[i].b);
    }
    for (i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}
