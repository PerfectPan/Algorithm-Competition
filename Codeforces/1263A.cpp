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
int T;
ll a[3];
int main(){
    for (read(T);T--;){
        read(a[0]),read(a[1]),read(a[2]);
        sort(a,a+3);
        ll ans=0;
        if (a[0]+a[1]<=a[2]) ans=a[0]+a[1];
        else{
            ll x=a[0]+a[1]-a[2];
            ans+=(x+1)/2;
            a[0]-=(x+1)/2;
            a[1]-=(x+1)/2;
            ans+=a[0]+a[1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}