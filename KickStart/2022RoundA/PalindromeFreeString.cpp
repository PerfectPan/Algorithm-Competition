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
const int N = 5e4 + 10;
bool t5[1 << 5], t6[1 << 6];
int T, Case, n, dp[N][1 << 6];
char s[N];
void pre() {
    // 10001 01010 00100
    int w5[] = {17, 10, 4};
    // 100001 010010 001100
    int w6[] = {33, 18, 12};
    for (int i = 0; i < (1 << 3); ++i) {
        int u5 = 0, u6 = 0;
        for (int j = 0; j < 3; ++j) {
            if ((i >> j) & 1) {
                u5 += w5[j];
                u6 += w6[j];
            }
        }
        t5[u5] = 1;
        t6[u6] = 1;
    }
}
int main() {
    pre();
    for (read(T), Case = 1; Case <= T; ++Case) {
        read(n);
        scanf("%s", s);
        printf("Case #%d: ", Case);
        if (n < 5) {
            puts("POSSIBLE");
            continue;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int sixMask = (1 << 6) - 1;
        int fiveMask = (1 << 5) - 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (1 << 6); ++j) if (dp[i][j]) {
                if (s[i] == '0' or s[i] == '?') {
                    int val = (j << 1) & sixMask;
                    dp[i + 1][val] = !((i >= 4 and t5[val & fiveMask]) or (i >= 5 and t6[val]));
                }
                if (s[i] == '1' or s[i] == '?') {
                    int val = ((j << 1) | 1) & sixMask;
                    dp[i + 1][val] = !((i >= 4 and t5[val & fiveMask]) or (i >= 5 and t6[val]));
                }
            }
        }
        bool f = false;
        for (int i = 0; i < (1 << 6); ++i) {
            if (dp[n][i]) {
                puts("POSSIBLE");
                f = true;
                break;
            }
        }
        if (!f) {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}
