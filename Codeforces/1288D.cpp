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
const int N=3e5+10,M=10;
int n,m,i,j,mx,a[N][M],pos[1<<8];
bool check(int x,int f){
    for (i=0;i<(1<<m);++i) pos[i]=-1;
    for (i=1;i<=n;++i){
        int num=0,num2=0;
        for (j=1;j<=m;++j){
            if (a[i][j]>=x) num|=1<<(j-1);
            else num2|=1<<(j-1);
        }
        pos[num2]=i;
        for (int S=num;S!=0;S=(S-1)&num){
            if (pos[S]!=-1){
                if (f){
                    printf("%d %d\n",pos[S],i);
                }
                return true;
            }
        }
        if (pos[0]!=-1){
            if (f){
                printf("%d %d\n",pos[0],i);
            }
            return true;
        }
    }
    return false;
}
int main(){
    read(n),read(m);
    for (i=1;i<=n;++i){
        for (j=1;j<=m;++j){
            read(a[i][j]);
            mx=max(mx,a[i][j]);
        }
    }
    int l=0,r=mx,ans=-1;
    while (l<=r){
        int mid=l+((r-l)>>1);
        if (check(mid,0)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    check(ans,1);
    return 0;
}