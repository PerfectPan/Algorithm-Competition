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
const int N=1e6+10;
int n,m,p,i,j,k,a[N],b[N];
int main(){
	read(n),read(m),read(p);
	for (i=0;i<n;++i) read(a[i]);
	for (i=0;i<m;++i) read(b[i]);
	for (i=0;i<n;++i){
		if (a[i]%p!=0) break;
	}
	for (j=0;j<m;++j){
		if (b[j]%p!=0) break;
	}
	printf("%d\n",i+j);
    return 0;
}