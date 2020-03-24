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
int n,i,a[10];
int fexp(int a,int n){
    int res=1;
    while (n){
        if (n&1) res=1ll*res*a%P;
        a=1ll*a*a%P;
        n>>=1;
    }
    return res;
}
int main(){
    read(n);
    for (i=1;i<=n;++i){
        int ans=0,a=0,b=0,c=0;
        if (n>=i+2){
            a=10ll*81%P*fexp(10,n-i-2)%P;
            a=1ll*a*(n-i-1)%P;
        }
        if (n>=i+1){
            b=20ll*9%P*fexp(10,n-i-1)%P;
        }
        if (n==i){
            c=10ll;
        }
        ans=(a+b)%P;
        ans=(ans+c)%P;
        printf("%d%c",ans,i==n?'\n':' ');
    }
    return 0;
}