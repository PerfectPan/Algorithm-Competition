#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=2000+10;
struct Node{
	int val,len;
	bool operator<(const Node&rhs)const{
		if (val==rhs.val) return len<rhs.len;
		return val<rhs.val;
	}
};
int n,m,i,j,a[N],b[N],mx[N*N];
ll x;
vector<Node>vec;
int main(){
	read(n),read(m);
	for (i=1;i<=n;++i) read(a[i]);
	for (i=1;i<=m;++i) read(b[i]);
	read(x);
	for (i=1;i<=m;++i){
		int num=0;
		for (j=i;j<=m;++j){
			num+=b[j];
			vec.PB((Node){num,j-i+1});
		}
	}
	sort(vec.begin(),vec.end());
	for (i=0;i<(int)vec.size();++i){
		if (i==0) mx[i]=vec[i].len;
		else mx[i]=max(mx[i-1],vec[i].len);
	}
	int ans=0;
	for (i=1;i<=n;++i){
		int res=0;
		for (j=i;j<=n;++j){
			res+=a[j];
			int l=0,r=(int)vec.size()-1,pos=-1;
			while (l<=r){
				int mid=l+((r-l)>>1);
				if (1LL*vec[mid].val*res<=x){
					l=mid+1;
					pos=mid;
				}
				else r=mid-1;
			}
			if (pos==-1) continue;
			ans=max(ans,(j-i+1)*mx[pos]);
		}
	}
	printf("%d\n",ans);
	return 0;
}