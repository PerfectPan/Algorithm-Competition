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
        int mn=1e9+10,mx=-1;
        for (i=1;i<=n;++i){
            read(a[i]);
        }
        for (i=1;i<=n;++i)if(a[i]!=-1){
            if (i>1 && a[i-1]==-1){
                mx=max(mx,a[i]);
                mn=min(mn,a[i]);
            }
            if (i<n && a[i+1]==-1){
                mx=max(mx,a[i]);
                mn=min(mn,a[i]);
            }
        }
        int k=(mn+mx)/2;
        if (mx==-1) k=1;
        int ans=-1;
        for (i=1;i<n;++i){
            int A=0,B=0;
            if (a[i]!=-1) A=a[i];
            else A=k;
            if (a[i+1]!=-1) B=a[i+1];
            else B=k;
            ans=max(ans,abs(A-B));
        }
        printf("%d %d\n",ans,k);
    }
    return 0;
}