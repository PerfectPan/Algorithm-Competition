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
const int N=1e5+10;
const int M=7;
int n,p,k,o,i,j,kk,S,s[N][M];
pair<int,int>a[N];
ll dp[N][1<<M];
inline bool cmp(const pair<int,int>&A,const pair<int,int>&B){
    return A.first>B.first;
}
int main(){
    read(n),read(p),read(k);
    for (i=1;i<=n;++i){
        read(a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+1+n,cmp);
    ll sum=0;
    for(i=1;i<=n;++i)for(j=0;j<p;++j)read(s[i][j]);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    int tot=1<<p;
    for (i=1;i<=n;++i){
        for (S=0;S<tot;++S){
            int cnt=__builtin_popcount(S);
            if (i-1-cnt<k){
              if (~dp[i-1][S]) dp[i][S]=dp[i-1][S]+a[i].first;
            }
            else{
              if (~dp[i-1][S]) dp[i][S]=dp[i-1][S];
            }
            for (j=0;j<p;++j)if((S&(1<<j))&&(~dp[i-1][S^(1<<j)])){
                dp[i][S]=max(dp[i][S],dp[i-1][S^(1<<j)]+s[a[i].second][j]);
            }
        }
    }
    printf("%lld\n",dp[n][tot-1]);
    return 0;
}