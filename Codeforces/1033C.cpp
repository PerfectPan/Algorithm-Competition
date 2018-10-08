#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e5+10;
int n,i,j,sg[N],a[N],pos[N];
vector<int>G[N];
void dfs(int x){
	if (sg[x]!=-1) return;
	if ((int)G[x].size()==0){
		sg[x]=0;
		return;
	}
	bool flag=0;
	for (int i=0;i<(int)G[x].size();++i){
		int y=G[x][i];
		dfs(y);
		if (sg[y]==0) flag=1;
	}
	if (flag) sg[x]=1;
	else sg[x]=0;
	return;
}
int main(){
	read(n);
	for (i=1;i<=n;++i){
		sg[i]=-1;
		read(a[i]);
		pos[a[i]]=i;
	}
	/*for (i=1;i<=n;++i){
		printf("%d ",pos[i]);
	}
	puts("");*/
	for (i=1;i<=n;++i){
		for (j=pos[i]+i;j<=n;j+=i)if(a[j]>i){
			G[pos[i]].PB(j);
		}
		for (j=pos[i]-i;j>=1;j-=i)if(a[j]>i){
			G[pos[i]].PB(j);
		}
	}
	/*for (i=1;i<=n;++i){
		for (j=0;j<(int)G[i].size();++j){
			printf("%d ",G[i][j]);
		}
		puts("");
	}*/
	dfs(pos[1]);
	//puts("***");
	for (i=1;i<=n;++i){
		if (sg[i]==0) putchar('B');
		else putchar('A');
	}
	puts("");
	return 0;
}