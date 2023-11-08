#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
constexpr int N = 100 + 10;
int T, n, a[N], b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T--; ) {
        cin >> n;
        vector<vector<int>> q(101, vector<int>{});
        int c = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            q[a[i]].push_back(i);
            if (q[a[i]].size() == 2) {
                c++;
            }
        }
        if (c <= 1) {
            cout << -1 << endl;
        } else {
            int flag = 0;
            for (int i = 1; i <= 100; ++i) if (q[i].size() > 0) {
                if (q[i].size() == 1) {
                    b[q[i][0]] = 1;
                } else {
                    if (flag == 0) {
                        b[q[i][0]] = 1;
                        for (int j = 1; j < q[i].size(); ++j) {
                            b[q[i][j]] = 2;
                        }
                    } else {
                        b[q[i][0]] = 1;
                        for (int j = 1; j < q[i].size(); ++j) {
                            b[q[i][j]] = 3;
                        }
                    }
                    flag ^= 1;
                }
            }
            for (int i = 1; i <= n; ++i) {
                cout << b[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
