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
ll x,y,a,b;
int main(){
    int T;
    for (read(T);T--;){
    read(x),read(y),read(a),read(b);
    if ((y-x)%(a+b)!=0) puts("-1");
    else printf("%lld\n",(y-x)/(a+b));
    }
    return 0;
}