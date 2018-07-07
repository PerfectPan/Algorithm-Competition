#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=3e5+10;
struct Edge{
	int u,v,w,offset;
	vector<int> specialPoints;

	int getSpecialPointIndex(int u,int v,int l){
		if (u>v) l=w-l;
		return offset+lower_bound(specialPoints.begin(),specialPoints.end(),l)-specialPoints.begin();
	}
};
struct Firestarter{int t,a,b,l;};
vector<Firestarter>updates;
map<pair<int,int>,Edge>mp;
vector<pair<int,int> >G[N];
int n,m,q,t,u,v,w,i,numGoodNode;
ll dis[N];
void createSpecialPoints(){
	for (int i=0;i<(int)updates.size();i++){
		Firestarter& e=updates[i];
		int a=e.a,b=e.b,l=e.l;
		bool swapped=0;
		if (a>b){
			swap(a,b);
			swapped=1;
		}
		Edge& edge=mp[MP(a,b)];
		if (swapped) l=edge.w-l;
		edge.specialPoints.PB(l);
	}
	for (auto& e:mp){
		Edge& rhs=e.second;
		sort(rhs.specialPoints.begin(),rhs.specialPoints.end());
		rhs.specialPoints.erase(unique(rhs.specialPoints.begin(),rhs.specialPoints.end()),rhs.specialPoints.end());
		rhs.offset=n+1;
		n+=rhs.specialPoints.size();
	}
}
void createGraph(){
	for (auto& itr:mp){
		Edge& rhs=itr.second;
		int lastNode=rhs.u,lastPos=0;
		for (int i=0;i<(int)rhs.specialPoints.size();i++){
			int curNode=rhs.offset+i,curPos=rhs.specialPoints[i];
			
			int pos=curPos-lastPos;
			G[lastNode].PB(MP(curNode,pos));
			G[curNode].PB(MP(lastNode,pos));
			lastNode=curNode;
			lastPos=curPos;
		}
		int curNode=rhs.v,curPos=rhs.w;
		int pos=curPos-lastPos;
		G[curNode].PB(MP(lastNode,pos));
		G[lastNode].PB(MP(curNode,pos));
	}
}
void createVirtualNode(){
	for (auto& itr:updates){
		int u=itr.a;
		int v=itr.b;
		if (u>v) swap(u,v);
		int specialPoints=mp[MP(u,v)].getSpecialPointIndex(itr.a,itr.b,itr.l);
		int myNode=++n;
		G[specialPoints].PB(MP(myNode,itr.t));
		G[myNode].PB(MP(specialPoints,itr.t));
	}
}
void dijkstra(){
	priority_queue<pair<ll,int> >Q;
	for (int i=1;i<=n;i++) dis[i]=1000000000000000000LL;
	for (int i=numGoodNode+1;i<=n;i++){
		dis[i]=0;
		Q.push(MP(0,i));
	}
	while (!Q.empty()){
		pair<ll,int> cur=Q.top();Q.pop();

		int u=cur.second;
		ll cost=-cur.first;
		if (dis[u]!=cost) continue;
		for (auto& itr:G[u]){
			int v=itr.first;
			ll w=itr.second;
			if (dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				Q.push(MP(-dis[v],v));
			}
		}
	}
}
bool isVirtual(int node){return node>numGoodNode;}
int main(){
	read(n),read(m),read(q);
	for (i=1;i<=m;i++){
		read(u),read(v),read(w);
		if (u>v) swap(u,v);
		mp[MP(u,v)]=(Edge){u,v,w,0};
	}
	for (i=1;i<=q;i++){
		read(t),read(u),read(v),read(w);
		updates.PB((Firestarter){t,u,v,w});
	}
	createSpecialPoints();
	createGraph();
	numGoodNode=n;
	createVirtualNode();
	dijkstra();

	double res=0;
	for (u=1;u<=numGoodNode;u++){
		for (auto& e:G[u]){
			int v=e.first;
			int w=e.second;
			ll a=dis[u];
			ll b=dis[v];

			if (isVirtual(u)||isVirtual(v)) continue;

			ll diff=a-b;
			diff=abs(diff);
			res=max(res,max(a,b)+(w-diff)/2.0);
		}
	}
	printf("%.1lf\n",res);
	return 0;
}