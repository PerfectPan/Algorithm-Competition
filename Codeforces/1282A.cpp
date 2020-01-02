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
int T,a,b,c,r;
int main(){
    for (read(T);T--;){
        read(a),read(b),read(c),read(r);
        if (b<a) swap(a,b);
        int L=min(max(a,c-r),b),R=max(min(b,c+r),a);
        printf("%d\n",L-a+b-R);
    }
    return 0;
}