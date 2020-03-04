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
int n,i,j,a[N],m,pre[N];
inline void up(int&x,int y){x+=y;if(x>=m)x-=m;}
int main(){
    read(n),read(m);
    for (i=1;i<=n;++i) read(a[i]);
    // sort(a+1,a+1+n);
    if (n<=2000){
        int ans=1;
        pre[0]=0;
        // for (i=1;i<=n;++i) pre[i]=(pre[i-1]+a[i])%m,cout<<" "<<pre[i]<<endl;
        for (i=1;i<=n;++i){
            for (j=i+1;j<=n;++j){
                int d=abs(a[j]-a[i]);
                d%=m;
                if (d<0) d+=m;
                ans=1ll*ans*d%m;
            }
        }
        printf("%d\n",ans%m);
    }
    else puts("0");
    return 0;
}