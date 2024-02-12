// k = 1 一定有解，如果 a[1] > 0，就让 a[1] 放最后一个，前面都是 0，否则把 a[1] 放第一个，后面都是 0
// 先用差分确保后面一段都是递增的，然后算出来 a_{n - k + 2}，根据限制条件需要满足 a_1 + a_2 + ... + a_{n - k + 1} <= (n - k + 1) * a_{n - k + 2}
// 如果满足就有解，只要你平均的分给前 n - k + 1 个就可以了，即 s_{n - k + 1} / (n - k + 1)，如果有余数，就每个余数分别 + 1
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
constexpr int N = 2e5 + 10;
int T, n, k, a[N];
int main() {
    for (read(T); T--;) {
        read(n), read(k);
        for (int i = 1; i <= k; ++i) {
            read(a[i]);
        }
        if (k == 1) {
            puts("Yes");
            continue;
        }
        bool flag = true;
        for (int i = k; i > 1; --i) {
            a[i] = a[i] - a[i - 1];
            if (i < k && a[i + 1] < a[i]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            puts("No");
            continue;
        }
        ll total = 1LL * a[2] * (n - k + 1);
        puts(total >= a[1] ? "Yes" : "No");
    }
    return 0;
}
