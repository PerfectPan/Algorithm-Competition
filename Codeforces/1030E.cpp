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
const int N=3e5+10;
int n,i,j,res,suf,b[N],cnt[2][N];
ll ans,a[N];
int main(){
	read(n);
	for (i=1;i<=n;++i){
		read(a[i]);
		b[i]=__builtin_popcountll(a[i]);
	}
	cnt[0][n+1]=1;
	for (i=n;i>=1;--i){
		int sum=0,mx=0,delta=0;
		for (j=i;j<=min(n,i+65);++j){
			sum+=b[j];
			mx=max(mx,b[j]);
			if (mx>sum-mx && sum%2==0) --delta;
		}
		suf+=b[i];
		delta+=cnt[suf&1][i+1];
		ans+=delta;

		cnt[0][i]=cnt[0][i+1];
		cnt[1][i]=cnt[1][i+1];
		++cnt[suf&1][i];
	}
	printf("%lld\n",ans);
	return 0;
}