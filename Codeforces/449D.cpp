#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=1e6+10;
const int P=1e9+7;
int n,i,status,ans,a[N],f[(1<<20)+10];
int fexp(int a,int n){
	int res=1;
	while (n){
		if (n&1) res=1LL*res*a%P;
		a=1LL*a*a%P;
		n>>=1;
	}
	return res;
}
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int main(){
	read(n);
	for (i=1;i<=n;i++){
		read(a[i]);
		f[a[i]]++;
	}
	for (i=0;i<20;i++){
		for (status=0;status<(1<<20);status++){
			if (!(status&(1<<i))) f[status]+=f[status|(1<<i)];
		}
	}
	for (status=0;status<(1<<20);status++){
		int g=__builtin_popcount(status);
		int res=fexp(2,f[status])-1;
		if (res<0) res+=P;
		if (g&1) up(ans,P-res);
		else up(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}