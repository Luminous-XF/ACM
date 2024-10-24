//
// Created by Luminous on 2024/10/24.
// https://onlinejudge.org/external/5/594.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

int swapBytes(int n) {
    int byte1 = (n >> 24) & 0xFF;
    int byte2 = (n >> 16) & 0xFF;
    int byte3 = (n >> 8) & 0xFF;
    int byte4 = n & 0xFF;

    return ((int) byte4 << 24) | ((int) byte3 << 16) | ((int) byte2 << 8) | ((int) byte1);
}

void solve() {
    int n;
    while (cin >> n) {
        int ans = swapBytes(n);
        cout << n << " converts to " << ans << endl;
    }
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    //cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}