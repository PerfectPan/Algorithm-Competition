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
const int N=16;
int T,n,i,j,cas=1,status,a[N],p[N],pos[N];
ll dp[(1<<16)+10][16];
int main(){
	for (read(T);T--;){
		read(n);
		memset(pos,-1,sizeof(pos));
		for (i=0;i<n;++i){
			read(a[i]),read(p[i]);
			if (p[i]!=-1) pos[p[i]]=i;
		}
		int tot=1<<n;
		for(status=0;status<tot;++status)for(i=0;i<n;++i)dp[status][i]=-1e18;
		for (status=1;status<tot;++status){
			int num=__builtin_popcount(status);
			if (num==1){
				for (i=0;i<n;++i)if(status&(1<<i)){
					dp[status][i]=0;
				}
				continue;
			}
			if (pos[num-1]==-1){
				for (i=0;i<n;++i)if(status&(1<<i)){
					if (pos[num-2]==-1){
						for (j=0;j<n;++j)if((status&(1<<j))&&(i!=j)){
							dp[status][i]=max(dp[status][i],dp[status^(1<<i)][j]+1LL*a[i]*a[j]);
						}
					}
					else{
						if (i!=pos[num-2]) dp[status][i]=max(dp[status][i],dp[status^(1<<i)][pos[num-2]]+1LL*a[i]*a[pos[num-2]]);
					}
				}
			}
			else{
				if (pos[num-2]==-1){
					for (j=0;j<n;++j)if((status&(1<<j))&&(pos[num-1]!=j)){
						dp[status][pos[num-1]]=max(dp[status][pos[num-1]],dp[status^(1<<pos[num-1])][j]+1LL*a[pos[num-1]]*a[j]);
					}
				}
				else{
					dp[status][pos[num-1]]=max(dp[status][pos[num-1]],dp[status^(1<<pos[num-1])][pos[num-2]]+1LL*a[pos[num-1]]*a[pos[num-2]]);
				}
			}
		}
		ll ans=-1e18;
		for (i=0;i<n;++i)if(dp[tot-1][i]!=-1e18){
			ans=max(ans,dp[tot-1][i]);
		}
		printf("Case #%d:\n%lld\n",cas++,ans);
	}
	return 0;
}