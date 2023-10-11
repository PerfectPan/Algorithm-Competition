// 代价越大，越容易做到
// 二分答案 x，然后滑窗，只要窗口尽可能的大（窗内 0 的个数不超过 x），那么窗口外的 1 的个数就尽可能的小，只要同时满足 <= x 就找了一个符合条件的 x
// 时间复杂度 O(nlogn)
#include <iostream>
#include <string>
using namespace std;
using ll = long long;
int T;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T--; ) {
        cin >> s;
        int one = 0;
        for (int i = 0; i < s.length(); ++i) {
            one += s[i] == '1';
        }

        auto check = [&](int x) -> bool {
            int tz = 0, to = one;
            int i = 0, r = 0;
            while (i < s.length()) {
                for (; r < s.length() && to > x; ++r) {
                    if (s[r] == '0') {
                        tz++;
                    } else {
                        to--;
                    }
                }
                if (tz <= x && to <= x) {
                    return true;
                }
                if (s[i] == '0') {
                    tz--;
                } else {
                    to++;
                }
                i += 1;
            }

            return false;
        };

        int l = 0, r = s.length(), ans = 0;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
