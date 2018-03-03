#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=100000+10;
int n,m,i,tot,sz,l,r,res,block[N],a[N],cnt[N],ans[N],b[N];
map<int,int>mp;
struct Query{
    int l,r,id;
    bool operator<(const Query&rhs)const{
        return block[l]^block[rhs.l]?block[l]<block[rhs.l]:block[l]&1?r<rhs.r:r>rhs.r;
    }
}q[N];
int id(int x){
    if (mp.find(x)==mp.end()){
        mp[x]=++tot;
        b[tot]=x;
    }
    return mp[x];
}
void ins(int x){
    cnt[x]++;
    if (cnt[x]==b[x]) res++;
    if (cnt[x]==b[x]+1) res--;
}
void dec(int x){
    cnt[x]--;
    if (cnt[x]==b[x]) res++;
    if (cnt[x]==b[x]-1) res--;
}
int main(){
    read(n),read(m),sz=sqrt(n+0.5);
    for (i=1;i<=n;i++) read(a[i]),a[i]=id(a[i]),block[i]=(i-1)/sz+1;
    for (i=1;i<=m;i++){
        read(q[i].l),read(q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+1+m);
    for (l=i=1,r=0;i<=m;i++){
        int L=q[i].l,R=q[i].r;
        while (r<R) ins(a[++r]);
        while (l>L) ins(a[--l]);
        while (r>R) dec(a[r--]);
        while (l<L) dec(a[l++]);
        ans[q[i].id]=res;
    }
    for (i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}
