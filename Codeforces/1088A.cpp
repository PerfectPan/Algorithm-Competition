#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
int x,a,b;
int main(){
    read(x);
    for (int i=1;i<=x;++i){
        for (int j=1;j<=x;++j){
            if (i%j==0 && i*j>x && i/j<x){
                return printf("%d %d\n",j,i),0;
            }
        }
    }
    puts("-1");
    return 0;
}