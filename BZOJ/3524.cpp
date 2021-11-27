#include <cstdio>
using namespace std;
const int maxn=500000+5;
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
int n,m,q,cnt,ans,root[maxn],sum[maxn*20],ls[maxn*20],rs[maxn*20];
void fIns(int &y,int last,int l,int r,int p){
    sum[y=++cnt]=sum[last]+1;
    if (l==r) return;
    int mid=l+((r-l)>>1);
    ls[y]=ls[last],rs[y]=rs[last];
    if (p<=mid) fIns(ls[y],ls[last],l,mid,p);
    else fIns(rs[y],rs[last],mid+1,r,p);
}
int query(int x,int y,int p){
    int l=1,r=n;
    while (l!=r){
        int mid=l+((r-l)>>1);
        if (sum[ls[y]]-sum[ls[x]]>p) r=mid,x=ls[x],y=ls[y];
        else if (sum[rs[y]]-sum[rs[x]]>p) l=mid+1,x=rs[x],y=rs[y];
        else return 0;
    }
    return l;
}
int main(){
    read(n),read(q);
    for (int i=1;i<=n;i++){
        int x;read(x);
        fIns(root[i],root[i-1],1,n,x);
    }
    for (int i=1;i<=q;i++){
        int l,r;read(l),read(r);
        int detla=(r-l+1)/2;
        printf("%d\n",query(root[l-1],root[r],detla));
    }
    return 0;
}
