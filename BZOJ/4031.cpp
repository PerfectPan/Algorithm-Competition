#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define Key_Value ch[ch[root][1]][0]
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=500000+5;
const int INF=0x3f3f3f3f;
const int P=1000000000;
const double PI=acos(-1.0);
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
int n,m,cnt,s[11][11],a[82][82];
char maze[11][11];
int dir_x[]={0,-1};
int dir_y[]={-1,0};
int gs(){
    cnt--;
    for (int i=1;i<=cnt;i++){
        for (int j=1;j<=cnt;j++){
            a[i][j]=(a[i][j]+P)%P;
        }
    }
    ll ans=1;
    for (int j=1;j<=cnt;j++){
        for (int i=j+1;i<=cnt;i++){
            while (a[i][j]){
                ll t=a[j][j]/a[i][j];
                for (int k=j;k<=cnt;k++){
                    a[j][k]=(a[j][k]-t*a[i][k]%P+P)%P;
                    swap(a[i][k],a[j][k]);
                }
                ans*=-1;
            }
        }
        ans=ans*a[j][j]%P;
    }
    return (ans+P)%P;
}
int main(){
    read(n),read(m);
    for (int i=1;i<=n;i++){
        scanf("%s",&maze[i][1]);
    }
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=m+1;j++){
            if (i==0 || i==n+1 || j==0 || j==m+1) maze[i][j]='*';
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (maze[i][j]=='.') s[i][j]=++cnt;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (maze[i][j]=='.'){
                for (int k=0;k<2;k++){
                    int tx=dir_x[k]+i;
                    int ty=dir_y[k]+j;
                    if (maze[tx][ty]=='.'){
                        int u=s[i][j],v=s[tx][ty];
                        a[u][u]++,a[v][v]++;
                        a[u][v]--,a[v][u]--;
                    }
                }
            }
        }
    }
    printf("%d\n",gs());
    return 0;
}
