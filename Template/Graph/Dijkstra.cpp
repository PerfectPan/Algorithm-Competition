// 图中不可出现负权路，很多问题可以先用此进行预处理。
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
        for (int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int dist){
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);
    }

    void dijkstra(int s){
        priority_queue<HeapNode>Q;
        for (int i=0;i<n;i++) d[i]=INF;
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
    }

    void GetShortestPaths(int s,int *dist,vector<int>* paths){
        dijkstra(s);
        for (int i=0;i<n;i++){
            dist[i]=d[i];
            paths[i].clear();
            int t=i;
            paths[i].push_back(t);
            while (t!=s){
                paths[i].push_back(edges[p[t]].from);
                t=edges[p[t]].from;
            }
            reverse(paths[i].begin(),paths[i].end());
        }
    }
}solver;
