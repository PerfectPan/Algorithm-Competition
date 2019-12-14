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
int n,i,res=1,a[N],l[N],r[N];
int main(){
    read(n);
    for (i=1;i<=n;++i) read(a[i]);
    for (l[1]=1,i=2;i<=n;++i){
        if (a[i]>a[i-1]){
            l[i]=l[i-1]+1;
            res=max(res,l[i]);
        }
        else l[i]=1;
    }
    for (r[n]=1,i=n-1;i>=1;--i){
        if (a[i]<a[i+1]) r[i]=r[i+1]+1;
        else r[i]=1;
    }
    for (i=2;i<=n-1;++i){
        if (a[i+1]>a[i-1]) res=max(res,l[i-1]+r[i+1]);
    }
    printf("%d\n",max(r[1],res));
    return 0;
}