//
// Created by Luminous on 2024/11/30 22:34.
// https://codeforces.com/contest/2034/problem/A
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int a, b;
    cin >> a >> b;
    cout << std::lcm(a, b) << endl;
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