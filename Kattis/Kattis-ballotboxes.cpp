//
// Created by Luminous on 2024/11/1.
// https://open.kattis.com/problems/ballotboxes
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 5e5 + 10;

int a[MAX_N];

bool check(int n, int m, int k) {
    for (int i = 0; i < n; i++) {
        m -= ceil((double) a[i] / k);
    }

    return m >= 0;
}

bool solve() {
    int n, m;
    cin >> n >> m;

    if (n == -1 && m == -1) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0, right = 5e6 + 10;
    while (left < right) {
        int mid = left + right >> 1;
        if (check(n, m, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    int ans = right;
    cout << ans << endl;

    return true;
}

int main() {

    ios::sync_with_stdio(false);

    while (solve());

    return 0;
}