#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100000+10;
const int M=1<<20;
int T,n,i,status,a[N];
ll mx;
pair<int,int> f[M];
void up(pair<int,int> &a,pair<int,int> b){
	if (b.second>=a.first){
		a.first=b.first;
		a.second=b.second;
	}
	else if (b.first>=a.first){
		a.second=a.first;
		a.first=b.first;
	}
	else if (b.first<a.first && b.first>=a.second){
		a.second=b.first;
	}
}
int main(){
	for (scanf("%d",&T);T--;){
		scanf("%d",&n);
		for (i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if (f[a[i]].first) f[a[i]].second=a[i];
			else f[a[i]].first=a[i];
		}
		for (i=0;i<20;i++){
			for (status=0;status<(1<<20);status++){
				if (!(status&(1<<i))) up(f[status],f[status|(1<<i)]);
			}
		}	
		for (mx=0,status=0;status<(1<<20);status++){
			mx=max(mx,1LL*status*f[status].first*f[status].second);
			f[status].first=f[status].second=0;
		}
		printf("%lld\n",mx);
	}
	return 0;
}