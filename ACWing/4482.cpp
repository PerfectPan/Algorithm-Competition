#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100 + 10;
int n, a[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    int res = 0, cnt = 0, num = -1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != num) {
            res = max(res, cnt);
            cnt = 1;
            num = a[i];
        } else {
            cnt += 1;
        }
    }
    printf("%d\n", max(res, cnt));
    return 0;
}

