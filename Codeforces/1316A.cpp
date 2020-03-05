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
const int N=1e3+10;
int T,n,m,i,a[N];
int main(){
  for (read(T);T--;){
    read(n),read(m);
    int sum=0;
    for (i=1;i<=n;++i) read(a[i]),sum+=a[i];
    printf("%d\n",min(sum,m));
  }
  return 0;
}