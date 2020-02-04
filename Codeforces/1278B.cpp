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
ll a,b;
int main(){
    for (read(T);T--;){
        read(a),read(b);
        if (a>b) swap(a,b);
        ll x=b-a;
        ll l=0,r=100000000LL,ans=-1;
        while (l<=r){
            ll mid=l+((r-l)>>1LL);
            ll xx=b-a+mid*(mid+1)/2;
            if (1.0*xx/2<=mid*(mid+1)/2){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        while ((b-a+ans*(ans+1)/2)%2==1) ans+=1;
        printf("%lld\n",ans);
    }
    return 0;
}