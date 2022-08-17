#include <map>
#include <cstdio>
#include <vector>
using namespace std;
int n, x, sum;
long long ans;
map<int, int> hs[2];
int main() {
    scanf("%d", &n);
    hs[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        sum ^= x;
        ans += hs[i&1][sum];
        hs[i&1][sum] += 1;
    }
    printf("%lld\n", ans);
    return 0;    
}
