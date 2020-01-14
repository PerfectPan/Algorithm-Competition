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
ll x;
int main(){
    read(x);
    ll m=sqrt(x+0.5);
    ll ans=-1;
    for (ll i=1;i<=m;++i){
        if (x%i==0 && __gcd(i,x/i)==1){
            if (ans==-1) ans=max(i,x/i);
            else ans=min(ans,max(i,x/i));
        }
    }
    printf("%lld %lld\n",ans,x/ans);
    return 0;
}

// a=k g b=k' g  
// k和k'互质 __gcd(kk',g);
// lcm=k k' g  1 2 2

