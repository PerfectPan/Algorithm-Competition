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
const int N=500000+10;
int n,q,i,c,u,v,dfs_clock,dep[N],sz[N],fa[N],son[N],L[N],R[N],bel[N];
vector<int>G[N];
#define IT set<Node>::iterator
struct Node{
	int l,r;
	mutable int v;
	Node(int L,int R=-1,int V=0):l(L),r(R),v(V){}
	bool operator<(const Node&rhs)const{
		return l<rhs.l;
	}
};
set<Node>S;
IT split(int pos){
	IT it=S.lower_bound(Node(pos));
	if (it!=S.end() && it->l==pos) return it;
	--it;
	int l=it->l,r=it->r,v=it->v;
	S.erase(it);
	S.insert(Node(l,pos-1,v));
	return S.insert(Node(pos,r,v)).first;
}
void assign(int l,int r,int val){
	IT itr=split(r+1),itl=split(l);
	S.erase(itl,itr);
	S.insert(Node(l,r,val));
}
int query(int x){return split(x)->v;}
void dfs(int u,int f){
	sz[u]=1,son[u]=-1,fa[u]=f,dep[u]=dep[f]+1;
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		if (v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		if (son[u]==-1 || sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int f){
	bel[u]=f;L[u]=R[u]=++dfs_clock;
	if (son[u]==-1) return;
	dfs2(son[u],f);
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		if (v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
	R[u]=dfs_clock;
}
void modify(int u,int v){
	while (bel[u]!=bel[v]){
		if (dep[bel[u]]<dep[bel[v]]) swap(u,v);
		assign(L[bel[u]],L[u],0);
		u=fa[bel[u]];
	}
	if (L[u]>L[v]) swap(u,v);
	assign(L[u],L[v],0);
}
int main(){
	read(n);
	for (i=1;i<n;++i){
		read(u),read(v);
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1,0),dfs2(1,1);
	S.insert(Node(1,n,0));
	for (read(q);q--;){
		read(c),read(v);
		if (c==1) assign(L[v],R[v],1);
		else if (c==2) modify(1,v);
		else printf("%d\n",query(L[v]));
	}
	return 0;
}