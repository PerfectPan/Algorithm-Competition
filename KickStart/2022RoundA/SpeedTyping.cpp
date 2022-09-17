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
const int N = 1e5 + 10;
int T, Case;
char a[N], b[N];
int main() {
    for (read(T), Case = 1; Case <= T; ++Case) {
        scanf("%s%s", a, b);
        int lena = strlen(a);
        int lenb = strlen(b);
        int i, j;
        for (i = 0, j = 0; i < lena && j < lenb; ++j) {
            if (a[i] == b[j]) {
                i++;
            }
        }
        printf("Case #%d: ", Case);
        if (i == lena) {
            printf("%d\n", lenb - lena);
        } else {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}
