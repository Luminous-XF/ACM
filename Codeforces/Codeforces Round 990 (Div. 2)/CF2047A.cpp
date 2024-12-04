//
// Created by Luminous on 2024/12/3 14:07
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 1e2 + 10;

int a[MAX_N];
int b[MAX_N];

void init() {
    b[1] = 1;
    for (int i = 2, j = 1; i < MAX_N; i++) {
        b[i] = j * 4 + 4;
        j += 2;
    }
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    int sum = 0, ans = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        sum += a[i];
        while (sum >= b[j]) {
            if (sum == b[j]) ans++;
            sum -= b[j];
            j++;
        }
    }

    std::cout << ans << endl;
}

int main() {

    std::ios::sync_with_stdio(false);

    init();

    int T = 1;
    std::cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}