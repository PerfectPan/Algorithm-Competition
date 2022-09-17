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
int T, x, y, a, b;
int main() {
    for (read(T); T--;) {
        read(x), read(y), read(a), read(b);
        int diff = a + b;
        if (abs(x - y) % diff == 0) {
            printf("%d\n", abs(x - y) / diff);
        } else {
            puts("-1");
        }
    }
    return 0;
}
