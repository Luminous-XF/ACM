///
/// Created by Luminous on 2024/12/2 22:31.
///

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 1e3 + 10;

struct customHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int a[MAX_N];

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::unordered_map<int, int, customHash> book;
    for (int i = 0; i < n; i++) {
        book[a[i]]++;
    }

    int cnt = 0;
    for (auto& [key, value] : book) {
        if (value == 1) cnt++;
    }

    int ans = (cnt + 1) / 2 * 2 + (int) book.size() - cnt;
    
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