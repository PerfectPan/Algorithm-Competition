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
int n,m,i,j,x,ans,mn[N];
vector<int>G[N];
int main(){
    read(n),read(m);
    for (i=1;i<=n;++i){
        for (j=1;j<=m;++j){
            read(x);
            G[i].PB(x);
        }
    }
    for (i=0;i<m;++i){
        for (j=0;j<n;++j) mn[j]=j+n;
        for (j=1;j<=n;++j){
            if (G[j][i]>=i+1 && G[j][i]<=n*m && G[j][i]%m==(i+1)%m){
                int row=(G[j][i]-i-1)/m+1;
                if (j>=row) mn[j-row]--;
                else mn[n-row+j]--;
            }
        }
        ans+=*min_element(mn,mn+n);
    }
    printf("%d\n",ans);
    return 0;
}