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
const int N=1e5+10;
int n,i,l[N],r[N],val;
ll ans;
int main(){n
	read(n);
	for (i=1;i<=n;++i) read(l[i]),read(r[i]);
	sort(l+1,l+1+n);
	sort(r+1,r+1+n);
	ans=n;
	for (i=1;i<=n;++i) ans+=max(l[i],r[i]);
	printf("%lld\n",ans);
	return 0;
}