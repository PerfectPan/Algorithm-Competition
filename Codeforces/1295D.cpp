#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e5+10;
int T,tot;
ll a,m,prime[N];
void pre(ll x){
    tot=0;
    for (ll i=2;i*i<=x;++i){
		if (x%i==0){
			prime[tot++]=i;
			while (x%i==0) x/=i;
		}
	}
	if (x>1) prime[tot++]=x;
}
ll work(ll n){
    if (n<=0) return 0;
    ll ans=0,S=1LL<<tot;
    for (ll i=1;i<S;++i){
		int cnt=0;
		ll t=1;
		for (int j=0;j<tot;++j){
			if ((1LL<<j)&i){
				t*=prime[j];
				cnt++;
			}
		}
		if (cnt&1) ans+=n/t;
		else ans-=n/t;
	}
    return ans;
}
int main(){
    for (read(T);T--;){
        read(a),read(m);
        ll g=__gcd(a,m);
        ll limit=(m-1)/g;
        ll A=a/g,B=m/g;
        pre(B);
        ll ans=work(A+limit)-work(A-1);
        printf("%lld\n",limit+1-ans);
    }
    return 0;
}