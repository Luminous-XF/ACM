//
// Created by Luminous on 2024/10/8.
// https://codeforces.com/contest/1669/problem/A
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int score;
    cin >> score;

    if (score < 1400) {
        cout << "Division 4" << endl;
    } else if (score < 1600) {
        cout << "Division 3" << endl;
    } else if (score < 1900) {
        cout << "Division 2" << endl;
    } else {
        cout << "Division 1" << endl;
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
