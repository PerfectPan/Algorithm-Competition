#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=1e5+10;
int n,q,i,rt,op,u,v,x,dfs_clock,a[N],rk[N],L[N],R[N],fa[N],son[N],sz[N],dep[N],bel[N];
ll sum[N<<2],tag[N<<2];
vector<int>G[N];
void dfs(int u,int f){
	dep[u]=dep[f]+1,son[u]=-1,sz[u]=1,fa[u]=f;
	for (int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		if (v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		if (son[u]==-1 || sz[son[u]]<sz[v]) son[u]=v;
	}
}
void dfs2(int u,int f){
	bel[u]=f;
	L[u]=R[u]=++dfs_clock;
	rk[dfs_clock]=u;
	if (son[u]==-1) return;
	dfs2(son[u],f);
	for (int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		if (v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
	R[u]=dfs_clock;
}
int lca(int u,int v){
	for (;bel[u]!=bel[v];dep[bel[u]]>dep[bel[v]]?u=fa[bel[u]]:v=fa[bel[v]]);
	return dep[u]>dep[v]?v:u;
}
int LCA(int u,int v,int r){
	int z1=lca(u,r),z2=lca(v,r);
	if (z1==z2) return lca(u,v);
	return dep[z1]>dep[z2]?z1:z2;
}
int LA(int u,int deep){
	for (;dep[bel[u]]>deep;u=fa[bel[u]]);
	return rk[L[u]+deep-dep[u]];
}
bool contain(int u,int v){return L[u]<=L[v]&&R[v]<=R[u];}
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
void pushup(int root){sum[root]=sum[root<<1]+sum[root<<1|1];}
void pushdown(int root,int len){
	if (tag[root]){
		sum[root<<1]+=tag[root]*(len-(len>>1));
		sum[root<<1|1]+=tag[root]*(len>>1);
		tag[root<<1]+=tag[root];
		tag[root<<1|1]+=tag[root];
		tag[root]=0;
	}
}
void build(int root,int l,int r){
	if (l==r){
		sum[root]=a[rk[l]];
		return;
	}
	int mid=l+((r-l)>>1);
	build(lson);
	build(rson);
	pushup(root);
}
void update(int root,int l,int r,int L,int R,int val){
	if (L<=l&&r<=R){
		sum[root]+=(ll)val*(r-l+1);
		tag[root]+=val;
		return;
	}
	pushdown(root,r-l+1);
	int mid=l+((r-l)>>1);
	if (L<=mid) update(lson,L,R,val);
	if (mid<R) update(rson,L,R,val);
	pushup(root);
}
ll query(int root,int l,int r,int L,int R){
	if (L<=l&&r<=R) return sum[root];
	pushdown(root,r-l+1);
	int mid=l+((r-l)>>1);
	ll ret=0;
	if (L<=mid) ret+=query(lson,L,R);
	if (mid<R) ret+=query(rson,L,R);
	pushup(root);
	return ret; 
}
int main(){
	read(n),read(q);
	for (i=1;i<=n;i++) read(a[i]);
	for (i=1;i<n;i++){
		read(u),read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	dfs2(1,1);
	build(1,1,n);
	rt=1;
	for (;q--;){
		read(op);
		if (op==1){
			read(v);
			rt=v;
		}
		else if (op==2){
			read(u),read(v),read(x);
			int f=LCA(u,v,rt);
			if (f==rt) update(1,1,n,1,n,x);
			else{
				if (contain(f,rt)){
					int la=LA(rt,dep[f]+1);
					update(1,1,n,1,n,x);
					update(1,1,n,L[la],R[la],-x);
				}
				else{
					update(1,1,n,L[f],R[f],x);
				}
			}
		}
		else{
			read(v);
			if (v==rt) printf("%lld\n",sum[1]);
			else{
				if (contain(v,rt)){
					int la=LA(rt,dep[v]+1);
					printf("%lld\n",sum[1]-query(1,1,n,L[la],R[la]));
				}
				else{
					printf("%lld\n",query(1,1,n,L[v],R[v]));
				}
			}
		}
	}
	return 0;
}