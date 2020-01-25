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
int T,a[3],n;
int main(){
    for (read(T);T--;){
        for (int i=0;i<3;++i) read(a[i]);
        read(n);
        sort(a,a+3);
        n-=a[2]-a[0];
        n-=a[2]-a[1];
        if (n>=0 && n%3==0) puts("YES");
        else puts("NO");
    }
    return 0;
}