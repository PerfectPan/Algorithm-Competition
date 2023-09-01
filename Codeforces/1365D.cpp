// 尝试把坏人的四周都围上，再看下好人是否都能跑出去即可，有些边界 case 也要考虑，比如好人不能和坏人贴在一起，没有好人的时候把出口堵上就行了
#include <iostream>
#include <string>
#include <queue>
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
constexpr int N = 50 + 10;
constexpr int dx[4] = {0, 1, 0, -1};
constexpr int dy[4] = {1, 0, -1, 0};
int T, n, m;
char maze[N][N];
int main(){
    for (read(T); T--;) {
        read(n), read(m);
        bool fail = false;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", maze[i]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (maze[i][j] == 'B') {
                    for (int k = 0; k < 4; ++k) {
                        int tx = dx[k] + i;
                        int ty = dy[k] + j;
                        if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                            continue;
                        }
                        if (maze[tx][ty] == 'G') {
                            fail = true;
                        } else if (maze[tx][ty] == '.') {
                            maze[tx][ty] = '#';
                        }
                    }
                } else if (maze[i][j] == 'G') {
                    cnt++;
                }
            }
        }

        if (maze[n - 1][m - 1] == '#') {
            puts(cnt > 0 ? "No" : "Yes");
            continue;
        }

        if (fail) {
            puts("No");
            continue;
        }
        queue<pair<int, int>> Q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        Q.push({n - 1, m - 1});
        vis[n - 1][m - 1] = 1;
    
        while (!Q.empty()) {
            auto& [x, y] = Q.front(); Q.pop();

            for (int i = 0; i < 4; ++i) {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] || maze[tx][ty] == '#') {
                    continue;
                }

                Q.push({tx, ty});
                vis[tx][ty] = 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (maze[i][j] == 'G' && !vis[i][j]) {
                    fail = true;
                }
            }
        }

        puts(fail ? "No" : "Yes");
    }
    return 0;
}
