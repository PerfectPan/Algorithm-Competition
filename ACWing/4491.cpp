#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n, x, y;
int main() {
    read(n);
    int p=0;
    for (int i=1;i<=n;++i){
        read(x);
        p+=x;
        y=min(y,p);
    }
    printf("%d\n",p-y);
    return 0;
}

