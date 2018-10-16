#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=2e5+10;
struct Edge{
	int u,v,w;
	bool operator<(const Edge&rhs)const{
		return w<rhs.w;
	}
};
int n,m,u,v,w,x,k,q,ans,tot,i,j,cnt,dfs_clock,rk[N],val[N],L[N],R[N],fa[N],h[N],root[N],sum[N*20],ls[N*20],rs[N*20],parent[N][18];
vector<Edge>edge;
vector<int>G[N],vec;
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
void dfs(int u){
	if (u<=n) L[u]=R[u]=++dfs_clock,rk[dfs_clock]=u;
	else L[u]=300000,R[u]=0;
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		parent[v][0]=u;
		dfs(v);
		L[u]=min(L[u],L[v]);
		R[u]=max(R[u],R[v]);
	}
}
void compress(){
	sort(vec.begin(),vec.end());
	for (i=1;i<=n;++i){
		int pos=lower_bound(vec.begin(),vec.end(),h[i])-vec.begin();
		h[i]=pos+1;
	}
}
void ins(int&y,int x,int l,int r,int val){
	sum[y=++cnt]=sum[x]+1;
	ls[y]=ls[x],rs[y]=rs[x];
	if (l==r) return;
	int mid=l+((r-l)>>1);
	if (val<=mid) ins(ls[y],ls[x],l,mid,val);
	else ins(rs[y],rs[x],mid+1,r,val);
}
int query(int x,int y,int l,int r,int k){
	if (l==r) return vec[l-1];
	int mid=l+((r-l)>>1);
	if (sum[ls[y]]-sum[ls[x]]>=k) return query(ls[x],ls[y],l,mid,k);
	else return query(rs[x],rs[y],mid+1,r,k-(sum[ls[y]]-sum[ls[x]]));
}
void preprocess(){
	for (j=1;j<18;++j){
		for (i=1;i<=tot && i+(1<<j)<=tot;++i)if(parent[i][j-1]){
			parent[i][j]=parent[parent[i][j-1]][j-1];
		}
	}
}
int main(){
	read(n),read(m),read(q);
	for (i=1;i<=n;++i){
		read(h[i]);
		fa[i]=i;
		vec.PB(h[i]);
	}
	compress();
	for (i=1;i<=m;++i){
		read(u),read(v),read(w);
		edge.PB((Edge){u,v,w});
	}
	sort(edge.begin(),edge.end());
	for (tot=n,i=0;i<(int)edge.size();++i){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int fu=Find(u),fv=Find(v);
		if (fu^fv){
			fa[fu]=fa[fv]=++tot;
			fa[tot]=tot;
			val[tot]=w;
			G[tot].PB(fu),G[tot].PB(fv);
		}
	}
	dfs(tot);
	preprocess();
	for (i=1;i<=n;++i) ins(root[i],root[i-1],1,(int)vec.size(),h[rk[i]]);
	for (;q--;){
		read(v),read(x),read(k);
		v^=ans,x^=ans,k^=ans;
		for (i=17;i>=0;--i){
			if (parent[v][i] && val[parent[v][i]]<=x) v=parent[v][i];
		}
		int l=L[v],r=R[v];
		if (sum[root[r]]-sum[root[l-1]]<k) puts("-1"),ans=0;
		else printf("%d\n",ans=query(root[l-1],root[r],1,(int)vec.size(),r-l+1-k+1));
	}
	return 0;
}