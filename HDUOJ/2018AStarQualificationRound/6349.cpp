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
const int N=100+10;
struct Edge{
	int u,v,w,tp;
	bool operator<(const Edge&rhs)const{
		return w<rhs.w;
	}
};
int T,n,m,a,b,w,i,tp,fa[N],ans[N],cas=1;
bool vis[N];
char s[2];
vector<Edge>edges;
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
void cal(int TP){
	sort(edges.begin(),edges.end());
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) fa[i]=i;
	int cnt=0,res=0;
	for (int i=0;i<(int)edges.size();i++){
		Edge& e=edges[i];
		if (TP==0&&e.tp==3) continue;
		if (TP==1&&e.tp==1) continue;
		int u=e.u,v=e.v;
		u=Find(u),v=Find(v);
		if (u^v){
			fa[u]=v;
			res+=e.w;
			cnt++;
			vis[i]=1;
		}
		if (cnt>=n-1) break;
	}
	if (cnt<n-1) return;
	if (ans[cnt]==-1) ans[cnt]=res;
	ans[cnt]=min(ans[cnt],res);
	for (int i=0;i<(int)edges.size();i++)if(!vis[i]){
		Edge& e=edges[i];
		res+=e.w;
		if (ans[++cnt]==-1) ans[cnt]=res;
		else ans[cnt]=min(ans[cnt],res);
	}
}
int main(){
	for (read(T);T--;){
		read(n),read(m);
		memset(ans,-1,sizeof(ans));
		edges.clear();
		for (i=1;i<=m;i++){
			read(a),read(b),read(w);
			scanf("%s",s);
			if (s[0]=='R') tp=1;
			else if (s[0]=='G') tp=2;
			else tp=3;
			edges.PB((Edge){a,b,w,tp});
		}
		if (m>=n-1) cal(0),cal(1);
		printf("Case #%d:\n",cas++);
		for (i=1;i<=m;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
