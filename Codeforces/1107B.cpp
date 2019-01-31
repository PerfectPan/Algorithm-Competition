#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e5+10;
int n,x;
ll k;
int work(int x){
	if (x<=9) return x;
	int sum=0;
	while (x){
		sum+=x%10;
		x/=10;
	}
	return work(sum);
}
int main(){
	// for (int i=1;i<=100;++i){
		// printf("%d\n",work(i));
	// }
	for (read(n);n--;){
		read(k),read(x);
		printf("%lld\n",x+9LL*(k-1));
	}
	return 0;
}