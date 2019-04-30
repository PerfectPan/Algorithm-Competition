#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=10000+10;
int n,m,r,s[N],b[N];
int main(){
	read(n),read(m),read(r);
	for (int i=1;i<=n;++i) read(s[i]);
	for (int i=1;i<=m;++i) read(b[i]);
	int a=*min_element(s+1,s+1+n);
	int bb=*max_element(b+1,b+1+m);
	int num=r/a;
	printf("%d\n",max(r,r-num*a+num*bb));
	return 0;
}