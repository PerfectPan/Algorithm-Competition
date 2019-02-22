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
int l,r,digit[11],dp[11][10];
int dfs(int pos,int num,bool preZero,bool jud){
	if (!pos) return 1;
	if (!jud && !preZero && ~dp[pos][num]) return dp[pos][num];
	int limit=jud?digit[pos]:9,ret=0;
	for (int i=0;i<=limit;++i){
		if (preZero) ret+=dfs(pos-1,i,preZero && i==0,jud && i==limit);
		else if(abs(i-num)>=2) ret+=dfs(pos-1,i,preZero && i==0,jud && i==limit);
	}
	if (!jud && !preZero) dp[pos][num]=ret;
	return ret;
}
int cal(int x){
	if (!x) return 1;
	int len=0;
	while (x){
		digit[++len]=x%10;
		x/=10;
	}
	return dfs(len,0,1,1);
}
int main(){
	memset(dp,-1,sizeof(dp));
	read(l),read(r);
	printf("%d\n",cal(r)-cal(l-1));
	return 0;
}