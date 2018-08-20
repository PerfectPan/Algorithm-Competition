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
const int N=50000+10;
int _,a,b,d,i,j,last,ans,mu[N],primes[N],sum[N];
void init(){
	for (sum[1]=mu[1]=1,i=2;i<=50000;i++){
		if (!primes[i]) primes[++primes[0]]=i,mu[i]=-1;
		for (j=1;j<=primes[0]&&i*primes[j]<=50000;j++){
			primes[i*primes[j]]=1;
			if (i%primes[j]==0){
				mu[i*primes[j]]=0;
				break;
			}
			else mu[i*primes[j]]=-mu[i];
		}
		sum[i]=sum[i-1]+mu[i];
	}
}
int main(){
	init();
	for (read(_);_--;){
		read(a),read(b),read(d);
		if (a>b) swap(a,b);
		a/=d,b/=d;
		for (ans=0,i=1;i<=a;i=last+1){
			last=min(a/(a/i),b/(b/i));
			ans+=(sum[last]-sum[i-1])*(a/i)*(b/i);
		}
		printf("%d\n",ans);
	}
	return 0;
}