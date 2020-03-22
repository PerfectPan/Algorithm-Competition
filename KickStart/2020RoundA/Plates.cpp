#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=50+10;
int T,n,k,p,i,j,l,cas=1,a[N][N],dp[N][N*N];
int main(){
    for (read(T);T--;){
        read(n),read(k),read(p);
        for (i=1;i<=n;++i) for (j=1;j<=k;++j) read(a[i][j]);
        memset(dp,0,sizeof(dp));
        for (i=1;i<=k;++i) dp[1][i]=dp[1][i-1]+a[1][i];
        for (j=0;j<=k;++j) printf("dp[1][%d]=%d\n",j,dp[1][j]);
        for (i=2;i<=n;++i){
            for (l=0;l<=(i-1)*k;++l){
                int sum=0;
                for (j=0;j<=k;++j){
                    sum+=a[i][j];
                    dp[i][l+j]=max(dp[i][l+j],dp[i-1][l+j]);
                    dp[i][l+j]=max(dp[i][l+j],dp[i-1][l]+sum);
                }
                // dp[i][l+j]=max(dp[i-1][l+j],dp[i-1][l]+sum);
            }
            // for (j=0;j<=i*k;++j) printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
        }
        printf("Case #%d: %d\n",cas++,dp[n][p]);
    }
    return 0;
}