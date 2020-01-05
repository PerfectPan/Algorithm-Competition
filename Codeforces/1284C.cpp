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
const int N=3e5+10;
int n,m,i,ans,pre[N];
inline void up(int&a,int b){a+=b;if(a>=m)a-=m;}
int main(){
    read(n),read(m);
    for (pre[0]=i=1;i<=n;++i) pre[i]=1LL*pre[i-1]*i%m;
    for (ans=i=0;i<=n-1;++i){
        int res=1LL*(n-i)*(n-i)%m;
        res=1LL*res*pre[i+1]%m;
        res=1LL*res*pre[n-i-1]%m;
        up(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}