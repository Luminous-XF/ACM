//
// Created by Luminous on 2024/10/13.
// https://codeforces.com/contest/1676/problem/H1
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

int a[MAX_N];

struct BIT {
    long long *C;
    int N;

    BIT(int n) {
        N = n;
        C = (long long *) malloc(sizeof(long long) * N);
        memset(C, 0, sizeof(long long) * N);
    }

    void add(int index, int value) {
        while (index < N) {
            C[index] += value;
            index += lowbit(index);
        }
    }

    int query(int index) {
        int res = 0;
        while (index > 0) {
            res += C[index];
            index -= lowbit(index);
        }
        return res;
    }

    int lowbit(int x) {
        return x & (-x);
    }
};

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    BIT bit(n + 1);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += i - bit.query(a[i] - 1);
        bit.add(a[i], 1);
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