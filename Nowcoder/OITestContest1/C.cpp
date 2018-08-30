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
const int N=1e5+10;
int n,q,i,p,a[N];
ll k,sum;
int main(){
	read(n),read(q);
	for (i=1;i<=n;i++) read(a[i]),sum+=a[i];
	for (;q--;){
		read(k);
		if (sum%k!=0) puts("No");
		else{
			ll cur=0,cnt=0;
			for (i=1;i<=n;i++){
				cur+=a[i];
				if (cur==sum/k) cur=0,cnt++;
			}
			puts(cur==0&&cnt==k?"Yes":"No");
		}
	}
	return 0;
}