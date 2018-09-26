#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
int n,x,i;
int main(){
	read(n);
	for (i=1;i<=n;i++){
		read(x);
		if (x==1) return puts("HARD"),0;
	}
	puts("EASY");
	return 0;
}