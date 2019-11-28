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
const int N=1e5+10;
int n,i,u,v,d[N];
int main(){
    read(n);
    for (i=1;i<n;++i){
        read(u),read(v);
        d[u]++,d[v]++;
    }
    ll ans=0;
    for (i=1;i<=n;++i){
        ans+=(ll)d[i]*(d[i]-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}