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
int n,i,j,l,cnt,tot,num[N],mm[N],mx[N];
ll ans;
int main(){
    read(n);
    for (i=1;i<=n;++i){
        read(l);
        int mn=1e9;
        bool flag=0;
        for (j=1;j<=l;++j){
            read(num[j]);
            if (mn<num[j]){
                flag=1;
            }
            mn=min(mn,num[j]);
        }
        if (flag) ans+=2LL*n-1,cnt++;
        else{
            ++tot;
            mm[tot]=num[l];
            mx[tot]=num[1];
        }
    }
    sort(mm+1,mm+1+tot);
    sort(mx+1,mx+1+tot);
    for (i=1;i<=tot;++i){
        int pos=upper_bound(mx+1,mx+1+tot,mm[i])-mx;
        if (pos<=tot) ans+=tot-pos+1;
    }
    ans-=1LL*cnt*(cnt-1);
    printf("%lld\n",ans);
    return 0;
}