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
int T,n,i,j,a[N],cnt[N],cnt2[N];
map<int,int>mp;
int main(){
    for (read(T);T--;){
        read(n);
        int o=0,e=0;
        for (i=1;i<=2*n;++i){
            read(a[i]);
            if (a[i]==1) o++;
            else e++;
            cnt[i]=cnt2[i]=0;
        }
        int delta=o-e;
        mp.clear();
        mp[0]=n+1;
        for (i=n,j=1;i>=1,j<=n;--i,++j){
            cnt[j]=cnt[j-1];
            if (a[i]==1) cnt[j]+=1;
            else cnt[j]-=1;
            if (mp.find(cnt[j])==mp.end()) mp[cnt[j]]=i;
        }
        int ans=-1;
        if (mp.find(delta)!=mp.end()){
            if (ans==-1) ans=mp[delta]-1+n;
            else ans=max(ans,mp[delta]-1+n);
        }
        for (i=n+1,j=1;i<=2*n;++i,++j){
            cnt2[j]=cnt2[j-1];
            if (a[i]==1) cnt2[j]+=1;
            else cnt2[j]-=1;
            if (mp.find(delta-cnt2[j])!=mp.end()){
                if (ans==-1) ans=mp[delta-cnt2[j]]-1+n-j;
                else ans=max(ans,mp[delta-cnt2[j]]-1+n-j);
            }
        }
        printf("%d\n",2*n-ans);
    }
    return 0;
}