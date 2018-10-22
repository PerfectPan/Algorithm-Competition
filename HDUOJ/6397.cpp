#include <bits/stdc++.h>
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
const int N=2e5+10;
int T,n,m,k,i,ans,f[N],inv[N];
int fexp(int a,int n){
    int res=1;
    while (n){
        if (n&1) res=1LL*res*a%P;
        a=1LL*a*a%P;
        n>>=1;
    }
    return res;
}
void up(int&a,int b){
    if (b==P) b=0;
    a+=b;if(a>=P)a-=P;
}
int C(int n,int m){return 1LL*(1LL*f[n]*inv[m]%P)*inv[n-m]%P;}
void pre(){
    for (inv[0]=f[0]=i=1;i<=N-10;++i) f[i]=1LL*f[i-1]*i%P;
    for (inv[N-10]=fexp(f[N-10],P-2),i=N-11;i>=1;--i) inv[i]=1LL*inv[i+1]*(i+1)%P;
}
int main(){
    pre();
    for (read(T);T--;){
        read(n),read(m),read(k);
        ans=C(m+k-1,m-1);
        for (i=1;;++i){
            if (k-i*n<0 || i>m) break;
            if (i&1) up(ans,P-1LL*C(m,i)*C(k-i*n+m-1,m-1)%P);
            else up(ans,1LL*C(m,i)*C(k-i*n+m-1,m-1)%P);
        }
        printf("%d\n",ans);
    }
    return 0;
}