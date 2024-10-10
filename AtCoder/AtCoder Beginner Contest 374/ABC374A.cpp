//
// Created by Luminous on 2024/10/9.
// https://atcoder.jp/contests/abc374/tasks/abc374_a
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    string s;
    cin >> s;

    if (s.substr(s.length() - 3, 3) == "san") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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