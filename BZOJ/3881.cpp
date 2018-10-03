#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=2e6+10;
const int SIGMA_SIZE=26;
int n,i,tot,q,op,dfs_clock,x,sum[N],fail[N],in[N],out[N],bel[N],sz[N],son2[N],fa[N],dep[N],pos[N],son[N][SIGMA_SIZE];
char s[N];
queue<int>Q;
vector<int>G[N];
void ins(char *s,int id){
	int p=0;
	for (int i=0;s[i];++i){
		int idx=s[i]-'a';
		if (!son[p][idx]) son[p][idx]=++tot;
		p=son[p][idx];
	}
	pos[id]=p;
}
void getFail(){
	for (i=0;i<SIGMA_SIZE;++i){
		if (son[0][i]) Q.push(son[0][i]);
	}
	while (!Q.empty()){
		int u=Q.front();Q.pop();
		for (i=0;i<SIGMA_SIZE;++i){
			if (!son[u][i]) son[u][i]=son[fail[u]][i];
			else{
				fail[son[u][i]]=son[fail[u]][i];
				Q.push(son[u][i]);
			}
		}
	}
}
void dfs(int u,int f){
	dep[u]=dep[f]+1,son2[u]=-1,sz[u]=0,fa[u]=f;
	in[u]=++dfs_clock;
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		dfs(v,u);
		sz[u]+=sz[v];
		if (son2[u]==-1 || sz[v]>sz[son2[u]]) son2[u]=v;
 	}
 	out[u]=dfs_clock;
}
void dfs2(int u,int f){
	bel[u]=f;
	if (son2[u]==-1) return;
	dfs2(son2[u],f);
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		if (v==son2[u]) continue;
		dfs2(v,v);
	}
}
int lca(int u,int v){
	for (;bel[u]!=bel[v];dep[bel[u]]>dep[bel[v]]?u=fa[bel[u]]:v=fa[bel[v]]);
	return dep[u]>dep[v]?v:u;
}
inline int lowbit(int x){return x&(-x);}
int get(int x){
	int res=0;
	for (;x>0;x-=lowbit(x)) res+=sum[x];
	return res;
}
void add(int x,int val){for(;x<=dfs_clock;x+=lowbit(x))sum[x]+=val;}
inline bool cmp(const int&a,const int&b){
	return in[a]<in[b];
}
void solve(char *s){
	static int vec[N];
	int p=0,top=0;
	for (int i=0;s[i];++i){
		int idx=s[i]-'a';
		vec[top++]=p=son[p][idx];
	}
	sort(vec,vec+top,cmp);
	add(in[vec[0]],1);
	for (int i=1;i<top;++i){
		add(in[vec[i]],1);
		add(in[lca(vec[i],vec[i-1])],-1);
	}
}
int main(){
	read(n);
	for (i=1;i<=n;++i){
		scanf("%s",s);
		ins(s,i);
	}
	getFail();
	for (i=1;i<=tot;++i) G[fail[i]].PB(i);
	dfs(0,0),dfs2(0,0);
	for (read(q);q--;){
		read(op);
		if (op==1){
			scanf("%s",s);
			solve(s);
		}
		else{
			read(x);
			printf("%d\n",get(out[pos[x]])-get(in[pos[x]]-1));
		}
	}
	return 0;
}
