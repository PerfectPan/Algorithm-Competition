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
const int N=2e5+10;
const int P=998244353;
int n,k,i,pre=-1,p[N];
int main(){
    read(n),read(k);
    ll sum=0,cnt=1;
    for (i=1;i<=n;++i){
        read(p[i]);
        if (p[i]>=n-k+1){
            if (pre==-1) pre=i;
            else cnt=1ll*cnt*(i-pre)%P;
            pre=i;
            sum+=p[i];
        }
    }
    printf("%lld %lld\n",sum,cnt);
    return 0;
}