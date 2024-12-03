///
/// Created by Luminous on 2024/12/2 22:31.
///

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    int suffix = 0;
    std::vector<int> v;
    for (int i = n - 1; i >= 1; i--) {
        if (s[i] == '1') suffix++;
        if (s[i] == '0') suffix--;
        v.push_back(suffix);
    }

    std::sort(v.begin(), v.end(), std::greater());

    long long sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        if (sum >= k) {
            std::cout << 1 + (i + 1) << endl;
            return;
        }
    }
    std::cout << -1 << endl;
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