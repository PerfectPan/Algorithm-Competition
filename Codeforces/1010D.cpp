#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=1e6+10;
vector<int>G[N];
int n,i,u,v,cnt,rk[N],val[N];
char s[N][5];
char res[N];
void dfs(int u,int f){
	for (int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		if (v==f) continue;
		dfs(v,u);
	}
	if (s[u][0]=='A'){
		val[u]=val[G[u][0]]&&val[G[u][1]];
	}
	else if (s[u][0]=='X'){
		val[u]=val[G[u][0]]^val[G[u][1]];
	}
	else if (s[u][0]=='O'){
		val[u]=val[G[u][0]]||val[G[u][1]];
	}
	else if (s[u][0]=='N'){
		val[u]=val[G[u][0]]^1;
	}
}
void dfs(int u,int f,bool flag){
	if (s[u][0]=='I'){
		if (!flag){
			if (res[rk[u]]=='1') res[rk[u]]='0';
			else res[rk[u]]='1';
		}
		return;
	}
	if (s[u][0]=='A'){
		if (val[u]==1){
			dfs(G[u][0],u,flag);
			dfs(G[u][1],u,flag);
		}
		else{
			if (val[G[u][0]]==0&&val[G[u][1]]==0){
				dfs(G[u][0],u,1);
				dfs(G[u][1],u,1);
			}
			else{
				if (val[G[u][0]]==0) dfs(G[u][0],u,flag);
				else dfs(G[u][0],u,1);
				if (val[G[u][1]]==0) dfs(G[u][1],u,flag);
				else dfs(G[u][1],u,1); 
			}
		}
	}
	if (s[u][0]=='N') dfs(G[u][0],u,flag);
	if (s[u][0]=='O'){
		if (val[u]==0){
			dfs(G[u][0],u,flag);
			dfs(G[u][1],u,flag);
		}
		else{
			if (val[G[u][0]]==1&&val[G[u][1]]==1){
				dfs(G[u][0],u,1);
				dfs(G[u][1],u,1);
			}
			else{
				if (val[G[u][0]]==1) dfs(G[u][0],u,flag);
				else dfs(G[u][0],u,1);
				if (val[G[u][1]]==1) dfs(G[u][1],u,flag);
				else dfs(G[u][1],u,1); 
			}
		}
	}
	if (s[u][0]=='X'){
		dfs(G[u][0],u,flag);
		dfs(G[u][1],u,flag);
	}
}
int main(){
	read(n);
	for (i=1;i<=n;i++){
		scanf("%s",s[i]);
		if (s[i][0]=='A'||s[i][0]=='X'||s[i][0]=='O'){
			read(u),read(v);
			G[i].PB(u),G[i].PB(v);
		}
		else if (s[i][0]=='N'){
			read(u);
			G[i].PB(u);
		}
		else{
			read(u);
			val[i]=u;
			rk[i]=++cnt;
		}
	}
	dfs(1,0);
	for (i=1;i<=cnt;i++) res[i]='0'+val[1];
	dfs(1,0,0);
	puts(res+1);
	return 0;
}