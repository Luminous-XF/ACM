//
// Created by Luminous on 2024/12/5 22:13
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long sum1 = 0LL, sum2 = 0LL, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if ((i & 1) == 0) {
            sum1 += a[i];
            cnt1++;
        } else {
            sum2 += a[i];
            cnt2++;
        }
    }

//    std::cerr << sum1 << " " << cnt1 << " " << sum2 << " " << cnt2 << endl;

    if (sum1 % cnt1 != 0 || sum2 % cnt2 != 0) {
        std::cout << "NO" << endl;
        return;
    }
    if (sum1 / cnt1 != sum2 / cnt2) {
        std::cout << "NO" << endl;
        return;
    }
    std::cout << "YES" << endl;
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