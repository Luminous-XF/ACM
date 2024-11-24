//
// Created by Luminous on 2024/11/5.
// https://codeforces.com/contest/2036/problem/F
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

long long preXor(long long x) {
    if (x <= 0) return 0;
    if (x % 2 == 1) return (x + 1) / 2 % 2;
    return preXor(x - 1) ^ x;
}

long long preXor(long long x, long long k, long long i) {
    long long y = x >> i << i | k;
    long long cnt = (y <= x ? x >> i : (x >> i) - 1);
    long long res = preXor(cnt) << i;
    if (cnt % 2 == 0) res |= k;
    return res;
}

void solve() {
    long long l, r, i, k;
    cin >> l >> r >> i >> k;

    if (i == 0) {
        cout << 0 << endl;
        return;
    }

    long long ans = preXor(r) ^ preXor(l - 1) ^ preXor(r, k, i) ^ preXor(l - 1, k, i);
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