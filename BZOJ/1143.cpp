#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=100;
int res,n,m,u,v,i,j,k,match[N];
bool vis[N][N],vis2[N];
bool dfs(int x){
	for (int i=1;i<=n;i++){
		if (vis[x][i]&&!vis2[i]){
			vis2[i]=1;
			if (!match[i]||dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	read(n),read(m);
	for (i=1;i<=m;i++){
		read(u),read(v);
		vis[u][v]=1;
	}
	for (i=1;i<=n;i++) vis[i][i]=1;
	for (k=1;k<=n;k++){
		for (i=1;i<=n;i++){
			for (j=1;j<=n;j++){
				vis[i][j]|=vis[i][k]&&vis[k][j];
			}
		}
	}
	for (i=1;i<=n;i++) vis[i][i]=0;
	res=n;
	for (i=1;i<=n;i++){
		memset(vis2,0,sizeof(vis2));
		res-=dfs(i);
	}
	printf("%d\n",res);
	return 0;
}
