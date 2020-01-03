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
const int N=1e5+10;
int T,n,i,a[N];
int main(){
    for (read(T);T--;){
        read(n);
        ll sum=0,sum_2=0;
        for (i=1;i<=n;++i){
            read(a[i]);
            sum+=a[i];
            sum_2^=a[i];
        }
        printf("2\n%lld %lld\n",sum_2,sum+sum_2);
    }
    return 0;
}