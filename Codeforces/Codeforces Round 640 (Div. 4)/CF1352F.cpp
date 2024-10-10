//
// Created by Luminous on 2024/9/30.
// https://codeforces.com/contest/1352/problem/F
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;

    if (n2 != 0) {
        for (int i = 0; i < n2 + 1; i++) {
            cout << 1;
        }
    }

    if (n0 != 0) {
        for (int i = 0; i < n0 + 1; i++) {
            cout << 0;
        }
    }

    if (n1 > 0) {
        if (n2 == 0 && n0 != 0) {
            for (int i = 0, x = 1; i < n1; i++, x ^= 1) {
                cout << x;
            }
        } else if (n2 != 0 && n0 == 0) {
            for (int i = 0, x = 0; i < n1; i++, x ^= 1) {
                cout << x;
            }
        } else if (n2 != 0 && n0 != 0) {
            for (int i = 0, x = 1; i < n1 - 1; i++, x ^= 1) {
                cout << x;
            }
        } else if (n2 == 0 && n0 == 0) {
            for (int i = 0, x = 1; i < n1 + 1; i++, x ^= 1) {
                cout << x;
            }
        }
    }

    cout << endl;
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
