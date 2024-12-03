//
// Created by Luminous on 2024/12/1 1:31.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 2e5 + 10;

int a[MAX_N];

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::priority_queue<int, std::vector<int>, std::greater<>> q1;
    std::priority_queue<int, std::vector<int>, std::greater<>> q2;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) q1.push(i);
        if (a[i] == 2) q2.push(i);
    }

    int cnt = (int) std::count(a, a + n, 2);

    std::vector<std::array<int, 2>> ans;
    for (int i = n - 1; i >= n - cnt; i--) {
        if (a[i] == 2) continue;

        if (a[i] == 0) {
            int j = q1.top();
            q1.pop();
            std::swap(a[i], a[j]);
            ans.push_back({i, j});
            i += 1;
        } else {
            int j = q2.top();
            q2.pop();
            std::swap(a[i], a[j]);
            q1.push(j);
            ans.push_back({i, j});
        }
    }

    for (int i = 0, j = n - cnt - 1; i < j; i++, j--) {
        while (i < n && a[i] == 0) i++;
        while (j > 0 && a[j] == 1) j--;
        if (i < j) {
            std::swap(a[i], a[j]);
            ans.push_back({i, j});
        }
    }

    std::cout << ans.size() << endl;
    for (auto& [i, j] : ans) {
        std::cout << (i + 1) << " " << (j + 1) << endl;
    }
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