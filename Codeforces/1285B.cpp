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
int T,n,i,a[N];
ll pre[N],mn[N];
int main(){
    for (read(T);T--;){
        read(n);
        mn[0]=1e18;
        ll ans=-1e18;
        for (i=1;i<=n;++i){
            read(a[i]);
            pre[i]=pre[i-1]+a[i];
            mn[i]=min(mn[i-1],pre[i]);
            ans=max(ans,pre[i]-mn[i]);
            if (i!=n) ans=max(ans,pre[i]);
        }
        if (ans>=pre[n]) puts("NO");
        else puts("YES");
    }
    return 0;
}