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
const int N=2e5+10;
int n,m,i,j,sum,a,b,k[N],lst[N],num[N];
vector<int>G[N<<1];
bool check(int d){
	for (i=1;i<=n;++i) lst[i]=d+1,num[i]=k[i];
	for (i=1;i<=d;++i){
		for (j=0;j<(int)G[i].size();++j){
			lst[G[i][j]]=i;
		}
	}
	int money=0,tot=sum;
	for (i=1;i<=d;++i){
		money+=1;
		for (j=0;j<(int)G[i].size();++j){
			if (lst[G[i][j]]==i){
				int cnt=min(num[G[i][j]],money);
				money-=cnt;
				num[G[i][j]]-=cnt;
				tot-=cnt;
			}
			if (!money) break;
		}
	}
	return money-tot*2>=0;
}
int main(){
	read(n),read(m);
	for (i=1;i<=n;++i) read(k[i]),sum+=k[i];
	for (i=1;i<=m;++i){
		read(a),read(b);
		G[a].PB(b);
	} 
	int l=1,r=4e5+10,ans=-1;
	while (l<=r){
		int mid=l+((r-l)>>1);
		if (check(mid)){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}