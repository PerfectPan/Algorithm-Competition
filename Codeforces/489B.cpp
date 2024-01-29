#include<cstdio>
#include<algorithm>
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
constexpr int N = 100 + 10;
int n, m, a[N], b[N];
int main(){
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]);
    read(m);
    for (int i = 1; i <= m; ++i) read(b[i]);
 
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    int ans = 0;
    for (int i = 1, j = 1; i <= n && j <= m; ) {
        if (abs(a[i] - b[j]) <= 1) {
            ++i, ++j;
            ans++;
        } else if (a[i] > b[j]) {
            ++j;
        } else {
            ++i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
