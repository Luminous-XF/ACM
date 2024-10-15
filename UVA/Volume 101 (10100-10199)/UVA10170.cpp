//
// Created by Luminous on 2024/10/15.
// https://onlinejudge.org/external/101/10170.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

bool check(long long start, long long end, long long D) {
    return (start + end) * (end - start + 1) / 2 >= D;
}

void solve() {
    long long S, D;
    while (cin >> S >> D) {
        if (S >= D) {
            cout << S << endl;
            continue;
        }

        long long left = S, right = 44721360LL;
        while (left < right) {
            long long mid = left + right >> 1;
            if (check(S, mid, D)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << right << endl;
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