// 题意：输入给定 nL 个字母，构造 n 个长度 L 的字符串，按字典序排列，最小化第 k 个字符串
// 一个观察：一列列的填答案会更优
// 另一个观察：当一列填的字母不一样的时候，字典序小的字符串，可以留到最后填
// 一列列填，收窄上界（从哪一行开始填），最后未填的按字典序大小一个个填即可
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
constexpr int N = 1e3 + 10;
int n, L, k, cnt[26];
char total[N * N], str[N][N];
int len[N];
int main() {
    read(n), read(L), read(k);
    scanf("%s", total + 1);
    for (int i = 1; i <= n * L; ++i) {
        cnt[total[i] - 'a']++;
    }

    int i0 = 1, idx = 0;
    for (int j = 0; j < L; ++j) {
        for (int i = i0; i <= k; ++i) {
            while (cnt[idx] == 0) {
                idx++;
            }
            str[i][len[i]++] = 'a' + idx;
            cnt[idx]--;
            if (i > i0 && str[i][len[i] - 1] != str[i - 1][len[i - 1] -1]) {
                i0 = i;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        while (len[i] < L) {
            while (cnt[idx] == 0) {
                idx++;
            }
            str[i][len[i]++] = 'a' + idx;
            cnt[idx]--;
        }
        str[i][len[i]] = '\0';
    }

    for (int i = 1; i <= n; ++i) {
        puts(str[i]);
    }
    return 0;
}
