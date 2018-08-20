#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=20+10;
const int P=1000000007;
ll s,f[N];
int n,i,status,ans,inv[N];
int fexp(int a,int n){
	int res=1;
	for(;n;n>>=1,a=(ll)a*a%P)if(n&1)res=(ll)res*a%P;
	return res;
}
/*int C(int n,int m){
    if (n<m) return 0;
    int res=1,i;
    for (i=0;i<m;i++) res=(ll)res*(n-i)%P;
    for (i=1;i<=m;i++) res=(ll)res*inv[i]%P;
    return res;
}
int lucas(ll n,int m){
    if (n<m) return 0;
    if (!m || n==m) return 1;
    return 1LL*C(n%P,m%P)*lucas(n/P,m/P)%P;
}*/
int C(ll n,int m){
	if (n<0||m<0||n<m) return 0;
	int res=1;
	for (ll i=n;i>n-m;i--) res=(ll)res*(i>=P?i%P:i)%P;
	for (int i=1;i<=m;i++) res=(ll)res*inv[i]%P;
	return res;
}
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int main(){
	for (i=1;i<=20;i++) inv[i]=fexp(i,P-2);
	read(n),read(s);
	for (i=1;i<=n;i++) read(f[i]);
	for (status=0;status<(1<<n);status++){
		if (status==0) up(ans,C(n+s-1,n-1));
		else{
			ll t=n+s;
			int cnt=0;
			for (i=0;i<n;i++)if(status&(1<<i)){
				cnt++;
				t-=f[i+1];
			}
			t-=cnt+1;
			if (cnt&1) up(ans,P-C(t,n-1));
			else up(ans,C(t,n-1));
		}
	}
	printf("%d\n",ans);
	return 0;
}