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
int n,i,j,ans=-1,pos=-1,a[N],bit[32];
int work(int x){
    int res=x;
    for (int i=0;i<32;++i)if(x&(1<<i)){
        if (bit[i]>1) res^=1<<i;
    }
    return res;
}
int main(){
    read(n);
    for (i=1;i<=n;++i){
        read(a[i]);
        for (j=0;j<32;++j)if(a[i]&(1<<j)) bit[j]++;
    }
    for (i=1;i<=n;++i){
        if (ans==-1 || ans<work(a[i])){
            ans=work(a[i]);
            pos=i;
        }
    }
    printf("%d",a[pos]);
    for (i=1;i<=n;++i)if(i!=pos) printf(" %d",a[i]);
    return 0;
}