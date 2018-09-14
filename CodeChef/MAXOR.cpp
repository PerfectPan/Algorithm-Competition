#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=1e6+10;
const int M=(1<<20)+10;
int T,n,status,i,a[N],f[M],num[M];
int main(){
	for (read(T);T--;){
		read(n);
		memset(f,0,sizeof(f));
		memset(num,0,sizeof(num));
		ll ans=0;
		for (i=1;i<=n;++i){
			read(a[i]);
			f[a[i]]++;
			num[a[i]]++;
		}
		for (i=0;i<20;++i){
			for (status=0;status<(1<<20);++status){
				if (status&(1<<i)) f[status]+=f[status^(1<<i)];
			}
		}
		for (i=1;i<=n;++i){
			ans+=f[a[i]]-num[a[i]];
		}
		for (status=0;status<(1<<20);++status)if(num[status]){
			ans+=1LL*num[status]*(num[status]-1)/2LL;
		}
		printf("%lld\n",ans);
	}
	return 0;
}