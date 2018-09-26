#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=2e5+10;
const int P=1e9+7;
int n,q,i,x,y,a[N],w[N],pres[N],sum2[N];
ll sum[N],prew[N];
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
inline int lowbit(int x){return x&(-x);}
void add1(int x,int val){for(;x<=n;x+=lowbit(x))sum[x]+=val;}
void add2(int x,int val){for(;x<=n;x+=lowbit(x))up(sum2[x],val);}
ll get1(int x){
	ll res=0;
	for (;x>0;x-=lowbit(x)) res+=sum[x];
	return res;
}
int get2(int x){
	int res=0;
	for (;x>0;x-=lowbit(x)) up(res,sum2[x]);
	return res;
}
void revise(int pos,int nw){
	add1(pos,-w[pos]);
	add2(pos,(-1LL*w[pos]*a[pos]%P+P)%P);
	w[pos]=nw;
	add1(pos,w[pos]);
	add2(pos,(1LL*w[pos]*a[pos]%P+P)%P);
}
void work(int L,int R){
	ll t=get1(L-1);
	ll tot=get1(R)-get1(L-1);
	int l=L,r=R,pos=R;
	while (l<=r){
		int mid=l+((r-l)>>1);
		ll v=get1(mid)-t;
		if (v*2LL>=tot){
			r=mid-1;
			pos=mid;
		}
		else l=mid+1;
	}
	ll A=get2(pos)-get2(L-1);
	ll B=get2(R)-get2(pos);
	ll C=-1LL*a[pos]*((get1(pos)-t)%P)%P;
	ll D=-1LL*a[pos]*((get1(R)-get1(pos))%P)%P;
	ll res=(B+D-A-C)%P;
	if (res<0) res+=P;
	printf("%lld\n",res);
}
int main(){
	read(n),read(q);
	for (i=1;i<=n;++i){
		read(a[i]);
		a[i]-=i;
	}
	for (i=1;i<=n;++i){
		read(w[i]);
		prew[i]=prew[i-1]+w[i];
		sum[i]=prew[i]-prew[i-lowbit(i)];
	
		pres[i]=(pres[i-1]+1LL*a[i]*w[i]%P)%P;
		if (pres[i]<0) pres[i]+=P;
		sum2[i]=pres[i]-pres[i-lowbit(i)];
		if (sum2[i]<0) sum2[i]+=P;
	}
	for (;q--;){
		read(x),read(y);
		if (x<0) revise(-x,y);
		else work(x,y);
	}
	return 0;
}