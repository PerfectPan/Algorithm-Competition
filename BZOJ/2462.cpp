#include <bits/stdc++.h>
using namespace std;
const int N=1000+10;
const int M=100+10;
int m,n,a,b,i,j,q,tot,matrix[N][N],cnt[N][N],son[M*M][2],fail[M*M*2],id[M*M*2],last[M*M*2];
char s[N];
queue<int>Q;
void ins(char *s,int ID){
	int p=0;
	for (int i=0;s[i];++i){
		int idx=s[i]-'0';
		if (!son[p][idx]) son[p][idx]=++tot;
		p=son[p][idx];
	}
	id[p]=ID;
}
void getFail(){
	for (int i=0;i<2;++i){
		if (son[0][i]) Q.push(son[0][i]),last[son[0][i]]=0;
	}
	while (!Q.empty()){
		int u=Q.front();Q.pop();
		for (int i=0;i<2;++i){
			if (!son[u][i]) son[u][i]=son[fail[u]][i];
			else{
				fail[son[u][i]]=son[fail[u]][i];
				last[son[u][i]]=id[fail[son[u][i]]]?fail[son[u][i]]:last[fail[son[u][i]]];
				Q.push(son[u][i]);
			}
		}
	}
}
void add(int p,int x,int y){
	if (id[p]){
		if (x-id[p]+1>=0) cnt[x-id[p]+1][y-b+1]++;
		add(last[p],x,y);
	}
}
void solve(int* s,int pos){
	int p=0;
	for (int i=1;i<=n;++i){
		p=son[p][s[i]];
		if (id[p]) add(p,pos,i);
		else if (last[p]) add(last[p],pos,i);
	}
}
int main(){
	scanf("%d%d%d%d",&m,&n,&a,&b);
	for (i=1;i<=m;++i){
		scanf("%s",s+1);
		for (j=1;j<=n;++j) matrix[i][j]=s[j]-'0';
	}
	for (scanf("%d",&q);q--;){
		for (i=1;i<=a;++i){
			scanf("%s",s+1);
			ins(s+1,i);
		}
		getFail();
		for (i=1;i<=m;++i) solve(matrix[i],i);
		bool flag=0;
		for (i=1;i<=m;++i){
			for (j=1;j<=n;++j){
				flag|=cnt[i][j]>=a;
				cnt[i][j]=0;
			}
		}
		puts(flag?"1":"0");
		for (i=0;i<=tot;++i){
			id[i]=last[i]=fail[i]=son[i][0]=son[i][1]=0;
		}
		tot=0;
	}
	return 0;
}