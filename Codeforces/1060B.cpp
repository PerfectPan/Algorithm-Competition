#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
ll n;
ll get(ll x){
	ll ans=0;
	while (x){
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main(){
	read(n);
	ll ans=get(n);
	ll base=1;
	while (base<=n){
		ll a=n-n%base-1;
		ll b=n-a;
		ans=max(ans,get(a)+get(b));
		base*=10LL;
	}
	printf("%lld\n",ans);
	return 0;
}