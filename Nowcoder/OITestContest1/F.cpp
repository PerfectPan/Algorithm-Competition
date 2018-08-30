#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int P=1e9+7;
const int N=1000+10;
int T,n,k,i,j,ans,a[N],comb[N][N];
void init(){
	for (comb[0][0]=1,i=1;i<=1000;i++){
		comb[i][0]=1;
		for (j=1;j<=i;j++){
			comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%(P-1);
		}
	}
}
int C(int n,int m){
	if (m<0||m>n) return 0;
	return comb[n][m];
}
int fexp(int a,int n){
	int res=1;
	while (n){
		if (n&1) res=1LL*res*a%P;
		a=1LL*a*a%P;
		n>>=1;
	}
	return res;
}
int main(){
	init();
	for (read(T);T--;){
		read(n),read(k);
		int constant=C(n-1,k-1);
		for (ans=1,i=1;i<=n;i++) read(a[i]);
		sort(a+1,a+1+n);
		for (i=1;i<=n;i++){
			int big=C(n-i,k-1),small=C(i-1,k-1);
			int tot=constant-big-small;
			tot%=(P-1);
			if (tot<0) tot+=(P-1);
			ans=1LL*ans*fexp(a[i],tot)%P;
		}
		printf("%d\n",ans);
	}
	return 0;
}