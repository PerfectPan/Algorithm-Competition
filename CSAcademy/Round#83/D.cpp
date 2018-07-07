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
const int N=1e6+10;
vector<int>G[N],Q[N];
int n,i,j,x,y,a,res,sum[N];
inline int lowbit(int x){return x&(-x);}
inline void add(int x){for(;x<=1e6+1;x+=lowbit(x))sum[x]++;}
inline int get(int x){
	int res=0;
	for (;x;x-=lowbit(x)) res+=sum[x];
	return res;
}
void update(int x){
	int m=sqrt(x+0.5);
	for (int i=1;i<=m;i++){
		if (x%i==0){
			int a=min(i,(int)1e6+1),b=min(x/i,(int)1e6+1);
			Q[a].push_back(b);
			Q[b].push_back(a);
		}
	}
}
int main(){
	read(n),read(a);
	for (i=1;i<=n;i++){
		read(x),read(y);
		G[x].push_back(y);
	}
	for (i=a;i>=max(1,a-1000);i--) update(i);
	for (i=1;i<=1e6+1;i++){
		for (j=0;j<(int)G[i].size();j++){
			add(G[i][j]);
		}
		for (j=0;j<(int)Q[i].size();j++){
			res=max(res,get(Q[i][j]));
		}
	}
	printf("%d\n",res);
	return 0;
}