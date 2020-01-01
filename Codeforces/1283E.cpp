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
int n,i,cnt,cnt2,x[N];
bool vis[N],vis2[N];
int main(){
    read(n);
    for (i=1;i<=n;++i) read(x[i]);
    sort(x+1,x+1+n);
    for (i=1;i<=n;++i){
        if (!vis[x[i]-1]) vis[x[i]-1]=1,cnt+=1;
        else if (!vis[x[i]]) vis[x[i]]=1,cnt+=1;
        else if (!vis[x[i]+1]) vis[x[i]+1]=1,cnt+=1;
    }
    for (i=1;i<=n;++i){
        if (vis2[x[i]] || vis2[x[i]-1] || vis2[x[i]+1]) continue;
        else vis2[x[i]+1]=1,cnt2+=1;
    }
    printf("%d %d\n",cnt2,cnt);
    return 0;
}
