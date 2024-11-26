//
// Created by Luminous on 2024/11/26 18:23.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 1e5 + 10;

int a[MAX_N];

int lowerBound(int l, int r, int x) {
    while (l < r) {
        int mid = l + r >> 1;
        if (a[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return a[r] == x ? r : -1;
}

int upperBound(int l, int r, int x) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (a[mid] <= x) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return a[l] == x ? l : -1;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q-- > 0) {
        int x;
        cin >> x;
        int ansL = lowerBound(0, n -1, x);
        int ansR = upperBound(0, n - 1, x);
        cout << ansL << " " << ansR << endl;
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