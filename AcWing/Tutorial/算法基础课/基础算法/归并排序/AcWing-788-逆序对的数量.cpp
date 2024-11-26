//
// Created by Luminous on 2024/11/26 17:59.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 1e5 + 10;

int a[MAX_N];
int temp[MAX_N];

void mergeSort(int l, int r, long long &ans) {
    if (l >= r) return;

    int mid = l + r >> 1;
    mergeSort(l, mid, ans);
    mergeSort(mid + 1, r, ans);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            ans += mid - i + 1;
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (i = l, j = 0; i <= r; i++, j++) {
        a[i] = temp[j];
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    mergeSort(0, n - 1, ans);

    cout << ans << endl;
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