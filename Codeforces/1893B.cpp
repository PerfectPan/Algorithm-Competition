// 官解会简单很多，我的解法是容易观察到针对 a 数组中的一个数 x，如果 b 数组能找到的话直接插到它前面一定不会让答案改变
// 然后剩下来的都是 a 中没有出现过的数，这个时候考虑 a 数组的 LIS，假设有多个位置都是符合 LIS 的最后一个数，那么这个数一定是倒序的，然后我们考虑
// 把 b 插入进去，怎么能不让答案变大，就是跟这个倒序的序列归并合并就好了，这样能够保证 LIS 不增加，因为假设 1 2 3 是一个 LIS，我把大于 3 的都插入在 3 前面 2 后面，LIS 的最后一位
// 只会从 3 转移到这个比 3 大的数
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
using ll = long long;
constexpr int N = 2e5 + 10;
int T, n, m, a[N], b[N];
unordered_set<int> S;
unordered_map<int, int> mp;
int s[N], f[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T--; ) {
        cin >> n >> m;
        S.clear();
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            S.insert(a[i]);
            s[i] = 0;
        }
        vector<int> dp(n + 1), f;
        for (int i = 1; i <= n; i++) {
            auto it = lower_bound(f.begin(), f.end(), a[i]);
            dp[i] = it - f.begin() + 1;
            if (it == f.end()) {
                f.push_back(a[i]);
            } else {
                *it = a[i];
            }
        }
            
        int ans = f.size();
        vector<int> vec;
        for (int i = 1; i <= m; ++i) {
            cin >> b[i];
            if (S.count(b[i])) {
                mp[b[i]] += 1;
            } else {
                vec.push_back(b[i]);
            }
        }
        sort(vec.begin(), vec.end(), greater<int>());
        int k = 0;
        for (int i = 1; i <= n; ++i) {
            if (dp[i] == ans) {
                while (k < vec.size()) {
                    if (vec[k] > a[i]) {
                        cout << vec[k] << " ";
                        k++;
                    } else {
                        break;
                    }
                }
            }
            cout << a[i] << " ";
            int cnt = mp[a[i]];
            for (int j = 1; j <= cnt; ++j) {
                cout << a[i] << " ";
            }
            mp[a[i]] = 0;
        }
        while (k < vec.size()) {
            cout << vec[k] << " ";
            k++;
        }
        cout << endl;
    }
    return 0;
}
