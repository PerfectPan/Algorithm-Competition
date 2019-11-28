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
int n,i,a[N];
int main(){
    read(n);
    for (i=1;i<=n;++i) read(a[i]);
    int pre=1,cnt=1,ans=0;
    for (i=2;i<=n;++i){
        if (a[i]!=a[i-1]+1){
            if (a[pre]==1 || a[i-1]==1000) ans=max(ans,cnt-1);
            else ans=max(ans,cnt-2); 
            cnt=1;
            pre=i;
        }
        else cnt+=1;
    }
    if (a[pre]==1 || a[n]==1000) ans=max(ans,cnt-1);
    printf("%d\n",ans);
    return 0;
}