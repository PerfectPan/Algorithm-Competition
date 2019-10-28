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
const int P=1e9+7;
const int N=250+10;
int n,k,i,ans,fac[N],inv[N],f[N];
int fexp(int a,int n){
	int res=1;
	while (n){
		if (n&1) res=(ll)res*a%P;
		a=(ll)a*a%P;
		n>>=1;
	}
	return res;
}
inline int C(int n,int m){return (ll)fac[n]*inv[m]%P*inv[n-m]%P;}
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int main(){
	read(n),read(k);
	for (fac[0]=i=1;i<=n;++i){
		f[i]=fexp((fexp(k,i)-fexp(k-1,i)+P)%P,n);
		fac[i]=(ll)fac[i-1]*i%P;
	}
	for (inv[n]=fexp(fac[n],P-2),i=n-1;i>=0;--i) inv[i]=(ll)inv[i+1]*(i+1)%P;
	for (i=0;i<=n;++i){
		int v=(ll)C(n,i)*fexp(k-1,n*i)%P*f[n-i]%P;
		if (i&1) up(ans,P-v);
		else up(ans,v);
	}
	printf("%d\n",ans);
	return 0;
}