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
const int N=1e5+10;
int n,k,x,i,j,a[N];
int main(){
    read(n),read(k);
    for (i=1;i<=n;++i) read(a[i]);
    sort(a+1,a+1+n);
    for (i=1,j=1;i<=k;++i){
        if (j>n) puts("0");
        else{
            while (j<=n && (a[j]-=x)==0) j++; 
            printf("%d\n",a[j]);
            x+=a[j++];
        }
    }
    return 0;
}