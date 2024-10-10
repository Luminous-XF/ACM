//
// Created by Luminous on 2024/9/30.
// https://codeforces.com/contest/1352/problem/A
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;

    vector<int> ans;
    int v = 1;
    while (n > 0) {
        int x = n % 10 * v;
        if (x != 0) {
            ans.push_back(x);
        }
        v *= 10;
        n /= 10;
    }

    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
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
