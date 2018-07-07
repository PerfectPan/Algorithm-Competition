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
const int N=1e5+10;
int n,m,i,a[N];
ll cal(ll x){return x*(x+1)/2LL;}
int main(){
	read(n),read(m);
	for (i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	int cnt=0,flag=0;
	ll ans=0;
	for (i=1;i<=n;i++){
		if (a[i]-1-cnt>=m){
			ans+=cal(m+cnt);
			flag=1;
			break;
		}
		else ans-=a[i],cnt++;
	}
	if (!flag){
		ans+=cal(m+cnt);
	}
	printf("%lld\n",ans);
	return 0;
}