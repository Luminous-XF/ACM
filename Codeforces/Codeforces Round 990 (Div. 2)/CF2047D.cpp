//
// Created by Luminous on 2024/12/3 14:08
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 1e5 + 10;


void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int minInx = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < a[minInx]) {
            minInx = i;
        }
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