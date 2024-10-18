//
// Created by Luminous on 2024/10/18.
//

#pragma GCC optimize(3)

//#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

double a[MAX_N];

bool check(int n, int k, double len) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += floor(a[i] / len);
    }

    return cnt >= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double left = 0, right = *max_element(a, a + n);
    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        if (check(n, k, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    double ans = floor(left * 100) / 100;
    cout << fixed << setprecision(2) << ans << endl;
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