//
// Created by Luminous on 2024/11/26 17:06.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 1e5 + 10;

int a[MAX_N];

void quickSort(int l, int r) {
    if (l >= r) return;

    int x = a[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }

    quickSort(l, j);
    quickSort(j + 1, r);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quickSort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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