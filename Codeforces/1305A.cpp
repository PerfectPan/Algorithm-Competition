#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=100+10;
int T,i,n,a[N],b[N];
int main(){
	for (read(T);T--;){
		read(n);
		for (i=1;i<=n;++i) read(a[i]);
		for (i=1;i<=n;++i) read(b[i]);
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for (i=1;i<=n;++i) printf("%d%c",a[i],i==n?'\n':' ');
		for (i=1;i<=n;++i) printf("%d%c",b[i],i==n?'\n':' ');
	}
    return 0;
}