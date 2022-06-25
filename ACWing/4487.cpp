#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e6+10;
int n,x,stk[N];
ll a[N];
int main() {
  read(n);
  for (int i=1;i<=n;++i) {
      read(x);
      a[i]=a[i-1]+x-100;
  }
  int top=0,ans=0;
  stk[++top]=0;
  for (int i=1;i<=n;++i){
      if (a[stk[top]]>a[i]) stk[++top]=i;
      else if (a[stk[top]]<a[i]){
          int l=1,r=top,res=-1;
          while (l<=r){
              int mid=l+((r-l)>>1);
              if (a[stk[mid]]<a[i]){
                  res=mid;
                  r=mid-1;
              } else {
                  l=mid+1;
              }
          }
          ans=max(ans,i-stk[res]);
      }
  }
  printf("%d\n",ans);
  return 0;
}

