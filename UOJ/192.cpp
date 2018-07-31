#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef unsigned long long ull;
const int N=1e4+10;
int n,i,j,p,u,v,w,primes[N];
ull val[N],sum[N*10]; 
map<int,ull>mp;
vector<pair<int,int> >G[N*10];
ull get(){return (ull)rand()*rand();}
ull getSingleHash(int x){
	if (mp.find(x)!=mp.end()) return mp[x];
	return mp[x]=get();
}
ull getHash(int x){
	ull ret=0;
	for (int i=1;i<=primes[0];i++){
		if (x<primes[i]) break;
		if (x%primes[i]==0){
			while (x%primes[i]==0){
				x/=primes[i];
				ret^=val[i];
			}
		}
	}
	if (x>1) ret^=getSingleHash(x);
	return ret;
}
void init(){
	srand((unsigned long long)new char);
	for (int i=2;i<=10000;i++){
		if (!primes[i]) primes[++primes[0]]=i;
		for (int j=1;j<=primes[j]&&i*primes[j]<=10000;j++){
			primes[i*primes[j]]=1;
			if (i%primes[j]==0) break;
		}
	}
	for (int i=1;i<=primes[0];i++) val[i]=get();
}
void dfs(int u,int f){
	for (int i=0;i<(int)G[u].size();i++){
		int v=G[u][i].first;
		if (v==f) continue;
		sum[v]=sum[u]^getHash(G[u][i].second);
		dfs(v,u);
	}
}
int main(){
	init();
	scanf("%d",&n);
	for (i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		G[u].PB(MP(v,w));
		G[v].PB(MP(u,w));
	}
	dfs(1,0);
	sort(sum+1,sum+1+n);
	long long ans=0;
	for (i=1,p;i<=n;i=p){
		p=n+1;
		for (j=i+1;j<=n;j++){
			if (sum[j]!=sum[i]){
				p=j;
				break;
			}
		}
		ans+=1LL*(p-i)*(p-i-1);
	}
	printf("%lld\n",ans);
	return 0;
}