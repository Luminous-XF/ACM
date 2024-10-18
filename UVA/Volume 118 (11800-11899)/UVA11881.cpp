//
// Created by Luminous on 2024/10/19.
// https://onlinejudge.org/external/118/11881.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 10 + 10;

int a[MAX_N];

bool check(int T, double IRR) {
    double res = 0, temp = IRR + 1  ;
    for (int i = 1; i <= T; i++) {
        res += a[i] / temp;
        temp = temp * (IRR + 1);
    }

    return res <= -a[0];
}

bool solve() {
    int T;
    cin >> T;

    if (T == 0) return false;

    for (int i = 0; i <= T; i++) {
        cin >> a[i];
    }

    double left = -1, right = INT_MAX;
    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        if (check(T, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    double ans = right;
    cout << fixed << setprecision(2) << ans << endl;

    return true;
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    //cin >> T;
    while (true) {
        if (!solve()) {
            break;
        }
    }

    return 0;
}