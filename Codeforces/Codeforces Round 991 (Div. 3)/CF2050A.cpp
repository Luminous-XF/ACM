//
// Created by Luminous on 2024/12/5 22:12
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n, m;
    std::cin >> n >> m;
    bool flag = true;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        if (flag && m >= s.size()) {
            m -= (int) s.size();
            ans++;
        } else {
            flag = false;
        }
    }

    std::cout << ans << endl;
}

int main() {

    std::ios::sync_with_stdio(false);

    int T = 1;
    std::cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}