//
// Created by Luminous on 2024/11/5.
// https://codeforces.com/contest/2036/problem/E
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

int findLess(vector<long long> &arr, int v, int n) {
    int left = 1, right = n;
    while (left < right) {
        int mid = left + right + 1 >> 1;
        if (arr[mid] < v) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    return arr[left] < v ? left : 0;
}

int findGreater(vector<long long> &arr, int v, int n) {
    int left = 1, right = n;
    while (left < right) {
        int mid = left + right >> 1;
        if (arr[mid] > v) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return arr[right] > v ? right : n + 1;
}

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<long long>> arr(k + 1, vector<long long>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> arr[j][i];
        }
    }

    vector<vector<long long>> pre(k + 1, vector<long long>(n + 1));
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j] = pre[i][j - 1] | arr[i][j];
        }
    }

    while (q-- > 0) {
        int m;
        cin >> m;

        int L = 1, R = n;
        while (m-- > 0) {
            int i, v;
            string op;
            cin >> i >> op >> v;
            if (op == "<") R = min(R, findLess(pre[i], v, n));
            if (op == ">") L = max(L, findGreater(pre[i], v, n));
        }

        cout << (L <= R ? L : -1) << endl;
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