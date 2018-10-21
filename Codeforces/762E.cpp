#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=100000+10;
const int M=N*30;
const int F=1e4+10;
const int INF=1e9;
struct Node{
	int x,r,f;
	bool operator<(const Node&rhs)const{
		return x<rhs.x;
	}
}a[N];
int n,m,i,j,k,tot,rk[N],root[F],ls[M],rs[M],val[M];
ll ans;
inline bool cmp(int x,int y){return a[x].x+a[x].r<a[y].x+a[y].r;}
void modify(int&o,int l,int r,int pos,int v){
	if (!o) o=++tot;
	val[o]+=v;
	if (l==r) return;
	int mid=l+((r-l)>>1);
	if (pos<=mid) modify(ls[o],l,mid,pos,v);
	else modify(rs[o],mid+1,r,pos,v);
}
int query(int o,int l,int r,int pos){
	if (!o) return 0;
	if (l>=pos) return val[o];
	int mid=l+((r-l)>>1);
	if (pos<=mid) return query(ls[o],l,mid,pos)+val[rs[o]];
	else return query(rs[o],mid+1,r,pos);
}
int main(){
	read(n),read(m);
	for (i=1;i<=n;++i) read(a[i].x),read(a[i].r),read(a[i].f),rk[i]=i;
	sort(a+1,a+1+n);sort(rk+1,rk+1+n,cmp);	
	for (i=j=1;i<=n;++i){
		while (j<=n && a[rk[j]].x+a[rk[j]].r<a[i].x) modify(root[a[rk[j]].f],1,INF,a[rk[j]].x,-1),++j;
		for (k=max(a[i].f-m,1);k<=min(a[i].f+m,10000);++k) ans+=query(root[k],1,INF,max(a[i].x-a[i].r,1));
		modify(root[a[i].f],1,INF,a[i].x,1);
	}
	printf("%lld\n",ans);
	return 0;
}