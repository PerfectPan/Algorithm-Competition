#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x; 
}
const int N=5000+10;
int n,k,i,len,a[N],sum[N];
double ans;
int main(){
	read(n),read(k);
	for (i=1;i<=n;i++) read(a[i]),sum[i]=sum[i-1]+a[i];
	for (len=k;len<=n;len++){
		for (i=1;i+len-1<=n;i++){
			int tot=sum[i+len-1]-sum[i-1];
			ans=max(ans,1.0*tot/len);
		}
	}
	printf("%.7lf\n",ans);
	return 0;
}