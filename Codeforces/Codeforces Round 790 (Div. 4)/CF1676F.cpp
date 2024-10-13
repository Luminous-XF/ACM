//
// Created by Luminous on 2024/10/12.
// https://codeforces.com/contest/1676/problem/F
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> book;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        book[x]++;
    }

    vector<pair<int, int>> v(book.begin(), book.end());
    int L = 0, R = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second < k) continue;

        int j = i;
        while (j + 1 < v.size() && v[j + 1].second >= k && v[j + 1].first == v[j].first + 1) j++;

        if (j - i + 1 > R - L + 1) {
            L = v[i].first;
            R = v[j].first;
        }

        i = j;
    }

    if (L == 0 && R == -1) {
        cout << -1 << endl;
    } else {
        cout << L << " " << R << endl;
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