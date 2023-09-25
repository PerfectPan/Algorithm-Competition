// 先给每个节点打标记，然后 DFS 的时候累加标记值即可，类似线段树的 lazy push down
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
vector<int> G[N];
int inc[N], ans[N];
int n, q, p, a, b;
void dfs(int u, int f, int sum) {
    sum += inc[u];
    ans[u] = sum;
    for (int v: G[u]) {
        if (v == f) {
            continue;
        }
        dfs(v, u, sum);
    }
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= q; ++i) {
        scanf("%d %d", &a, &b);
        inc[a] += b;
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}
