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
const int N=10000+10;
int n,sum,i,a[N];
int main(){
	read(n);
	for (i=1;i<=n;i++) read(a[i]),sum+=a[i];
	if (4.5*n<=sum) puts("0");
	else{
		sort(a+1,a+1+n);
		for (i=1;i<=n;i++){
			sum-=a[i];
			sum+=5;
			if (4.5*n<=sum) return printf("%d\n",i),0;
		}
	}
	return 0;
}