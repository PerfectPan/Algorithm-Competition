#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define Key_Value ch[ch[root][1]][0]
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define ALL(x) x.begin(),x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
const int maxn=500000+5;
const int INF=0x3f3f3f3f;
const int P=1000000007;
const double PI=acos(-1.0);
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
template <typename T1,typename T2>inline void gmax(T1 &a,T2 b){if (b>a) a=b;}
template <typename T1,typename T2>inline void gmin(T1 &a,T2 b){if (b<a) a=b;}
const int N=5e5+10;
int n,i,cnt[N];
ll sum,ans,a[N],suff[N],pre[N];
int main(){
    read(n);
    for (i=1;i<=n;i++) sum+=read(a[i]);
    if (sum%3!=0) puts("0");
    else{
        sum/=3;
        for (i=n;i>=1;i--){
            suff[i]=a[i]+suff[i+1];
            if (suff[i]==sum) cnt[i]++;
            cnt[i]+=cnt[i+1];
        }
        for (i=1;i<=n-2;i++){
            pre[i]=a[i]+pre[i-1];
            if (pre[i]==sum) ans+=cnt[i+2];
        }
        printf("%lld\n",ans);
    }
    return 0;
}