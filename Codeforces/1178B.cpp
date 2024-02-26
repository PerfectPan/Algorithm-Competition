// 维护前后缀 w 的个数，枚举中心点 o 统计答案
// 时间复杂度 O(n)
#include <cstdio>
#include <algorithm>
#include <cstring>
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
constexpr int N = 1e6 + 10;
int pre[N], suff[N];
char s[N];
int main(){
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int cur = 0;
    for (int i = 1; i <= len; ++i) {
        if (s[i] == 'o') {
            pre[i] = pre[i - 1];
            cur = 0;
        } else {
            if (cur > 0) {
                pre[i] = pre[i - 1] + 1;
            } else {
                pre[i] = pre[i - 1];
            }
            cur++;
        }
    }
    cur = 0;
    for (int i = len; i >= 1; --i) {
        if (s[i] == 'o') {
            suff[i] = suff[i + 1];
            cur = 0;
        } else {
            if (cur > 0) {
                suff[i] = suff[i + 1] + 1;
            } else {
                suff[i] = suff[i + 1];
            }
            cur++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= len; ++i) {
        if (s[i] == 'o') {
            ans += 1ll * pre[i - 1] * suff[i + 1];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
