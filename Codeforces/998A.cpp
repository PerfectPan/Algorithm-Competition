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
int n,i,sum,a[15];
int main(){
	read(n);
	for (i=1;i<=n;i++) read(a[i]),sum+=a[i];
	if (n==1) puts("-1");
	else if (n==2){
		if (a[1]==a[2]) puts("-1");
		else{
			puts("1\n1");
		}
	}
	else{
		bool flag=1;
		for (i=1;i<=n;i++){
			if (sum-a[i]!=a[i]){
				puts("1");
				printf("%d\n",i);
				flag=0;
				break;
			}
		}
		if (flag) puts("-1");
	}
	return 0;
}