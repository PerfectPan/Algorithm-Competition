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
const int N=2000+10;
int n,h,l,r,i,j,x,ans,dp[N][N];
int main(){
    read(n),read(h),read(l),read(r);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for (i=1;i<=n;++i){
        read(x);
        for (j=0;j<h;++j){
            int pre=j-x;
            if (pre<0) pre+=h;
            if (dp[i-1][pre]!=-1) dp[i][j]=max(dp[i][j],dp[i-1][pre]+(j>=l && j<=r));

            pre=j-x+1;
            if (pre<0) pre+=h;
            if (dp[i-1][pre]!=-1) dp[i][j]=max(dp[i][j],dp[i-1][pre]+(j>=l && j<=r));
            ans=max(ans,dp[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}