#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=40+10;
const int P=1e9+7;
int n,m,i,x,y,A,B,C,status,a[N],w[N],g2[N],g3[N],dp[(1<<22)+10],dp2[(1<<22)+10],dp3[(1<<22)+10];
ll g[N];
inline void up(int &a,int b){a+=b;if(a>=P)a-=P;}
int fexp(int a,int n){
	int res=1;
	while (n){
		if (n&1) res=1LL*res*a%P;
		a=1LL*a*a%P;
		n>>=1;
	}
	return res;
}
void dfs(int x,int tot,int val,int val2,int SS,int S){
	if (x==tot+1){
		up(dp[SS],val);
		up(dp2[SS],1);
		up(dp3[SS],val2);
		return;
	}
	dfs(x+1,tot,val,val2,SS,S);
	if (!(S>>x&1)) dfs(x+1,tot,1LL*val*w[x]%P,1LL*val2*a[x]%P,SS|(1<<x),(S|g2[x])|(1<<x));
}
void dfs2(int x,int tot,int val,int val2,int SS,int S){
	if (x==tot+1){
		int S2=0;
		for (int i=1;i<=n-n/2;++i)if(SS>>i&1){
			for (int j=1;j<=n/2;++j)if(g[i+n/2]>>j&1){
				S2|=1<<j;
			}
		}
		for (int j=1;j<=n/2;++j){
			S2^=1<<j;
		}
		up(A,1LL*val*dp[S2]%P);
		up(B,dp2[S2]);
		up(C,1LL*val2*dp3[S2]%P);
		return;
	}
	dfs2(x+1,tot,val,val2,SS,S);
	if (!(S>>x&1)) dfs2(x+1,tot,1LL*val*w[x+n/2]%P,1LL*val2*a[x+n/2]%P,SS|(1<<x),(S|g3[x])|(1<<x));
}
int main(){
	read(n),read(m);
	for (i=1;i<=n;++i) read(w[i]),a[i]=1LL*w[i]*w[i]%P;
	for (i=1;i<=m;++i){
		read(x),read(y);
		if (x<=n/2 && y<=n/2) g2[x]|=1<<y,g2[y]|=1<<x;
		else if (x>n/2 && y>n/2) g3[x-n/2]|=1<<(y-n/2),g3[y-n/2]|=1<<(x-n/2);
		g[x]|=1LL<<y,g[y]|=1LL<<x;
	}
	dfs(1,n/2,1,1,0,0);
	for (i=0;i<=n/2;++i){
        for (status=0;status<(1<<(n/2+1));++status){
            if (status&(1<<i)){
            	up(dp[status],dp[status^(1<<i)]);
        		up(dp2[status],dp2[status^(1<<i)]);
        		up(dp3[status],dp3[status^(1<<i)]);
        	}
        }
    }
	dfs2(1,n-n/2,1,1,0,0);

	int ans=1LL*C*fexp(B,P-2)%P;
	A=1LL*A*fexp(B,P-2)%P;
	A=1LL*A*A%P;
	ans=(ans-A)%P;
	if (ans<0) ans+=P;
	printf("%d\n",ans);
	return 0;
}