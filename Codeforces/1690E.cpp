// 每个数对 k 作向下的除法一定是会在答案里的，然后考虑余数的部分，我们必须选尽可能多的数对让 k <= a_i + a_j，才能得分
// 把余数部分排序后双向双指针
// 如果 a_i + a_j < k，说明 a_i 加上任何小于 a_j 的数都是小于 k 的，所以 a_i 不能和其余数加在一起得分了，右移 i
// 否则可以得一分，i++ j--，假设 a_i 不和 a_j 匹配，那么 a_i 很可能跟后面的数无法匹配，答案不会更优
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int T, n, k, a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T--; ) {
        cin >> n >> k;
        ll sum = 0;
        vector<int> ret;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i] / k;
            int mo = a[i] % k;
            if (mo) {
                ret.push_back(mo);
            }
        }
        sort(ret.begin(), ret.end());
        for (int i = 0, j = (int)ret.size() - 1; i < j; ) {
            if (ret[i] + ret[j] >= k) {
                i++;
                j--;
                sum++;
            } else {
                i++;
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
