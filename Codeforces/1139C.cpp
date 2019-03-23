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
const int N=1e5+10;
const int P=1e9+7;
int n,k,i,u,v,w,cnt,ans;
bool vis[N];
vector<pair<int,int> >G[N];
int fexp(int a,int n){
	int res=1;
	while (n){
		if (n&1) res=1LL*res*a%P;
		a=1LL*a*a%P;
		n>>=1;
	}
	return res;
}
void dfs(int u){
	vis[u]=1;
	cnt+=1;
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i].first,w=G[u][i].second;
		if (vis[v] || w) continue;
		dfs(v);
	}n
}
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int main(){
	read(n),read(k);
	for (i=1;i<n;++i){
		read(u),read(v),read(w);
		G[u].PB(MP(v,w));
		G[v].PB(MP(u,w));
	}
	for (i=1;i<=n;++i)if(!vis[i]){
		cnt=0;
		dfs(i);
		up(ans,fexp(cnt,k));
	}
	ans=fexp(n,k)-ans;
	if (ans<0) ans+=P;
	printf("%d\n",ans);
	return 0;
}