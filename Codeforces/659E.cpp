// 题意：需要把一张无向图每条边都变成有向边（定向）。定向后，入度为 0 的点最少有多少个？
// 如果一个连通块没有环，即一棵树，随便选一个点出发 DFS，按照递归的顺序定向，那么除了起点以外，其余点的入度都大于 0。
// 如果一个连通块有环，那么从环上的点出发 DFS，按照递归的顺序定向，所有的点的入度都可以大于 0。
// 也可以用贪心的思想，假设当前每个点的度数为 x，用堆维护，每次弹出最小度数的点，然后从里面挑一个边指向它，挑的边另一端的点是度数尽可能的大，因为大度数的点可选的指向它的边会多，所以大度数的点放后选会让答案变优
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T& x) {
    x = 0; int f = 0; char ch = getchar();
    while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x = f ? -x : x;
}
constexpr int N = 2e5 + 10;
int n, m, u, v, vis[N];
vector<int> G[N];
bool flag;
void dfs(int u, int f) {
    if (vis[u]) {
        flag = false;
        return;
    }
    vis[u] = 1;
    for (int& v: G[u]) {
        if (v == f) {
            continue;
        }
        dfs(v, u);
    }
}
int main() {
    read(n), read(m);
    for (int i = 1; i <= m; ++i) {
        read(u), read(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        flag = true;
        dfs(i, -1);
        ans += flag;
    }
    printf("%d\n", ans);
    return 0;
}
