#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=(1<<18)+10;
int n,i,j,status,a[N];
pair<int,int> f[N];
inline void up(pair<int,int> &a,pair<int,int> b){
	if (b.second>=a.first){
		a=b;
	}
	else if (b.first>=a.first){
		a.second=a.first;
		a.first=b.first;
	}
	else if (b.first<a.first && b.first>=a.second){
		a.second=b.first;
	}
}
int main(){
	read(n);
	for (i=0;i<(1<<n);++i){
		read(a[i]);
		f[i].first=a[i];
	}
	for (i=0;i<n;++i){
		for (status=0;status<(1<<n);++status){
			if (status&(1<<i)) up(f[status],f[status^(1<<i)]);
		}
	}
	int res=0;
	for (i=1;i<(1<<n);++i){
		res=max(res,f[i].first+f[i].second);
		printf("%d\n",res);
	}
	return 0;
}