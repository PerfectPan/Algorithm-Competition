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
const int N=2e5+10;
int n,i,pre,a[N];
ll ans;
int main(){
	read(n);
	for (i=1;i<=n;++i) read(a[i]);
	for (ans=pre=a[n],i=n-1;i>=1;--i){
		pre=min(pre-1,a[i]);
		if (pre==0) break;
		ans+=pre;
	}
	printf("%lld\n",ans);
	return 0;
}