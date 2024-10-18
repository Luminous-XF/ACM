//
// Created by Luminous on 2024/10/18.
// http://poj.org/problem?id=2456
//

#pragma GCC optimize(3)

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

long long a[MAX_N];

bool check(int n, int c, long long dis) {
    long long before = -dis;
    for (int i = 0; i < n; i++) {
        if (a[i] - before >= dis) {
            before = a[i];
            c--;
        }
    }

    return c <= 0;
}

void solve() {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    long long left = 0, right = a[n - 1];
    while (left < right) {
        long long mid = left + right + 1 >> 1;
        if (check(n, c, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;
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