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
int T,n,i,k,cas=1,a[N];
bool check(int x){
    int cnt=0;
    for (int i=2;i<=n;++i){
        int d=a[i]-a[i-1];
        if (d>x){
            cnt+=d/x;
            if (d%x==0) cnt--;
        }
    }
    return cnt<=k;
}
int main(){
    for (read(T);T--;){
        read(n),read(k);
        int mx=0;
        for (i=1;i<=n;++i){
            read(a[i]);
            if (i>1) mx=max(mx,a[i]-a[i-1]);
        }
        int l=1,r=mx,ans=-1;
        while (l<=r){
            int mid=l+((r-l)>>1);
            if (check(mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}