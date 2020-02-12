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
int T,n,i,l,r;
int main(){
    for (read(T);T--;){
        read(n);
        int a=0,b=1e9;
        for (i=1;i<=n;++i){
            read(l),read(r);
            a=max(a,l),b=min(b,r);
        }
        if (a<=b) printf("0\n");
        else printf("%d\n",a-b);
    }
    return 0;
}