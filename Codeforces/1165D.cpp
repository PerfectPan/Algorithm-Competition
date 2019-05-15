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
const int N=300+10;
int T,n,i,j,d[N];
int main(){
	for (read(T);T--;){
		read(n);
		for (i=1;i<=n;++i) read(d[i]);
		sort(d+1,d+1+n);
		ll ans=(ll)d[1]*d[n];
		for (i=2,j=n-1;i<=j;++i,--j){
			if (ans!=(ll)d[i]*d[j]){
				ans=-1;
				break;
			}
		}
		if (ans!=-1){
			int m=(int)sqrt(ans+0.5),cnt=0;
			for (i=2;i<=m;++i){
				if (ans%i==0){
					cnt++;
					if (ans/i!=i) cnt++;
				}
			}
			if (cnt!=n) ans=-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}