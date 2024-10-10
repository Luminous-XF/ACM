//
// Created by Luminous on 2024/9/30.
// https://codeforces.com/contest/1352/problem/C
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;

    int x = k % (n - 1);
    cout << k / (n - 1) * n + (x == 0 ? - 1 : x) << endl;
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
