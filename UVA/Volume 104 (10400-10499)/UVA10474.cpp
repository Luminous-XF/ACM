//
// Created by Luminous on 2024/10/19.
// https://onlinejudge.org/external/104/10474.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

int a[MAX_N];

int find(int x, int left, int right) {
    while (left < right) {
        int mid = left + right >> 1;
        if (a[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return a[right] == x ? right : -1;
}

bool solve(int testCase) {
    int n, q;
    cin >> n >> q;

    if (n == 0 && q == 0) return false;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    cout << "CASE# " << testCase  << ":" << endl;
    while (q-- > 0) {
        int x;
        cin >> x;

        int index = find(x, 0, n - 1);
        if (index == -1) {
            cout << x << " not found" << endl;
        } else {
            cout << x << " found at " << (index + 1) << endl;
        }
    }

    return true;
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    //cin >> T;
    for (int i = 1;; i++) {
        if (!solve(i)) {
            break;
        }
    }

    return 0;
}