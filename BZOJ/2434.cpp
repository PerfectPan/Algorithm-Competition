#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
const int N=1e5+10;
const int SIGMA_SIZE=26;
int T,i,j,tot,dfs_clock,n,m,x,y,cnt,ans[N],sum[N],q[N],fail[N],fa[N],pos[N],L[N],R[N],son[N][SIGMA_SIZE];
char s[N];
vector<int>G[N];
vector<pair<int,int> >qu[N];
inline int lowbit(int x){return x&(-x);}
int get(int x){
	int res=0;
	for (;x>0;x-=lowbit(x)) res+=sum[x];
	return res;
}
void add(int x,int v){for(;x<=dfs_clock;x+=lowbit(x))sum[x]+=v;}
void build(char* s){
	int p=0,id=0;
	for (i=0;s[i];++i){
		if (s[i]=='P') pos[++id]=p;
		else if (s[i]=='B') p=fa[p];
		else{
			int idx=s[i]-'a';
			if (!son[p][idx]){
				son[p][idx]=++tot;
				fa[tot]=p;
			}
			p=son[p][idx];
		}
	}
}
void getfail(){
	int head=0,tail=0;
	for (i=0;i<SIGMA_SIZE;++i){
		if (son[0][i]) q[tail++]=son[0][i];
	}
	for (;head!=tail;){
		int u=q[head++];
		for (i=0;i<SIGMA_SIZE;++i){
			if (son[u][i]){
				fail[son[u][i]]=son[fail[u]][i];
				q[tail++]=son[u][i];
			}
			else son[u][i]=son[fail[u]][i];
		}
	}
}
void dfs(int u){
	L[u]=++dfs_clock;
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		dfs(v);
	}
	R[u]=dfs_clock;
}
void solve(){
	int p=0,id=0;	
	add(L[p],1);
	for (i=0;s[i];++i){
		if (s[i]=='P'){
			id++;
			for (j=0;j<(int)qu[id].size();++j){
				int u=qu[id][j].first,idx=qu[id][j].second;
				ans[idx]=get(R[pos[u]])-get(L[pos[u]]-1);
			}
		}
		else if (s[i]=='B'){
			add(L[p],-1);
			p=fa[p];
		}
		else{
			p=son[p][s[i]-'a'];
			add(L[p],1);
		}
	}
}
int main(){
	scanf("%s",s);
	build(s);
	getfail();
	for (i=1;i<=tot;++i) G[fail[i]].PB(i);
	dfs(0);
	for (scanf("%d",&m),i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		qu[y].PB(MP(x,i));
	}
	solve();
	for (i=1;i<=m;++i) printf("%d\n",ans[i]);
	return 0;
}