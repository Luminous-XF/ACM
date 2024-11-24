//
// Created by Luminous on 2024/11/24 17:39.
// https://codeforces.com/contest/2036/problem/B
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

struct customHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    unordered_map<int, int, customHash> book;
    for (int i = 0; i < k; i++) {
        int b, c;
        cin >> b >> c;
        book[b] += c;
    }

    vector<int> v;
    for (auto &[key, value] : book) {
        v.push_back(value);
    }

    sort(v.begin(), v.end(), greater<>());

    int ans = 0;
    for (int i = 0; i < min((int) v.size(), n); i++) {
        ans += v[i];
    }

    cout << ans << endl;
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}