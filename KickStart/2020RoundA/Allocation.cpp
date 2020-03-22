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
int n,b,T,cas=1,cnt,i,a[N];
int main(){
    for (read(T);T--;){
        read(n),read(b);
        for (i=1;i<=n;++i) read(a[i]);
        sort(a+1,a+1+n);
        int cnt=0;
        for (i=1;i<=n;++i){
            b-=a[i];
            if (b>=0) cnt++;
            else break;
        }
        printf("Case #%d: %d\n",cas++,cnt);
    }
    return 0;
}
