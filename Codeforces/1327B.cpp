→ SourceCopy
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
int T,n,k,i,j,x,m[N],g[N];
bool vis[N];
int main(){
    for (read(T);T--;){
        read(n);
        int cnt=0;
        for (i=1;i<=n;++i) m[i]=vis[i]=0;
        for (i=1;i<=n;++i){
            read(k);
            for (j=1;j<=k;++j){
                read(x);
                if (!m[i] && !vis[x]){
                    m[i]=x;
                    vis[x]=1;
                    cnt++;
                }
            }
        }
        int A=-1,B=-1;
        for (i=1;i<=n;++i){
            if (!m[i]) A=i;
            if (!vis[i]) B=i;
        }
        if (~A){
            puts("IMPROVE");
            printf("%d %d\n",A,B);
        }
        else puts("OPTIMAL");
    }
    return 0;
}