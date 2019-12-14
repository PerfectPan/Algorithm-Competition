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
int n,i,d,a[N],dis[N],ans[N];
vector<int>G[N],G2[N];
queue<pair<int,int> >Q;
int main(){
    read(n);
    for (i=1;i<=n;++i) read(a[i]);
    for (i=1;i<=n;++i){
        if (i-a[i]>=1) G[i-a[i]].push_back(i);
        if (i+a[i]<=n) G[i+a[i]].push_back(i);
    }
    for (d=0;d<2;++d){
        memset(dis,-1,sizeof(dis));
        queue<int>Q;
        for (i=1;i<=n;++i)if((a[i]&1)==d){
            dis[i]=0;
            Q.push(i);
        }
        while (!Q.empty()){
            int u=Q.front();Q.pop();
            for (i=0;i<(int)G[u].size();++i){
                int v=G[u][i];
                if (dis[v]==-1){
                    dis[v]=dis[u]+1;
                    Q.push(v);
                }
            }
        }
        for (i=1;i<=n;++i)if((a[i]&1)!=d){
            ans[i]=dis[i];
        }
    }
    for (i=1;i<=n;++i) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}