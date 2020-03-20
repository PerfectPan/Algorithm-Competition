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
const int N=2e5+10;
int n,i,mx,b[N],a[N];
int main(){
    read(n);
    for (i=1;i<=n;++i){
        read(b[i]);
        if (i==1) a[1]=b[1],mx=a[1];
        else{
            a[i]=b[i]+mx;
            mx=max(mx,a[i]);
        }
    }
    for (i=1;i<=n;++i) printf("%d%c",a[i],i==n?'\n':' ');
    return 0;
}