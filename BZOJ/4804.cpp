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
const int N=10000000+10;
int T,n,i,j,last,primes[N],phi[N];
ll ans,sum[N];
void sieve(){
	for (sum[1]=phi[1]=1,i=2;i<=N-10;i++){
		if (!primes[i]) phi[i]=i-1,primes[++primes[0]]=i;
		for (j=1;j<=primes[0]&&i*primes[j]<=N-10;j++){
			primes[i*primes[j]]=1;
			if (i%primes[j]==0){
				phi[i*primes[j]]=phi[i]*primes[j];
			}
			else phi[i*primes[j]]=phi[i]*(primes[j]-1);
		}
		sum[i]=sum[i-1]+phi[i];
	} 
}
int main(){
	sieve();
	for (read(T);T--;){
		read(n);
		for (ans=0,i=1;i<=n;i=last+1){
			last=n/(n/i);
			ans+=(sum[last]-sum[i-1])*sum[n/i];
		}
		printf("%lld\n",2LL*ans-sum[n]);
	}
	return 0;
}