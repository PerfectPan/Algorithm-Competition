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
const int N=3e5+10;
struct Node{
	ll sum,pre,suff;
}p[N<<2];
int n,i,l[N],r[N];
ll ans,a,td[N],d[N],c[N];
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
void pushup(int root){
	p[root].sum=p[root<<1].sum+p[root<<1|1].sum;
	p[root].pre=max(p[root<<1].pre,p[root<<1].sum+p[root<<1|1].pre);
	p[root].suff=max(p[root<<1|1].suff,p[root<<1].suff+p[root<<1|1].sum);
}
void build(int root,int l,int r){
	if (l==r){
		p[root].sum=p[root].pre=p[root].suff=c[l];
		return;
	}
	int mid=l+((r-l)>>1);
	build(lson);
	build(rson);
	pushup(root);
}
pair<ll,ll> MergePre(const pair<ll,ll>&A,const pair<ll,ll>&B){
	pair<ll,ll> res=A;
	res.first+=B.first;
	res.second=max(res.second,A.first+B.second);
	return res;
}
pair<ll,ll> queryPre(int root,int l,int r,int L,int R){
	if (L<=l && r<=R) return MP(p[root].sum,p[root].pre);
	int mid=l+((r-l)>>1);
	if (L>mid) return queryPre(rson,L,R);
	else if (R<=mid) return queryPre(lson,L,R);
	else return MergePre(queryPre(lson,L,R),queryPre(rson,L,R)); 
}
pair<ll,ll> MergeSuff(const pair<ll,ll>&A,const pair<ll,ll>&B){
	pair<ll,ll> res=B;
	res.first+=A.first;
	res.second=max(res.second,A.second+B.first);
	return res;
}
pair<ll,ll> querySuff(int root,int l,int r,int L,int R){
	if (L<=l && r<=R) return MP(p[root].sum,p[root].suff);
	int mid=l+((r-l)>>1);
	if (L>mid) return querySuff(rson,L,R);
	else if (R<=mid) return querySuff(lson,L,R);
	else return MergeSuff(querySuff(lson,L,R),querySuff(rson,L,R)); 
}
int main(){
	read(n),read(a);
	for (i=1;i<=n;++i){
		read(d[i]),read(c[i]);
		td[i]=d[i]-d[i-1];
		c[i]=a-c[i];
		l[i]=r[i]=i;
		ans=max(ans,c[i]);
	}
	build(1,1,n);
	for (i=2;i<=n;++i){
		int cur=i;
		while (cur>1 && td[i]>=td[cur-1]) cur=l[cur-1];
		l[i]=cur;
	}
	for (i=n-1;i>=1;--i){
		int cur=i;
		while (cur<n && td[i]>=td[cur+1]) cur=r[cur+1];
		r[i]=cur;
	}
	for (i=2;i<=n;++i){
		ans=max(ans,querySuff(1,1,n,max(l[i]-1,1),i-1).second+queryPre(1,1,n,i,r[i]).second-1LL*td[i]*td[i]);
	}
	printf("%lld\n",ans);
	return 0;
}