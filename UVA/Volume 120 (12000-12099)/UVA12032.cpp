//
// Created by Luminous on 2024/10/18.
// https://onlinejudge.org/external/120/12032.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 1e5 + 10;

int a[MAX_N];

bool check(int n, int k) {
    int pre = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] - pre > k) return false;
        if (a[i] - pre == k) {
            k--;
        }
        pre = a[i];
    }

    return true;
}

void solve(int testCase) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long left = 0, right = *max_element(a, a + n);
    while (left < right) {
        int mid = left + right >> 1;
        if (check(n, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << "Case " << testCase << ": ";
    cout << right << endl;
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }

    return 0;
}