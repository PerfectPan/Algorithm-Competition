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
const int N=105;
const int P=1e9+7;
int T,dp[105][10][2][2];
char s[N];
inline void add(int&a,int b){a+=b;if(a>=P)a-=P;}
int dfs(int len,int num,bool up,bool preZero,bool jud){
	if (len==-1) return 1;
	if (!jud && ~dp[len][num][up][preZero]) return dp[len][num][up][preZero];
	int limit=jud?s[len]-'0':9,ret=0;
	for (int i=0;i<=limit;++i){
		if (preZero) add(ret,dfs(len-1,i,0,preZero && i==0,jud && i==limit));
		else if(up && i>=num) add(ret,dfs(len-1,i,up,preZero && i==0,jud && i==limit));
		else if (!up) add(ret,dfs(len-1,i,i>num,preZero && i==0,jud && i==limit));
	}
	if (!jud) dp[len][num][up][preZero]=ret;
	return ret;
}
int main(){
	for (read(T);T--;){
		scanf("%s",s);
		int len=strlen(s);
		reverse(s,s+len);
		memset(dp,-1,sizeof(dp));
		int ans=dfs(len-1,0,0,1,1);
		add(ans,P-1);
		printf("%d\n",ans);
	}
	return 0;
}
