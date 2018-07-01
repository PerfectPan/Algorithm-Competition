#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=100+10;
int n,i,j,k,tot,primes[N],a[N],info[N],dp[N][1<<16],pre[N][1<<16],num[N][1<<16];
void init(){
	for (i=2;i<=58;i++){
		if (!primes[i]) primes[++primes[0]]=i;
		for (j=1;j<=primes[0]&&i*primes[j]<=58;j++){
			primes[i*primes[j]]=1;
			if (i%primes[j]==0) break;
		}
	}
	for (i=1;i<=58;i++){
		for (j=1;j<=primes[0];j++){
			if (i%primes[j]==0) info[i]|=1<<(j-1);
		}
	}
} 
void print(int idx,int status){
	if (idx==0) return;
	print(idx-1,pre[idx][status]);
	printf("%d%c",num[idx][status],idx==n?'\n':' ');
}
int main(){
	init();
	read(n);
	for (i=1;i<=n;i++) read(a[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for (tot=1<<primes[0],i=0;i<n;i++){
		for (j=0;j<tot;j++){
			for (k=1;k<=58;k++){
				if (((~j)&info[k])!=info[k]) continue;
				if (dp[i][j]+abs(k-a[i+1])<dp[i+1][j|info[k]]){
					dp[i+1][j|info[k]]=dp[i][j]+abs(k-a[i+1]);
					pre[i+1][j|info[k]]=j;
					num[i+1][j|info[k]]=k;
				}
			}
		}
	}
	int res=1<<30;
	for (i=0;i<tot;i++) res=min(res,dp[n][i]);
	for (i=0;i<tot;i++){
		if (dp[n][i]==res){
			print(n,i);
			break;
		}
	}
	return 0;
}