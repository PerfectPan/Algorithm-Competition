// 枚举 x y，看最后谁是胜利者
// 但其实直接输出这个字符串的最后一位就行，因为胜利者肯定是最后一个赢了的人，感觉有点脑筋急转弯
#include <iostream>
#include <string>
using namespace std;
using ll = long long;
int T, n;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T--; ) {
        cin >> n;
        cin >> s;
        int a = 0, b = 0;
        bool a_win = false, b_win = false;
        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= n; ++y) {
                int a = 0, b = 0, ca = 0, cb = 0;
                for (int i = 0; i < n; ++i) {
                    if (s[i] == 'A') {
                        a++;
                    } else {
                        b++;
                    }
                    if (a == x) {
                        a = b = 0;
                        ca++;
                        if (i == n - 1) {
                            if (ca == y) {
                                a_win = true;
                            }
                        }
                    } else if (b == x) {
                        a = b = 0;
                        cb++;
                        if (i == n - 1) {
                            if (cb == y) {
                                b_win = true;
                            }
                        }
                    }
                }
            }
        }
        if ((a_win && b_win) || (!a_win && !b_win)) {
            cout << "?" << endl;
        } else if (a_win) {
            cout << "A" << endl;
        } else {
            cout << "B" << endl;
        }
    }
    return 0;
}
