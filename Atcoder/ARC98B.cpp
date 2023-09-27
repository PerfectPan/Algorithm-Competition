// 异或是不进位加法，所以数组和等于数组异或和等价于数组中任意两个元素按位与位 0
// 假设一个左端点 l_x 最远延伸的下标为 r_x，那么 l_x 为起点满足条件的子数组个数即为 r_x - l_x + 1
// 那么对于左端点 l_1 < l_2，一定有 r_1 <= r_2，保持单调性
// 因此滑窗双指针统计即可，时间复杂度 O(n)
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, a[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    
    int l = 1, r = 1, sum = 0;
    ll ans = 0;
    while (l <= n) {
        for (; r <= n && ((sum & a[r]) == 0); sum ^= a[r++]);
        ans += r - l;
        sum ^= a[l++];
    }

    printf("%lld\n", ans);
    return 0;
}
