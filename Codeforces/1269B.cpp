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
const int N=2000+10;
int n,m,i,j,a[N],b[N];
map<int,int>mp;
int main(){
    read(n),read(m);
    for (i=1;i<=n;++i) read(a[i]);
    for (i=1;i<=n;++i) read(b[i]);
    int ans=-1;
    for (i=1;i<=n;++i){
        int x=0;
        if (a[1]<=b[i]) x=b[i]-a[1];
        else x=b[i]-a[1]+m;
        for (j=1;j<=n;++j) mp[b[j]]+=1;
        bool flag=0;
        for (j=1;j<=n;++j){
            int y=(a[j]+x)%m;
            if (mp.find(y)!=mp.end()){
                if (mp[y]==0) flag=1;
                else mp[y]-=1;
            }
            else flag=1;
        }
        if (!flag){
            if (ans==-1) ans=x;
            else ans=min(ans,x);
        }
        mp.clear();
    }
    printf("%d\n",ans);
    return 0;
}