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
int n,i;
ll pre,x;
int main(){
    read(n);
    read(x);pre=x;
    for (i=1;i<n;++i){
        read(x);
        if (x&1) puts("0");
        else puts("1");
        pre=x;
    }
    return 0;
}