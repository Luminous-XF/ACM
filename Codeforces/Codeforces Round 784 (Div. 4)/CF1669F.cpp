//
// Created by Luminous on 2024/10/10.
// https://codeforces.com/contest/1669/problem/F
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

int a[MAX_N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0, leftSum = 0, rightSum = 0;
    for (int i = -1, j = n; i < j;) {
        if (leftSum == rightSum) {
            ans = i + 1 + n - j;
            leftSum += a[++i];
        } else {
            if (j - i == 1) break;
            if (leftSum + a[i + 1] <= rightSum) {
                leftSum += a[++i];
            } else {
                rightSum += a[--j];
            }
        }
    }

    cout << ans << endl;
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