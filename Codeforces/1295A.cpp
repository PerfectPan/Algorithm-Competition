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
        if (n==2) puts("1");
        else if (n==3) puts("7");
        else if (n==4) puts("11");
        else if (n%2==0){
            for (int i=1;i<=n/2;++i) putchar('1');
            puts("");
        }
        else{
            putchar('7');
            n-=3;
            for (int i=1;i<=n/2;++i) putchar('1');
            puts("");
        }
    }
    return 0;
}