//
// Created by Luminous on 2024/10/2.
// https://codeforces.com/contest/1352/problem/E
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

using namespace std;
#define endl "\n"


const int MAX_N = 8e3 + 10;

int a[MAX_N];
bool book[MAX_N];

void init(int n) {
    fill(book, book + n + 10, false);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    init(n);
    for (int i = 0; i < n; i++) {
        int sum = a[i];
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            if (sum <= n) {
                book[sum] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (book[a[i]]) {
            ans++;
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
