    //
    // Created by Luminous on 2024/11/30 22:43.
    // https://codeforces.com/contest/2034/problem/B
    //

    #pragma GCC optimize(3)

    #include <bits/stdc++.h>
    using namespace std;

    #define endl "\n"


    const int MAX_N = 2e5 + 10;

    void solve() {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;

        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt = 0;
                continue;
            }

            cnt++;
            if (cnt == m) {
                ans++;
                i = i + k - 1;
                cnt = 0;
            }
        }

        cout << ans << endl;
    }

    int main() {

        ios::sync_with_stdio(false);

        int T = 1;
        cin >> T;
        while (T-- > 0) {
            solve();
        }

        return 0;
    }