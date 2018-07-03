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
int a,b,c,n;
int main(){
	read(a),read(b),read(c),read(n);
	n=n-a-b+c;
	if (a+b-c>=0&&c<=b&&c<=a&&n>=1) printf("%d\n",n);
	else puts("-1");
	return 0;
}