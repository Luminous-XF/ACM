//
// Created by Luminous on 2024/11/12 13:22.
// https://codeforces.com/contest/977/problem/A
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;

    while (k-- > 0) {
        if (n % 10 == 0) {
            n /= 10;
        } else {
            n--;
        }
    }

    cout << n << endl;
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