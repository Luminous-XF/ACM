//
// Created by Luminous on 2024/11/6.
// http://poj.org/problem?id=3104
//

#pragma GCC optimize(3)

#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

#define endl "\n"


const int MAX_N = 1e5 + 10;

int a[MAX_N];

bool check(int n, int k, int mid) {
    long long time = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < mid) continue;
        time += (int) ceil((double) (a[i] - mid) / (k - 1));
        if (time > mid) return false;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    sort(a, a + n);

    if (k == 1) {
        cout << a[n - 1] << endl;
        return;
    }

    int l = 0, r = a[n - 1];
    while (l < r) {
        int mid = l + r >> 1;
        if (check(n, k, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    int ans = r;
    cout << ans << endl;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    //cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}