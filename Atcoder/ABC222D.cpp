// dp[i][j] 表示从低到高填第 i 位数为 j 的方案数
// dp[i][j] = dp[i - 1][0] + dp[i - 1][1] + ... + dp[i - 1][j]（可以用前缀和优化成 O(1)）
// 最后答案为 dp[n][b_n]
// 注意到只和 i - 1 的状态有关，因此可以滚动数组优化成 dp[2][n]
// 时间复杂度 O(n^2)
// 也有一种思路是定义 dp[i][j] 为从低到高填第 i 位数 <= j 的方案数
// 考虑第 i 个数是否要填 j，如果不填从 dp[i][j - 1] 转移过来（从低到高第 i 位数 <= j - 1 的方案数）
// 如果填从 dp[i - 1][min(j, b_{i - 1})] 转移过来
// 初始值 dp[0][j] = j - a_0 + 1
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
constexpr int N = 3000 + 10;
constexpr int P = 998244353;
int n, a[N], b[N], dp[2][N];
void up(int& a, int b) { a += b; if (a >= P) a -= P; }
int main() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
    }
    int cur = 0;
    for (int i = 0; i <= N - 10; ++i) {
        dp[cur][i] = a[1] <= i and i <= b[1];
        if (i > 0) {
            up(dp[cur][i], dp[cur][i - 1]);
        }
    }

    for (int i = 2; i <= n; ++i) {
        cur ^= 1;
        for (int j = 0; j <= N - 10; ++j) {
            if (a[i] <= j and j <= b[i]) {
                dp[cur][j] = dp[cur ^ 1][j];
            } else {
                dp[cur][j] = 0;
            }   
            if (j > 0) {
                up(dp[cur][j], dp[cur][j - 1]);
            }
        }
    }
    printf("%d\n", dp[cur][b[n]]);
    return 0;
}
