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
const int maxn=5000+10;
const int INF=2e9;
struct Edge{
    int from,to,dist;
};
struct HeapNode{
    int d,u;
    bool operator <(const HeapNode& rhs)const{
        return d>rhs.d;
    }
};
struct Dijkstra{
    int n,m;
    vector<Edge>edges;
    vector<int>G[maxn];
    bool done[maxn];
    int d[maxn];
    int p[maxn];

    void init(int n){
        this->n=n;
        for (int i=0;i<=n;i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int dist){
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);
    }

    void dijkstra(int s){
        priority_queue<HeapNode>Q;
        for (int i=0;i<=n;i++) d[i]=INF;
        d[s]=0;
        memset(done,false,sizeof(done));
        Q.push((HeapNode){0,s});
        while (!Q.empty()){
            HeapNode x=Q.top();Q.pop();
            int u=x.u;
            if (done[u]) continue;
            done[u]=true;
            for (int i=0;i<(int)G[u].size();i++){
                Edge &e=edges[G[u][i]];
                if (d[e.to]>d[u]+e.dist){
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
        printf("%d\n",d[n]);
    }
}solver;
int n,m,k,i,j,u,v,w;
int main(){
	read(n),read(m),read(k);
	solver.init(n*(k+1)+1);
	for (i=1;i<=m;++i){
		read(u),read(v),read(w);
		solver.AddEdge(u+n*k,v+n*k,w);
		solver.AddEdge(v+n*k,u+n*k,w);
		for (j=0;j<k;++j){
			solver.AddEdge(u+n*j,v+n*(j+1),w/2);
			solver.AddEdge(v+n*j,u+n*(j+1),w/2);
			solver.AddEdge(u+n*j,v+n*j,w);
			solver.AddEdge(v+n*j,u+n*j,w);
		}
	}
	for (i=0;i<=k;++i) solver.AddEdge(n+n*i,n*(k+1)+1,0);
	solver.dijkstra(1);
	return 0;
}