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
int n,i,left2;
ll tot,k,m,sum,ans,a[N];
void up(ll x,ll y,ll&sum,ll&ans){
	if (x*ans>y*sum){
		sum=x;
		ans=y;
	}
}
int main(){
	read(n),read(k),read(m);
	for (i=1;i<=n;++i) read(a[i]),sum+=a[i];
	sort(a+1,a+1+n);
	ans=n;
	for (tot=sum,left2=n,i=0;i<n;++i){
		if (i==m+1) break;
		tot-=a[i];
		ll tmp=tot;
		if (left2*k>=(m-i)) tmp+=m-i;
		else tmp+=left2*k;
		up(tmp,left2,sum,ans);
		left2-=1;
	}
	printf("%.8f\n",1.0*sum/ans);
	return 0;
}