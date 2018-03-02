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
int n,i,l,r,sz,tot,a[N],block[N],mx[N],ans[N];
vector<int>vec;
struct Query{
    int l,r,id;
    bool operator<(const Query&rhs)const{
        return block[l]^block[rhs.l]?block[l]<block[rhs.l]:block[l]&1?r<rhs.r:r>rhs.r;
    }
}q[N];
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
void pushup(int root){mx[root]=max(mx[root<<1],mx[root<<1|1]);}
void update(int root,int l,int r,int x,int val){
    if (l==r){
        mx[root]+=val;
        return;
    }
    int mid=l+((r-l)>>1);
    if (x<=mid) update(lson,x,val);
    else update(rson,x,val);
    pushup(root);
}
int query(int root,int l,int r){
    if (l==r) return vec[l-1];
    int mid=l+((r-l)>>1);
    if (mx[root]==mx[root<<1]) return query(lson);
    return query(rson);
}
void ins(int x){update(1,1,tot,x,1);}
void dec(int x){update(1,1,tot,x,-1);}
void compress(){
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    tot=(int)vec.size();
    for (i=1;i<=n;i++){
        int pos=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin();
        a[i]=pos+1;
    }
}
int main(){
    read(n),sz=sqrt(n+0.5);
    for (i=1;i<=n;i++) read(a[i]),vec.push_back(a[i]),block[i]=(i-1)/sz+1;
    for (i=1;i<=n;i++){
        read(q[i].l),read(q[i].r);
        q[i].id=i;
    }
    compress();
    sort(q+1,q+1+n);
    for (l=i=1,r=0;i<=n;i++){
        int L=q[i].l,R=q[i].r;
        while (r<R) ins(a[++r]);
        while (l>L) ins(a[--l]);
        while (r>R) dec(a[r--]);
        while (l<L) dec(a[l++]);
        ans[q[i].id]=query(1,1,tot);
    }
    for (i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}
