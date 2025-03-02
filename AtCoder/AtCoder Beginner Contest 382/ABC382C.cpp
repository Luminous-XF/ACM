//
// Created by Luminous on 2024/12/4 20:53
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::pair<int, int>> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i].first;
        b[i].second = i;
    }

    std::sort(b.begin(), b.end(), std::greater<>());

    std::vector<int> ans(m, -1);
    for (int i = 0, j = 0; i < n && j < m; i++) {
        while (j < m && b[j].first >= a[i]) {
            ans[b[j].second] = i + 1;
            j++;
        }
    }

    for (auto item: ans) {
        std::cout << item << endl;
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