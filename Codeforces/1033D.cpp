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
const int P=998244353;
int n,i,j,ans=1;
ll a[N];
map<ll,int>mp;
inline ll test(ll a,int b){
    ll ret=pow(a,1./b)+.5;
    ll tmp=1;
    for (int i=1;i<=b;++i) tmp*=ret;
    if (tmp==a) return ret;
    return -1;
}
inline void up(ll x){
    if (mp.find(x)!=mp.end()) return;
    for (int i=1;i<=n;++i){
        ll u=a[i];
        while (!(u%x)) ++mp[x],u/=x;
    }
}
int main(){
	read(n);
    for (i=1;i<=n;++i) read(a[i]);
    for (i=1;i<=n;++i){
        ll tmp=-1;
        for (j=4;j>=2;--j){
            if (~(tmp=test(a[i],j))){
                up(tmp);
                break;
            }
        }
        if (!~tmp){
            bool f=0;
            for (j=1;j<=n;++j)if(a[j]!=a[i] && __gcd(a[i],a[j])>1){
                ll u=__gcd(a[i],a[j]);
                ll v=a[i]/u;
                up(u),up(v);
                f=1;
                break;
            }
            if (!f){
                for (j=1;j<i;++j)if(a[j]==a[i])f=1;
                if (!f){
                    int cnt=0;
                    for (j=1;j<=n;++j)if(a[j]==a[i])cnt++;
                    ans=(ll)ans*(cnt+1)%P;
                    ans=(ll)ans*(cnt+1)%P;
                }
            }
        }
    }
    for (map<ll,int>::iterator it=mp.begin();it!=mp.end();++it){
        int num=(*it).second;
        ans=(ll)ans*(num+1)%P;
    }
    printf("%d\n",ans);
	return 0;
}