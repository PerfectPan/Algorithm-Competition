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
const int N=100+10;
int n,b,i,a[N];
bool ok(int x){
	vector<int>vec;
	int c=0;
	for (i=1;i<n;i++){
		if (a[i]%2==0) c++;
		else c--;
		if (c==0) vec.push_back(abs(a[i]-a[i+1]));
	}
	if ((int)vec.size()<x) return 0;
	sort(vec.begin(),vec.end());
	int res=0;
	for (int i=0;i<(int)vec.size();i++){
		res+=vec[i];
		if (i+1==x) break;
	}
	return res<=b;
}
int main(){
	read(n),read(b);
	for (i=1;i<=n;i++) read(a[i]);
	int l=1,r=n,ans=0;
	while (l<=r){
		int mid=l+((r-l)>>1);
		if (ok(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}