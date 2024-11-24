//
// Created by Luminous on 2024/11/5.
// https://codeforces.com/contest/2036/problem/D
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"


const int MAX_N = 2e3 + 10;
const string NUM = "1543";

string a[MAX_N];

vector<char> getArray(int x, int y, int n, int m) {
    vector<char> res;
    for (int i = 0; i < m; i++) res.push_back(a[x][y + i]);
    for (int i = 1; i < n; i++) res.push_back(a[x + i][y + m - 1]);
    for (int i = 1; i < m; i++) res.push_back(a[x + n - 1][y + m - 1 - i]);
    for (int i = 1; i < n - 1; i++) res.push_back(a[x + n - 1 - i][y]);
    return res;
}

int find1543(vector<char> &v) {
    int res = 0, n = (int) v.size();
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < 4; j++) {
            if (v[(i + j) % n] != NUM[j]) {
                ok = false;
            }
        }
        if (ok) res++;
    }

    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x = 0, y = 0, ans = 0;
    while (n > 1 && m > 1) {
        vector<char> v = getArray(x, y, n, m);
        ans += find1543(v);
        x++, y++, n -= 2, m -= 2;
    }

    cout << ans << endl;
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;
    while (T-- ) {
        solve();
    }

    return 0;
}