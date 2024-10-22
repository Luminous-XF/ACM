//
// Created by Luminous on 2024/10/22.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 1e6 + 10;

int a[MAX_N];

int quickSort(int l, int r, int k) {
    if (l >= r) return a[l];

    int x = a[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }

    return k <= j ? quickSort(l, j, k) : quickSort(j + 1, r, k);
}

void solve() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = quickSort(0, n - 1, n / 2 + 1);
        cout << ans << endl;
    }
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
//    cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}