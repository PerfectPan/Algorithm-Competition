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
int n,i,sz,a[N],b[N],sum[N*2];
vector<int>vec;
inline int lowbit(int x){return x&(-x);}
int get(int x){
    int ans=0;
    for (;x>0;x-=lowbit(x)) ans+=sum[x];
    return ans;
}
void update(int x,int v){for(;x<=sz;x+=lowbit(x))sum[x]+=v;}
void compress(){
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    sz=(int)vec.size();
}
int main(){
    read(n);
    for (i=1;i<=n;++i) read(a[i]);
    for (i=1;i<=n;++i) read(b[i]),vec.PB(a[i]-b[i]),vec.PB(b[i]-a[i]);
    compress();
    ll ans=0;
    for (i=1;i<=n;++i){
        int pos=upper_bound(vec.begin(),vec.end(),b[i]-a[i])-vec.begin();
        if (0<=pos && pos<=sz) ans+=get(sz)-get(pos);
        pos=lower_bound(vec.begin(),vec.end(),a[i]-b[i])-vec.begin();
        update(pos+1,1);
    }
    printf("%lld\n",ans);
    return 0;
}