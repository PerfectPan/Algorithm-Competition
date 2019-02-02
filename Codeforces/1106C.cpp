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
const int N=3e5+10;
int i,j;
ll ans,n,a[N];
int main(){
	read(n);
	for (i=1;i<=n;++i) read(a[i]);
	sort(a+1,a+1+n);
	for (i=1,j=n;i<=j;++i,--j){
		ans+=(a[i]+a[j])*(a[i]+a[j]);
	}
	printf("%lld\n",ans);
	return 0;
}