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
int T,n,p,k,i,ans,a[N],pre[N];
int work(int x){
    if (p<pre[x]) return 0;
    int tot=p-pre[x],cnt=x;
    for (int i=x+k;i<=n;i+=k){
        if (tot-a[i]<0) return cnt;
        cnt+=k;
        tot-=a[i];
    }
    return cnt;
}
int main(){
    for (read(T);T--;){
        read(n),read(p),read(k);
        for (i=1;i<=n;++i) read(a[i]);
        sort(a+1,a+1+n);
        for (i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
        for (ans=0,i=0;i<k;++i) ans=max(ans,work(i));
        printf("%d\n",ans);
    }
    return 0;
}