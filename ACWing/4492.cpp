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
ll n, x, y;
int main() {
    read(n);
    if (n & 1) {
        int ans = 0;
        for (ll i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                n -= i;
                ans += 1;
                break;
            }
        } 
        if (!(n & 1)) {
            printf("%lld\n", 1LL * ans + (n / 2));
        } else {
            puts("1");
        }
    } else {
        printf("%lld\n", n / 2);
    }
    return 0;
}

