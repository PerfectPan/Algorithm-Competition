#include <bits/stdc++.h>
#define PB emplace_back
#define MP make_pair
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=2e5+10;
const int P=998244353;
int n,k,i,j,x,a[N],b[N],dp[N][2];
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int fexp(int a,int n){
	int res=1;
	while (n){
		if (n&1) res=1LL*res*a%P;
		a=1LL*a*a%P;
		n>>=1;
	}
	return res;
}
int solve(int a[],int len){
	if (len==0) return 1;
	int cnt,l=1,r=len,ans=0;
	for (;l<=len && a[l]==-1;++l);
	if (l==len+1) return 1LL*k*fexp(k-1,len-1)%P;
	for (;r>=1 && a[r]==-1;--r);
	ans=1LL*fexp(k-1,l-1)*fexp(k-1,len-r)%P;
	for (i=l+1;i<=r-1;i=j+1){
		for (cnt=0,j=i;a[j]==-1;++j) cnt+=1;
		ans=1LL*ans*dp[cnt][a[i-1]!=a[j]]%P;
	}
	return ans;
}
int main(){
	read(n),read(k);
	for (i=1;i<=n;++i){
		read(x);
		if (i&1) a[++a[0]]=x;
		else b[++b[0]]=x;
	}
	for (dp[0][1]=1,i=1;i<=n;++i){
		up(dp[i][0],1LL*dp[i-1][1]*(k-1)%P);
		up(dp[i][1],dp[i-1][0]);
		up(dp[i][1],1LL*dp[i-1][1]*(k-2)%P);
	}
	printf("%d\n",1LL*solve(a,a[0])*solve(b,b[0])%P);
	return 0;
}