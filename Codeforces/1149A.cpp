#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=4e5+10;
int n,i,j,b,c,sum,a[N],primes[N],ans[N];
bool vis[N];
void init(){
	for (vis[1]=1,i=2;i<=4e5;++i){
		if (!vis[i]) primes[++primes[0]]=i;
		for (j=1;j<=primes[0] && i*primes[j]<=4e5;++j){
			vis[i*primes[j]]=1;
			if (i%primes[j]==0) break;
		}
	}
}
int main(){
	init();
	read(n);
	for (i=1;i<=n;++i){
		read(a[i]),sum+=a[i];
		if (a[i]==1) b++;
		else c++;
	}
	i=1;
	if (c) ans[i++]=2,c--;
	if (b) ans[i++]=1,b--;
	for (;i<=n;++i){
		if (c) ans[i]=2,c--;
		else ans[i]=1;
	} 
	for (i=1;i<=n;++i) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}