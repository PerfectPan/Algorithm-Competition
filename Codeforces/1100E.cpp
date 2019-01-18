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
const int N=100000+10;
struct Edge{int u,v,c;};
int n,m,u,v,c,i,cnt,in[N],rk[N];
vector<Edge>edges;
vector<int>G[N],res;
queue<int>Q;
bool check(int limit){
	int i;
	while (!Q.empty()) Q.pop();
	for (i=1;i<=n;++i) in[i]=0,G[i].clear();
	for (i=0;i<(int)edges.size();++i){
		if (edges[i].c>limit){
			G[edges[i].u].PB(edges[i].v);
			++in[edges[i].v];
		}
	}  
	for (cnt=0,i=1;i<=n;++i){
		if (!in[i]){
			rk[i]=++cnt;
			Q.push(i);
		}
	}
	while (!Q.empty()){
		int u=Q.front();Q.pop();
		for (i=0;i<(int)G[u].size();++i){
			int v=G[u][i];
			if (--in[v]==0){
				rk[v]=++cnt;
				Q.push(v);
			}
		}
	}
	return cnt==n;
}
int main(){
	read(n),read(m);
	for (i=1;i<=m;++i){
		read(u),read(v),read(c);
		edges.PB((Edge){u,v,c});
	}
	int l=0,r=1e9,ans=-1;
	while (l<=r){
		int mid=l+((r-l)>>1);
		if (check(mid)){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	check(ans);
	for (i=0;i<m;++i){
		if (edges[i].c<=ans && rk[edges[i].u]>rk[edges[i].v]){
			res.PB(i+1);
		}
	}
	printf("%d %d\n",ans,(int)res.size());
	for (i=0;i<(int)res.size();++i){
		printf("%d%c",res[i],i==(int)res.size()-1?'\n':' ');
	}
	return 0;
}