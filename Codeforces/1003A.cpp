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
int n,i,a[N],cnt[105];
int main(){
	read(n);
	int mx=0;
	for (i=1;i<=n;i++) read(a[i]),cnt[a[i]]++,mx=max(mx,cnt[a[i]]);
	cout<<mx<<endl;
	return 0;
}