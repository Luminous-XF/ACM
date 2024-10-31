//
// Created by Luminous on 2024/10/29.
// https://codeforces.com/contest/2033/problem/D
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

int a[MAX_N];
long long pre[MAX_N];
long long dp[MAX_N];

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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    dp[0] = 0;

    long long ans = 0;
    unordered_map<long long, int, customHash> book;
    book[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (book.find(pre[i]) != book.end()) {
            dp[i] = max(dp[i - 1], dp[book[pre[i]]] + 1);
        } else {
            dp[i] = dp[i - 1];
        }
        book[pre[i]] = i;
    }

    cout << dp[n] << endl;
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