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
const int N=1000+10;
struct Point{
    int x,y,t;
    double p;
    bool operator < (const Point&rhs)const{
        return t<rhs.t;
    }
}p[N];
int n,i,j;
double ans,dp[N];
int main(){
    read(n);
    for (i=1;i<=n;++i){
        scanf("%d%d%d%lf",&p[i].x,&p[i].y,&p[i].t,&p[i].p);
    }
    sort(p+1,p+1+n);
    for (i=1;i<=n;++i){
        for (j=i-1;j>=1;--j){
            int delta=abs(p[j].t-p[i].t);
            if (1LL*(p[i].x-p[j].x)*(p[i].x-p[j].x)+1LL*(p[i].y-p[j].y)*(p[i].y-p[j].y)<=1LL*delta*delta){
                dp[i]=max(dp[i],dp[j]);
            }
        }
        dp[i]+=p[i].p;
        ans=max(ans,dp[i]);
    }
    printf("%.8f\n",ans);
    return 0;
}