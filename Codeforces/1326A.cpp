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
int T,n;
int main(){
    for (read(T);T--;){
        read(n);
        if (n==1) puts("-1");
        else if (n==3) puts("239");
        else{
            putchar('5');
            for (int i=1;i<=n-1;++i) putchar('3');
            puts("");
        }
    }
    return 0;
}