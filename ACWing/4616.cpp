#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N = 2e5 + 10;
int n, a, b, k;
char s[N];
bool check(int x, bool print) {
    int cnt = 0;
    int tx = x;
    int ta = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '1') {
            cnt = 0;
        } else {
            cnt++;
            if (tx > 0) {
                if (cnt == b) {
                    tx -= 1;
                    cnt = 0;
                    if (print) {
                        printf("%d%c", i, tx == 0 ? '\n' : ' ');
                    }
                }
            } else if (cnt ==b) {
                ta++;
                cnt = 0;
            }
        }
    }
    return ta < a;
}
int main() {
    read(n), read(a), read(b), read(k);
    scanf("%s", s + 1);
    int L = 1, R = n - k, ans = n - k;
    while (L <= R) {
        int mid = L + ((R - L) >> 1);
        if (check(mid, false)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    printf("%d\n", ans);
    check(ans, true);
    return 0;
}
