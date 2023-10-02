// 方法 1: dp[i][0] 表示第 i 位没有进行翻转，dp[i][1] 表示第 i 位进行翻转了，然后从 dp[i - 1][0/1] 转移过来即可，答案为 max(dp[n][0], dp[n][1])
// 方法 2: 考虑进行一次操作，假设有两个负数 a b，中间都是正数，即 a x x x x b，那么我们可以通过连续的翻转使得序列变成 -a x x x x -b
// 即把两个负数改成正数，那么如果负数的个数为偶数个，我们可以两两配对，都将其改成正数；如果负数的个数为奇数个，那么势必最后会剩下一个负数 c
// 考虑到一个负数的时候我们仍然可以使用操作将这个负数变成正数，其相邻的数变成负数，以此类推，因此为了让答案最优，我们让绝对值最小的那个数变成负数即可
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#define MP make_pair
#define PB emplace_back
using namespace std;
using ll = long long;
template <typename T>
inline T read(T &x) {
    x = 0; int f = 0; char ch = getchar();
    while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x = f ? -x : x;
}
constexpr int N = 1e5 + 10;
int n;
ll a[N], dp[N][2];
int main() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    // dp[2][0] = a[1] + a[2];
    // dp[2][1] = -a[1] - a[2];
    // for (int i = 3; i <= n; ++i) {
    //     dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
    //     dp[i][1] = max(dp[i - 1][0] - 2 * a[i - 1] - a[i], dp[i - 1][1] + 2 * a[i - 1] - a[i]);
    // }
    // printf("%lld\n", max(dp[n][0], dp[n][1]));
    ll sum = 0, mn = 2e9;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        sum += abs(a[i]);
        mn = min(mn, abs(a[i]));
        if (a[i] <= 0) {
            cnt++;
        }
    }
    if (cnt & 1) {
        printf("%lld\n", sum - mn * 2);
    } else {
        printf("%lld\n", sum);
    }
    return 0;
}
