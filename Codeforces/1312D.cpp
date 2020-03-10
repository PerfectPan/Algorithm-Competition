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
const int P=998244353;
int n,m,i,ans;
int fexp(int a,int n){
    int res=1;
    while (n){
        if (n&1) res=1ll*res*a%P;
        n>>=1;
        a=1ll*a*a%P;
    }
    return res;
}
// C(m,n-1)*(n-2)*2^{n-3} 只有一对数相等可选n-1 选出来以后最大的减去剩下来 n-2个数拿一个出来当相等的数
// 剩下来 n-3个数要么在峰值左边要么在峰值右边一共2^{n-3}种选择。 
// C(m,n-1)=m!/(n-1)!/(m-n+1)!
// 分步做的思想 最大值已经在选出来的过程中就确定了！
int main(){
    read(n),read(m);
    if (n==2) return puts("0"),0;
    ans=1ll*(n-2)*fexp(2,n-3)%P;
    int _n=1,_m=1,_n_m=1;
    for (i=1;i<=n-1;++i) _n=1ll*_n*i%P;
    for (i=1;i<=m;++i) _m=1ll*_m*i%P;
    for (i=1;i<=m-n+1;++i) _n_m=1ll*_n_m*i%P;
    int C=1ll*_m*fexp(_n,P-2)%P*fexp(_n_m,P-2)%P;
    printf("%lld\n",1ll*ans*C%P);
    return 0;
}