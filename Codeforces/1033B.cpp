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
int T;
ll a,b;
bool isPrime(ll x){
	if (x==2LL) return 1;
	for (ll i=2;i*i<=x;++i){
		if (x%i==0) return 0;
	}
	return 1;
}
int main(){
	for (read(T);T--;){
		read(a),read(b);
		if (a-b==1){
			if (isPrime(a+b)) puts("YES");
			else puts("NO");
		}
		else puts("NO");
	}
	return 0;
}