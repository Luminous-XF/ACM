//
// Created by Luminous on 2024/9/30.
// https://codeforces.com/contest/1352/problem/B
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k > n) {
        cout << "NO" << endl;
        return;
    }

    if (n % 2 == 1) {
        if ((n - k) % 2 == 0) {
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; i++) {
                cout << 1 << " ";
            }
            cout << n - (k - 1) << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (n >= 2 * k) {
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; i++) {
                cout << 2 << " ";
            }
            cout << n - 2 * (k - 1) << endl;
        } else {
            if (k % 2 == 0) {
                cout << "YES" << endl;
                for (int i = 0; i < k - 1; i++) {
                    cout << 1 << " ";
                }
                cout << n - (k - 1) << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
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
