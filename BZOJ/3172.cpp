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
const int N=1e6+10;
const int SIGMA_SIZE=26;
char s[N];
int n,i,tot,fail[N],final[N],cnt[N],son[N][SIGMA_SIZE];
queue<int>Q;
vector<int>G[N];
void ins(char* s,int x){
	int p=0;
	for (int i=0;s[i];++i){
		int idx=s[i]-'a';
		if (!son[p][idx]) son[p][idx]=++tot;
		p=son[p][idx];
		cnt[p]++;
	}
	final[x]=p;
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
void dfs(int u){
	for (int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		dfs(v);
		cnt[u]+=cnt[v];
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
	dfs(0);
	for (i=1;i<=n;++i) printf("%d\n",cnt[final[i]]);
	return 0;
}