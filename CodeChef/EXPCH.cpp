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
const int N=1e7+10;
const int P=1e9+7;
int T,n,i,j,k,l,r,len,ans,o,dp[N<<1];
char s[N];
int fexp(int a,int n){
    int res=1;
    while (n){
        if (n&1) res=1ll*res*a%P;
        a=1ll*a*a%P;
        n>>=1;
    }
    return res;
}
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int main(){
    for (read(T);T--;){
        read(n);
        scanf("%s",s+1);
        int X=0,Y=1ll*n*(n+1)/2%P;
        for (o=n,i=0;i<=n*2+1;++i) dp[i]=0; 
        for (i=1;i<=n;++i){
            up(dp[o],1);
            if (s[i]=='(') --o;
            else if (s[i]==')'){
                ++o;
                up(X,1ll*dp[o-1]*(n-i+1)%P);
                up(dp[o+1],dp[o-1]);
                dp[o-1]=0;
            }
        }
        printf("%d\n",1ll*X*fexp(Y,P-2)%P);
    }
    return 0;
}
