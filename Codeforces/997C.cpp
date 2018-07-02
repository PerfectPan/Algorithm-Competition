#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x; 
}
const int N=1000000+10;
const int P=998244353;
int ans,res,n,i,po[N],jc[N],inv[N];
int ksm(int a,ll n){
	int res=1;
	while (n){
		if (n&1) res=1LL*res*a%P;
		a=1LL*a*a%P;
		n>>=1LL;
	}
	return res;
}
int main(){
	read(n);
	for (jc[0]=po[0]=1,i=1;i<=n;i++){
		jc[i]=1LL*jc[i-1]*i%P;
		inv[i]=ksm(jc[i],P-2);
		po[i]=po[i-1]*3LL%P;
	}

	for (i=1;i<=n;i++){
		int c;
		if (i==n) c=1;
		else{
			c=1LL*jc[n]*inv[i]%P;
			c=1LL*c*inv[n-i]%P;
		}
		int d=1LL*ksm(3,i)*ksm(3,1LL*n*(n-i))%P;
		d=1LL*d*c%P;
		if ((i+1)&1) res-=2LL*d%P;
		else res+=2LL*d%P;
		res%=P;if (res<0) res+=P;
	}
	
	for (i=0;i<=n-1;i++){
		int c=1LL*jc[n]*inv[i]%P;
		c=1LL*c*inv[n-i]%P;
		if (i==0) c=1;

		int d=-po[i];
		d%=P;if (d<0) d+=P;
		
		int tmp=(1+d)%P;
		tmp=ksm(tmp,n)-ksm(d,n);
		tmp%=P;if (tmp<0) tmp+=P;

		tmp=1LL*tmp*c%P;
		if ((i+1)&1) ans-=tmp;
		else ans+=tmp;

		ans%=P;if (ans<0) ans+=P;	
	}
	ans=3LL*ans%P;
	ans=(ans+res)%P;
	printf("%d\n",ans);
	return 0;
}