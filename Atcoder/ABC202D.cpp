// 从前往后按位考虑，假设当前位填 'a'，可以算出来一共有多少字符串（组合数）
// 假设这个数量大于等于 K，那么当前填 'a' 即可，否则说明以 'a' 为首选出来的字符串最大也不会到第 K 个
// 则当前位要填 'b'，然后 K 减去这个数量，继续考虑下一位，以此类推
// 时间复杂度 O((a + b) ^ 2)
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
int a, b;
ll k;
ll comb[65][65];
int main() {
    cin >> a >> b >> k;
    for (int i = 0; i <= a + b; ++i) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
    string ans = "";
    int total = a + b;
    for (int i = 1; i <= total; ++i) {
        if (k <= comb[a + b - 1][b]) {
            ans.push_back('a');
            a--;
        } else {
            k -= comb[a + b - 1][b];
            ans.push_back('b');
            b--;
        }
    }

    cout << ans << endl;
    return 0;
}
