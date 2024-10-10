//
// Created by Luminous on 2024/10/8.
// https://codeforces.com/contest/1669/problem/C
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;

    int oddCnt0 = 0, oddCnt1 = 0, evenCnt0 = 0, evenCnt1 = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if ((i & 1) == 1) {
            if ((x & 1) == 1) {
                oddCnt1++;
            } else {
                oddCnt0++;
            }
        } else {
            if ((x & 1) == 1) {
                evenCnt1++;
            } else {
                evenCnt0++;
            }
        }
    }

    if ((oddCnt0 == (n + 1) / 2 || oddCnt1 == (n + 1) / 2) &&
        (evenCnt0 == n / 2 || evenCnt1 == n / 2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
