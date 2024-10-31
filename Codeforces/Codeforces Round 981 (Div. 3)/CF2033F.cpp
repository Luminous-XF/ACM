//
// Created by Luminous on 2024/10/30.
// https://codeforces.com/contest/2033/problem/F
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 1e6 + 10;
const long long MOD = 1e9 + 7;

long long f[MAX_N];

void solve() {
    long long n, k;
    cin >> n >> k;

    f[1] = f[2] = 1;

    int index = 0;
    for (int i = 1; ; i++) {
        f[i] = (i > 2 ? f[i - 2] + f[i - 1] : f[i]) % k;
        if (f[i] % k == 0) {
            index = i;
            break;
        }
    }

    cout << index % MOD * (n % MOD) % MOD << endl;
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