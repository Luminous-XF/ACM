//
// Created by Luminous on 2024/10/29.
// https://codeforces.com/contest/2033/problem/A
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    cout << ((n & 1) == 1 ? "Kosuke" : "Sakurako") << endl;
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