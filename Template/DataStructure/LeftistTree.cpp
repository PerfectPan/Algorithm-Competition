// d[0]要初始化为-1
int fa[maxn],l[maxn],r[maxn],d[maxn],v[maxn];
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
int Merge(int x,int y){
    if (!x) return y;
    if (!y) return x;
    if (v[x]<v[y]) swap(x,y);//大根堆还是小根堆看题目要求来修改
    r[x]=Merge(r[x],y);
    fa[r[x]]=x;
    if (d[r[x]]>d[l[x]]) swap(l[x],r[x]);
    d[x]=d[r[x]]+1;
    return x;
}
int pop(int x){
    int L=l[x],R=r[x];
    fa[L]=L,fa[R]=R;
    l[x]=r[x]=d[x]=0;
    return Merge(L,R);
}
