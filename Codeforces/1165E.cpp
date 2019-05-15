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
const int N=2e5+10;
const int P=998244353;
int n,i,j,k,ans,b[N],c[N];
ll a[N];
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int main(){
	read(n);
	for (i=1;i<=n;++i) read(a[i]);
	for (i=1;i<=n;++i) read(b[i]);
	sort(b+1,b+1+n);
	for (i=1;i<=n;++i){
		a[i]=a[i]*i*(n-i+1);
	}
	sort(a+1,a+1+n);
	reverse(b+1,b+1+n);
	for (i=1;i<=n;++i) up(ans,1LL*a[i]%P*b[i]%P);
	printf("%d\n",ans);
	return 0;
}