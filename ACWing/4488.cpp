#include<cstdio>
#include<cstring>
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
const int N = 100+10;
int n,i,x;
int main() {
  read(n);
  bool flag = false;
  for (int i = 1; i <= n; ++i) {
    read(x);
    if (x == 1) {
      flag = true;
    }
  }
  puts(flag?"YES":"NO");
  return 0;
}

