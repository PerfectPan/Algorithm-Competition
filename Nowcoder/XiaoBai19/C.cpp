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
const int N=1000+10;
int n,m,k,i,j,res,ans[N][N];
char s[N][N];
int main(){
    read(n),read(m),read(k);
    for (i=1;i<=n;++i){
        scanf("%s",s[i]+1);
    }
    for (i=1;i<=n;++i){
        for (j=1;j<=m;++j){
            ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
            ans[i][j]+=s[i][j]=='1';
        }
    }
    for (i=1;i<=n;++i){
        for (j=1;j<=m;++j){
            if (i-k+1>=1 && j-k+1>=1){
                if (ans[i][j]+ans[i-k][j-k]-ans[i-k][j]-ans[i][j-k]>0){
                    res++;
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}