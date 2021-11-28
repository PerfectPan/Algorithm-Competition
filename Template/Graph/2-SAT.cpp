struct TwoSAT{
    int n;
    vector<int>G[maxn*2];
    bool mark[maxn*2];
    int S[maxn],c;

    void init(int n){
        this->n=n;
        for (int i=0;i<n*2;i++) G[i].clear();
        memset(mark,false,sizeof(mark));
    }

    void add_clause(int x,int y){
        G[x].push_back(y);
    }

    bool dfs(int x){
        if (mark[x^1]) return false;
        if (mark[x]) return true;
        mark[x]=true;
        S[c++]=x;
        for (int i=0;i<(int)G[x].size();i++)
            if (!dfs(G[x][i])) return false;
        return true;
    }

    bool solve(){
        for (int i=0;i<n*2;i+=2){
            if (!mark[i] && !mark[i+1]){
                c=0;
                if (!dfs(i)){
                    while (c) mark[S[--c]]=false;
                    if (!dfs(i+1)) return false;
                }
            }
        }
        return true;
    }
}

