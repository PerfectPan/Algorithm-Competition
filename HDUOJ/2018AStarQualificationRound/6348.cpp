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
const int N=1e4+10;
const int P=1000000007;
int T,n,i,cur,len,cas=1,ans[N],p[N],sum[N],dp[N][2];
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
inline int lowbit(int x){return x&(-x);}
void update(int pos,int v){
	for (;pos<=n;pos+=lowbit(pos)) up(sum[pos],v);
}
int get(int x){
	int res=0;
	for (;x>0;x-=lowbit(x)) up(res,sum[x]);
	return res;
}
int main(){
	for (read(T);T--;){
		read(n);
		for (i=1;i<=n;i++){
			read(p[i]);
			dp[i][0]=1;
			ans[i]=0;
		}
		cur=0;
		for (ans[1]=n,len=2;len<=n;len++){
			if (ans[len-1]==0) break;
			for (i=1;i<=n;i++){
				int tmp=get(p[i]-1);
				up(ans[len],tmp); 
				update(p[i],dp[i][cur]);
				dp[i][cur^1]=tmp;
			}
			cur^=1;
			for (i=1;i<=n;i++) sum[i]=0;
		} 
		printf("Case #%d: ",cas++);
		for (i=1;i<=n;i++){
			printf("%d%c",ans[i],i==n?'\n':' ');
		}
	}
	return 0;
}