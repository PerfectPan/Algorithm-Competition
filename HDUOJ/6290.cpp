#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=100000+10;
struct Node{int v,a,b;};
int T,n,m,i,j,u,v,a,b;
bool vis[N];
ll dis[N];
vector<Node>G[N];
void dijkstra(){
	priority_queue<pair<ll,int> >Q;
	Q.push(MP(-1LL,1));
	memset(vis,0,sizeof(vis));
	dis[1]=1LL;
	for (int i=2;i<=n;i++) dis[i]=2000000000000000000LL;
	while (!Q.empty()){
		pair<ll,int> cur=Q.top();Q.pop();
		int u=cur.second;
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=0;i<(int)G[u].size();i++){
			int v=G[u][i].v;
			if ((1.0*(dis[u]+G[u][i].a))/dis[u]>=(1LL<<G[u][i].b)&&dis[u]+G[u][i].a<dis[v]){
				dis[v]=dis[u]+G[u][i].a;
				Q.push(MP(-dis[v],v));
			}
		}
	}
	if (dis[n]==2000000000000000000LL) puts("-1");
	else{
		for (int i=1;;i++){
			if ((1LL<<i)>dis[n]){
				printf("%d\n",i-1);
				break;
			}
		}
	}
}
int main(){
	for (read(T);T--;){
		read(n),read(m);
		for (i=1;i<=n;i++) G[i].clear();
		for (i=1;i<=m;i++){
			read(u),read(v),read(a),read(b);
			G[u].PB((Node){v,a,b});
		}
		dijkstra();
	}
	return 0;
}