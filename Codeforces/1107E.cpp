#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=100+10;
int n,i,a[N];
char s[N];
ll dp[N][N][N];
ll cal(int l,int r,int k){
	if (l>r) return 0;
	if (l==r) return a[k+1];
	if (~dp[l][r][k]) return dp[l][r][k];
	dp[l][r][k]=cal(l,r-1,0)+a[k+1];
	for (int i=l;i<r;++i){
		if (s[i]==s[r]){
			dp[l][r][k]=max(dp[l][r][k],cal(l,i,k+1)+cal(i+1,r-1,0));
		}
	}
	return dp[l][r][k];
}
int main(){
	memset(dp,-1,sizeof(dp));
	read(n);
	scanf("%s",s+1);
	for (i=1;i<=n;++i) read(a[i]);
	printf("%lld\n",cal(1,n,0));
	return 0;
}