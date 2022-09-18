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
int T, Case;
char s[N];
int main() {
    for (read(T), Case = 1; Case <= T; ++Case) {
        scanf("%s", s);
        int len = strlen(s);
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += s[i] - '0';
        }
        int ans = 9 - (sum % 9);
        if (ans == 9) {
            ans = 0;
        }
        int pos = len;
        for (int i = 0; i < len; ++i) {
            if (i == 0 && ans == 0) {
                continue;
            }
            if (ans < s[i] - '0') {
                pos = i;
                break;
            }
        }
        
        printf("Case #%d: ", Case);
        for (int i = 0; i < pos; ++i) {
            putchar(s[i]);
        }
        putchar(ans + '0');
        for (int i = pos; i < len; ++i) {
            putchar(s[i]);
        }
        puts("");
    }
    return 0;
}
