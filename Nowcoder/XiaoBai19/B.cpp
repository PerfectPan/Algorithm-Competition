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
const int N=3000+10;
const int P=2333;
int n,m,i,j,a[N][N],dp[N][N];
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int main(){
    read(n),read(m);
    for (i=n;i>=1;--i){
        for (j=1;j<=m;++j){
            read(a[i][j]);
        }
    }
    dp[1][1]=1;
    for (i=1;i<=n;++i){
        for (j=1;j<=m;++j){
            if (i==1 && j==1) continue;
            if (a[i][j]==1) continue;
            if (!a[i-1][j]) up(dp[i][j],dp[i-1][j]);
            if (!a[i][j-1]) up(dp[i][j],dp[i][j-1]);
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}