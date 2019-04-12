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
int n,m,p,l,r,h,t,i,j,q[N];
ll d[N],a[N],S[N],dp[105][N];
inline ll getAns(int i,int j,int k){return dp[i-1][k]+a[j]*(j-k)-(S[j]-S[k]);}
inline ll getY(int i,int k){return dp[i-1][k]+S[k];}
int main(){
	read(n),read(m),read(p);
	for (i=2;i<=n;++i){
		read(d[i]);
		d[i]+=d[i-1];
	}
	for (i=1;i<=m;++i){
		read(h),read(t);
		a[i]=t-d[h];
	}
	sort(a+1,a+1+m);
	for (i=1;i<=m;++i) S[i]=S[i-1]+a[i];
	memset(dp,0x3f,sizeof(dp));
	for (dp[0][0]=0,i=1;i<=p;++i){
		q[l=r=1]=0;
		for (j=1;j<=m;++j){
			while (l<r && getY(i,q[l+1])-getY(i,q[l])<=a[j]*(q[l+1]-q[l])) l++;
			dp[i][j]=min(dp[i-1][j],getAns(i,j,q[l]));
			while (l<r && (getY(i,q[r])-getY(i,q[r-1]))*(j-q[r])>=(getY(i,j)-getY(i,q[r]))*(q[r]-q[r-1])) r--;
			q[++r]=j;
		}
	}
	printf("%lld\n",dp[p][m]);
	return 0;
}