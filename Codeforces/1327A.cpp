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
int T,n,k;
int main(){
    for (read(T);T--;){
        read(n),read(k);
        if (n%2==k%2 && n>=1ll*k*k) puts("YES");
        else puts("NO");
    }
    return 0;
}