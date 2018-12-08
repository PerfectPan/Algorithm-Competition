#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=2000+10;
int n,i,j,delta,a[N];
vector<pair<int,int> >vec;
int main(){
    read(n);
    for (i=1;i<=n;++i) read(a[i]);
    for (i=n;i>=1;--i){
        if (a[i]<i-1) delta=i-1-a[i];
        else delta=n-(a[i]-i+1)%n;
        vec.PB(MP(1,delta));
        for (j=i;j>=1;--j) a[j]+=delta; 
    }
    printf("%d\n",(int)vec.size()+1),i=n;
    for (auto x:vec){
        printf("%d %d %d\n",x.first,i,x.second);
        --i;
    }
    printf("%d %d %d\n",2,n,n);
    return 0;
}