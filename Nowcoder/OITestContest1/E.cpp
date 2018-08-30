#include <bits/stdc++.h>
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
const int N=1e6+10;
const int INF=2000000000;
int n,i,res,a[N],g[N],dp[N];
int main(){
	read(n);
	for (i=1;i<=n;i++) read(a[i]);
	for (i=1;i<=n;i++) g[i]=INF;
	for (i=1;i<=n;i++){
		int k=upper_bound(g+1,g+1+n,a[i])-g;
		dp[i]=k;
		g[k]=a[i];
		res=max(res,k);
	}
	printf("%d\n",res);
	return 0;
}