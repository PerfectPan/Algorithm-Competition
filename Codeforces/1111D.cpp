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
const int P=1e9+7;
int q,n,i,j,k,x,y,w,f[N],dp[N],inv[N],fac[N],buc[100],ans[100][100];
char s[N];
int fexp(int a,int n){
	int res=1;
	while (n){
		if (n&1) res=1LL*res*a%P;
		a=1LL*a*a%P;
		n>>=1;
	}
	return res;
}
int convert(char ch){
	if (ch>='a' && ch<='z') return ch-'a'+1;
	return ch-'A'+27;
}
inline void up(int&a,int b){a+=b==P?0:b;if(a>=P)a-=P;}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (i=1;i<=n;++i) buc[convert(s[i])]++;
	for (fac[0]=i=1;i<=n;++i) fac[i]=1LL*fac[i-1]*i%P;
	inv[n]=fexp(fac[n],P-2);
	for (i=n-1;i>=0;--i) inv[i]=1LL*inv[i+1]*(i+1)%P;
	w=1LL*fac[n/2]*fac[n/2]%P;
	for (i=1;i<=52;++i) w=1LL*w*inv[buc[i]]%P;
	for (dp[0]=1,i=1;i<=52;++i)if(buc[i]){
		for (j=n/2;j>=buc[i];--j){
			up(dp[j],dp[j-buc[i]]);
		}
	}
	for (i=1;i<=52;++i) ans[i][i]=1LL*w*dp[n/2]%P;
	for (i=1;i<=52;++i)if(buc[i]){
		for (k=0;k<=n/2;++k) f[k]=dp[k];
		for (k=buc[i];k<=n/2;++k) up(f[k],P-f[k-buc[i]]);
		for (j=i+1;j<=52;++j)if(buc[j]){
			for (k=buc[j];k<=n/2;++k) up(f[k],P-f[k-buc[j]]);
			ans[i][j]=ans[j][i]=2LL*w%P*f[n/2]%P;
			for (k=n/2;k>=buc[j];--k) up(f[k],f[k-buc[j]]);
		}
	}
	for (read(q);q--;){
		read(x),read(y);
		x=convert(s[x]),y=convert(s[y]);
		printf("%d\n",ans[x][y]);
	}
	return 0;
}