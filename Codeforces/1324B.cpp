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
const int N=5000+10;
int T,n,i,a[N],vis[N];
int main(){
    for (read(T);T--;){
        read(n);
        memset(vis,0,sizeof(vis));
        bool flag=1;
        for (i=1;i<=n;++i){
            read(a[i]);
            if (vis[a[i]]){
                if (vis[a[i]]+1<i) flag=0;
            }
            else vis[a[i]]=i;
        }
        puts(!flag?"YES":"NO");
    }
    return 0;
}
