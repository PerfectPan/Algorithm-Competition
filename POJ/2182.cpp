#include <cstdio>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=8000+10;
int n,i,a[N],sum[N<<2],val[N];
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
inline void up(int root){sum[root]=sum[root<<1]+sum[root<<1|1];}
void build(int root,int l,int r){
	sum[root]=0;
	if (l==r){
		sum[root]=1;
		return;
	}
	int mid=l+((r-l)>>1);
	build(lson);
	build(rson);
	up(root);
}
void update(int root,int l,int r,int pos,int v){
	if (l==r){
		sum[root]+=v;
		return;
	}
	int mid=l+((r-l)>>1);
	if (pos<=mid) update(lson,pos,v);
	else update(rson,pos,v);
	up(root);
}
int query(int root,int l,int r,int k){
	if (l==r) return l;
	int mid=l+((r-l)>>1);
	if (sum[root<<1]>=k) return query(lson,k);
	else return query(rson,k-sum[root<<1]);
}
int main(){
	read(n),build(1,1,n);
	for (i=2;i<=n;i++) read(a[i]);
	for (i=n;i>=1;i--){
		val[i]=query(1,1,n,a[i]+1);
		update(1,1,n,val[i],-1);
	}
	for (i=1;i<=n;i++) printf("%d\n",val[i]);
	return 0;
}