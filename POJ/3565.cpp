#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=100+10;
int n,i,j,k,a[N],b[N],c[N],d[N],match[N],ans[N],va[N],vb[N];
double delta,la[N],lb[N],w[N][N];
bool dfs(int x){
	va[x]=1;
	for(int y=1;y<=n;y++)if(!vb[y]){
		if(fabs(la[x]+lb[y]-w[x][y])<1e-10){
			vb[y]=1;
			if(!match[y]||dfs(match[y])){
				match[y]=x; 
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	read(n);
	for (i=1;i<=n;i++) read(a[i]),read(b[i]);
	for (i=1;i<=n;i++) read(c[i]),read(d[i]);
	for (i=1;i<=n;i++) la[i]=-1e12;
	for (i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			w[i][j]=-sqrt(1.0*(a[i]-c[j])*(a[i]-c[j])+1.0*(b[i]-d[j])*(b[i]-d[j]));
			la[i]=max(la[i],w[i][j]);
		}
	}
	for (i=1;i<=n;i++){
		for (;;){
			memset(va,0,sizeof(va));
			memset(vb,0,sizeof(vb));
			delta=1e12;
			if (dfs(i)) break;
			for (j=1;j<=n;j++)if(va[j]){
				for (k=1;k<=n;k++)if(!vb[k]){
					delta=min(delta,la[j]+lb[k]-w[j][k]);
				}
			}
			for (j=1;j<=n;j++){
				if (va[j]) la[j]-=delta;
				if (vb[j]) lb[j]+=delta;
			}
		}
	}
	for (i=1;i<=n;i++) ans[match[i]]=i;
	for (i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}