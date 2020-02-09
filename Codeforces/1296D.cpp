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
int n,a,b,k,i,h,cnt[N];
int main(){
    read(n),read(a),read(b),read(k);
    for (i=1;i<=n;++i){
        read(h);
        h%=a+b;
        if (h==0) h=a+b;
        cnt[i]=max(0,(h-a+a-1)/a);
    }
    sort(cnt+1,cnt+1+n);
    for (i=1;i<=n;++i){
        if (k-cnt[i]>=0) k-=cnt[i];
        else break;
    }
    printf("%d\n",i-1);
    return 0;
}