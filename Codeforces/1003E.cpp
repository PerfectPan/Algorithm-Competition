#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x; 
}
const int N=4e5+10;
int n,d,k,i,j,in[N];
vector<int>G[N];
void dfs(int dis,int pre){
	if (j>n||dis==0) return;
	while (j<=n&&in[pre]<k){
		G[j].push_back(pre);
		in[j]++,in[pre]++;
		j++;
		dfs(dis-1,j-1);
	}
}
int main(){
	read(n),read(d),read(k);
	if (d+1>n) return puts("NO"),0;
	for (i=1,j=d+2;i<=d;i++){
		G[i].push_back(i+1);
		in[i]++,in[i+1]++;
		if (i==1||j>n) continue;
		if (in[i]>k) return puts("NO"),0;
		int dis=min(abs(i-1),abs(d+1-i));
		int tmp=k-in[i];
		dfs(dis,i);
	}
	for (i=1;i<=n;i++){
		if (in[i]>k||in[i]==0) return puts("NO"),0;
	}
	puts("YES");
	for (i=1;i<=n;i++){
		for (j=0;j<(int)G[i].size();j++){
			printf("%d %d\n",i,G[i][j]);
		}
	}
	return 0;
}