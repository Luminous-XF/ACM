//
// Created by Luminous on 2024/10/2.
// https://codeforces.com/contest/1352/problem/G
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10x;

void solve() {
    int n;
    cin >> n;

    if (n <= 3) {
        cout << -1 << endl;
        return;
    }

    if (n == 4) {
        cout << "3 1 4 2" << endl;
        return;
    }

    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }

    if (n % 2 == 1) {
        n--;
        cout << n - 2 << " " << n << " ";
        for (int i = n - 4; i > 0; i -= 2) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << n - 4 << " " << n << " " << n - 2 << " ";
        for (int i = n - 6; i > 0; i -= 2) {
            cout << i << " ";
        }
        cout << endl;
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
