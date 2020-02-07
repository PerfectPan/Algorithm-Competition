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
int T,s;
ll tot;
int main(){
    for (read(T);T--;){
        read(s);tot=s;
        while (s>9){
            tot+=s/10;
            s=s/10+s%10;
        }
        printf("%lld\n",tot);
    }
    return 0;
}