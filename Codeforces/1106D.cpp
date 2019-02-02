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
int n,m,i,u,v;
bool vis[N];
set<int>G[N];
priority_queue<int,vector<int>,greater<int> >Q;
void bfs(){
	Q.push(1);
	while (!Q.empty()){
		int x=Q.top();Q.pop();
		if (vis[x]) continue;
		printf("%d ",x),vis[x]=1;
		for (auto v:G[x]){
			Q.push(v);
		}
	}
}
int main(){
	read(n),read(m);
	for (i=1;i<=m;++i){
		read(u),read(v);
		G[u].insert(v);
		G[v].insert(u);
	}
	bfs();puts("");
	return 0;
}