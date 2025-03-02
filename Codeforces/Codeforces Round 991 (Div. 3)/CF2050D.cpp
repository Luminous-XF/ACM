//
// Created by Luminous on 2024/12/5 22:13
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    std::string s;
    std::cin >> s;

    std::reverse(s.begin(), s.end());

    std::string ans;
    while (!s.empty()) {
        int n = (int) s.size() - 1;
        int j = 0;
        char c = s[n];
        for (int i = 0; i < 9 && n - i >= 0; i++) {
            if (s[n - i] - i > c) {
                j = i;
                c = s[n - i] - i;
            }
        }
        ans.push_back(c);
        s.erase(s.end() - (j + 1));
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