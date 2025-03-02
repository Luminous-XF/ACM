//
// Created by Luminous on 2024/12/4 19:56
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n, d;
    std::cin >> n >> d;
    std::string s;
    std::cin >> s;

    int cnt = (int) std::count(s.begin(), s.end(), '@');
    int ans = n - (cnt - d);
    std::cout << ans << endl;
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