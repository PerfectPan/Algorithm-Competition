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
const int N=1e6+10;
const int P=1e9+7;
int n,i,dp[N][2][2];
char s[N];
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    dp[0][0][0]=dp[0][0][1]=1;
    for (i=1;i<=n;++i){
        if (s[i]=='0'){
            dp[i][0][0]=dp[i-1][0][0];
        }
        else if (s[i]=='1'){
            dp[i][0][0]=dp[i-1][1][0];
            dp[i][0][1]=dp[i-1][0][0];
        }
        else if (s[i]=='2'){
            dp[i][0][1]=dp[i-1][1][0];
        }
        else if (s[i]=='*'){
            dp[i][1][0]=dp[i][1][1]=(dp[i-1][0][1]+dp[i-1][1][1])%P;
        }
        else if (s[i]=='?'){
            dp[i][0][0]=dp[i][0][1]=(dp[i-1][0][0]+dp[i-1][1][0])%P;
            dp[i][1][0]=dp[i][1][1]=(dp[i-1][0][1]+dp[i-1][1][1])%P;
        }
    }
    printf("%d\n",(dp[n][0][0]+dp[n][1][0])%P);
    return 0;
}