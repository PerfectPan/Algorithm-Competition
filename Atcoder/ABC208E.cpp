// 考虑到最后所有数的乘积都可以表示成 2^a * 3^b * 5^c * 7^d <= k
// 可以知道状态数其实就 (log k)^4 而不是 k 个，所以直接数位 DP 即可解决
// 定义 f[i][j] 表示从高到低考虑第 i 位，乘积为 j 的合法方案数，f[i] 用哈希表来存储即可
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
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
const int N = 20;
int digit[N];
ll n, k;
unordered_map<ll, ll> f[N];
ll dfs(int pos, ll mul, bool limit, bool isLeadZero) {
    if (pos < 0) {
        return mul <= k;
    }
    if (!limit and !isLeadZero and f[pos].count(mul)) {
        return f[pos][mul];
    }
    int up = limit ? digit[pos] : 9;
    ll res = 0;
    for (int i = 0; i <= up; ++i) {
        if (isLeadZero) {
            if (i == 0) {
                res += dfs(pos - 1, 0, limit and i == up, true);
            } else {
                res += dfs(pos - 1, i, limit and i == up, false);
            }
        } else {
            res += dfs(pos - 1, mul * i, limit and i == up, false);
        }
    }
    if (!limit and !isLeadZero) {
        f[pos][mul] = res;
    }
    return res;
}
ll get(ll n) {
    int cnt = 0;
    while (n > 0) {
        digit[cnt++] = n % 10;
        n /= 10;
    }
    return dfs(cnt - 1, 0, true, true) - 1;
}
int main() {
    cin >> n >> k;
    cout << get(n) << endl;
    return 0;
}
