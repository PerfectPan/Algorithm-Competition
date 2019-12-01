#include <bits/stdc++.h>
using namespace std;
string S[11];
int num[11];
int main() {
    int T, n;
    for(scanf("%d", &T); T -- ;) {
        scanf("%d", &n);
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; ++ i) {
            cin >> S[i];
            ++num[S[i][0] - '0'];
        }
        int cnt = 0;
        for(int i = 0; i < n; ++ i) {
            for(int j = i + 1; j < n; ++ j) {
                if(S[i] == S[j]) {
                    for(int k = 0; k <= 9; ++ k) {
                        if(!num[k]) {
                            S[j][0] = k + '0';
                            num[k] = 1;
                            ++ cnt;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n", cnt);
        for(int i = 0; i < n; ++ i) {
            cout << S[i] << endl;
        }
    }
}