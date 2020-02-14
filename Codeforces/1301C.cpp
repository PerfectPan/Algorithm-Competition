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
int T,n,m;
int main(){
    for (read(T);T--;){
        read(n),read(m);
        ll tot=1LL*n*(n+1)/2;
        if (!m){
            puts("0");
            continue;
        }
        int left=(n-m)/(m+1);
        int _=(n-m)%(m+1);
        int __=m-_+1;
        ll a=1LL*left*(left+1)/2*__+1LL*_*(left+1)*(left+2)/2;
        printf("%lld\n",tot-a);
    }
    return 0;
}