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
const int N=100+10;
int T,n,i;
ll h,a[N];
bool check(ll x){
    ll r=a[0]+x-1,res=r-a[0]+1;
    for (i=1;i<n;++i){
        ll r1=a[i]+x-1;
        res+=max(0LL,r1-max(a[i],r+1)+1);
        r=max(r,r1);
    }
    return res>=h;
}
int main() {
    for (read(T);T--;){
        read(n),read(h);
        for (i=0;i<n;++i) read(a[i]);
        ll l=1,r=h,ans=-1;
        while (l<=r){
            ll mid=l+((r-l)>>1LL);
            if (check(mid)) {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

