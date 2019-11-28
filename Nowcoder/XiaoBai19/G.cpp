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
const int N=20+10;
int n,i,a[N],b[N],c[N],d[N];
ll res;
void dfs(int i,int m,int cf){
    if (i==n){
        res=max(res,(ll)m*cf);
        return;
    }
    dfs(i+1,m+c[i+1],max(0,cf-d[i+1]));
    dfs(i+1,max(0,m-b[i+1]),cf+a[i+1]);
}
int main(){
    read(n);
    for (i=1;i<=n;++i){
        read(a[i]),read(b[i]),read(c[i]),read(d[i]);
    }
    dfs(0,0,0);
    printf("%lld\n",res);
    return 0;
}