#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T& x) {
    x = 0; int f = 0; char ch = getchar();
    while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x = f ? -x : x;
}
constexpr int N = 1e5 + 10;
int T, n, a[N];
ll pre[N], suff[N];
int main() {
    for (read(T); T--;) {
        read(n);
        for (int i = 1; i <= n; ++i) {
            read(a[i]);
        }
        pre[0] = 0;
        for (int i = 1, j = 0; i <= n; ++i, j ^= 1) {
            pre[i] = pre[i - 1];
            if ((j & 1) && i + 1 <= n) {
                pre[i] += max(0, max(a[i - 1], a[i + 1]) + 1 - a[i]); 
            }
        }
        if (n & 1) {
            printf("%lld\n", pre[n]);
            continue;
        }
        ll ans = pre[n];
        suff[n + 1] = 0;
        for (int i = n, j = 0; i >= 1; --i, j ^= 1) {
            suff[i] = suff[i + 1];
            if ((j & 1) && i - 1 >= 1) {
                suff[i] += max(0, max(a[i - 1], a[i + 1]) + 1 - a[i]);
                ans = min(ans, suff[i] + (i - 2 >= 0 ? pre[i - 2] : 0));
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
