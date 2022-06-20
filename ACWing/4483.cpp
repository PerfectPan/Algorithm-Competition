#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
const int M = 1e6 + 10;
int n, k, a[N], cnt[M];
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        cnt[a[i]] += 1;
    }
    sort(a + 1, a + 1 + n);
    a[n + 1] = 1e9;
    int res = 0;
    for (int i = 1; i <= n;) {
        if (a[i] + k < a[i + 1]) {
            res += cnt[a[i]];
            i += 1;
            continue;
        }
        int l = i + 1, r = n, ans = -1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (a[i] + k >= a[mid]) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        if (~ans) {
            i = ans;
        }
        
    }
    printf("%d\n", res);
    return 0;
}

