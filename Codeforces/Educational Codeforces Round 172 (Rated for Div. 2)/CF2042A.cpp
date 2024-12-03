///
/// Created by Luminous on 2024/12/2 22:31.
///

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 2e5 + 10;

int a[MAX_N];

void solve() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    sort(a, a + n, std::greater());

    int sum = 0;
    for (int i = 0; i < n && sum + a[i] <= k; i++) {
        sum += a[i];
    }

    std::cout << k - sum << endl;
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