// Credits: https://docs.qq.com/sheet/DWGFoRGVZRmxNaXFz?tab=BB08J2
// 题意：输入 n(2≤n≤50) m(2≤m≤50) 和长为 n 的数组 a，长为 m 的数组 b，元素范围 [-1e9,1e9]。
//      你必须恰好删除 a 中的一个数字。
//      最小化 a[i] * b[j] 的最大值，输出这个最大值。
// 注意到最大值只能在最小数和最大数之间产生（两两组合有 4 个乘积）。
// 如果 a[0] 与 b[0] 或 b[m-1] 乘积更大，那么删除 a[0]，否则删除 a[n-1]。
// 删除后重新算最小数和最大数，取这 4 个乘积的最大值，作为答案。
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
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
int n, m;
ll a[N], b[N];
int main() {
    read(n), read(m);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        read(b[i]);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    if (max(a[1] * b[1], a[1] * b[m]) > max(a[n] * b[1], a[n] * b[m])) {
        printf("%lld\n", max({ a[n] * b[1], a[n] * b[m], a[2] * b[1], a[2] * b[m] }));
    } else {
        printf("%lld\n", max({ a[n - 1] * b[1], a[n - 1] * b[m], a[1] * b[1], a[1] * b[m] }));
    }
    return 0;
}
