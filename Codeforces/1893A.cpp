// 操作 k 轮以后，最后一位一定是上一次被操作的不动点，所以我们可以基于此往前逆推
// 同时这个东西最多不超过 n 次就会开始进入重复的循环
// 所以我们只要判断这个操作是否会有循环节，如果有的话一定有解，否则就看最多操作数是否大于等于 k 就好
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
constexpr int N = 2e5 + 10;
int T, n, k, b[N];
bool vis[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T--; ) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
            vis[i] = 0;
        }
        int idx = n, cnt = 0;
        bool has_loop = true;
        while (!vis[idx]) {
            if (b[idx] > n) {
                has_loop = false;
                break;
            }
            cnt++;
            vis[idx] = true;
            if (b[idx] < idx) {
                idx -= b[idx];
            } else {
                idx = n - (b[idx] - idx);
            }
        }
        if (has_loop) {
            if (cnt > 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            if (k <= cnt) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
