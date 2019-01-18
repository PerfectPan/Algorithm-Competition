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
const int N=100+10;
int n,k,i,ans,a[N],vis[N];
int work(int b){
	int aa=0,bb=0;
	for (int i=1;i<=n;++i) vis[i]=0;
	for (int i=b;i<=n;i+=k) vis[i]=1;
	for (int i=b-k;i>=1;i-=k) vis[i]=1;
	for (int i=1;i<=n;++i) if (!vis[i]){
		if (a[i]==1) aa++;
		else bb++;
	}
	return abs(aa-bb);
}
int main(){
	read(n),read(k);
	for (i=1;i<=n;++i) read(a[i]);
	for (i=1;i<=n;++i){
		ans=max(ans,work(i));
	}
	printf("%d\n",ans);
	return 0; 
}