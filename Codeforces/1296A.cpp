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
const int N=2000+10;
int T,sum,n,x,odd,even;
int main(){
    for (read(T);T--;){
        sum=odd=even=0;
        for (read(n);n--;){
            read(x);
            sum+=x;
            odd|=x&1;
            even|=!(x&1);
        }
        if (sum&1) puts("YES");
        else if (odd && even) puts("YES");
        else puts("NO");
    }
    return 0;
}