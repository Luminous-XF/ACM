//
// Created by Luminous on 2024/12/5 22:27
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 2e3 + 10;

int dp[MAX_N][MAX_N];

void solve() {
    std::string a, b, c;
    std::cin >> a >> b >> c;

    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            dp[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < c.size(); j++) {
            if (i + b.size() < j) break;
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    int T = 1;
    //std::cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}