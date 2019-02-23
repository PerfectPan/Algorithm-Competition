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
const int P=2520;
int T,status,i,digit[20];
ll l,r,ans,dp[20][256][2520];
ll dfs(int pos,int S,int num,bool jud){
	if (!pos){
		for (int i=0;i<8;++i)if(S&(1<<i)){
			if (num%(i+2)) return 0;
		}
		return 1;
	}
	if (!jud && ~dp[pos][S][num]) return dp[pos][S][num];
	int limit=jud?digit[pos]:9;
	ll ret=0;
	for (int i=0;i<=limit;++i){
		ret+=dfs(pos-1,i>1?S|(1<<(i-2)):S,(num*10+i)%P,jud && i==limit);
	}
	if (!jud) dp[pos][S][num]=ret;
	return ret;
}
ll cal(ll x){
	if (!x) return 1;
	int len=0;
	while (x){
		digit[++len]=x%10;
		x/=10;
	}
	return dfs(len,0,0,1);
}
int main(){
	memset(dp,-1,sizeof(dp));
	for (read(T);T--;){
		read(l),read(r);
		printf("%lld\n",cal(r)-cal(l-1));
	}
	return 0;
}