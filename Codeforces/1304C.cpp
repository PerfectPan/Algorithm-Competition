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
int q,n,m,i,j,t[N],l[N],h[N],cur[N],tot[N];
int main(){
    for (read(q);q--;){
        read(n),read(m);
        int L=m,R=m;
        bool flag=1;
        for (i=1;i<=n;++i){
            read(t[i]),read(l[i]),read(h[i]);
            if (!flag) continue;
            int x=t[i]-t[i-1];
            L-=x,R+=x;
            if (h[i]<L || R<l[i]){
                flag=0;
                continue;
            }
            L=max(L,l[i]);
            R=min(R,h[i]);
            if (L>R) flag=0;
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}