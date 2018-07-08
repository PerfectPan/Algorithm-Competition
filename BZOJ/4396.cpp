#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=1e5+10;
int n,i,j,x,cnt,cnta,cntb,a[N/2],b[N/2];
bool vis[N];
int main(){
	read(n);
	for (i=1;i<=n;i++){
		read(x);
		vis[x]=1;
	}
	for (cnta=cntb=i=1;i<=2*n;i++){
		if (!vis[i]) a[cnta++]=i;
		else b[cntb++]=i;
	}
	for (i=1,j=1;i<=n;i++,j++){	
		while (j<=n&&a[j]<b[i]) j++;
		if (j>n) break;
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}