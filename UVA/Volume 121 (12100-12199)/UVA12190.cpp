//
// Created by Luminous on 2024/10/19.
// https://onlinejudge.org/external/121/12190.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

long long getCost(long long v) {
    long long res = 0;
    if (v > 0) {
        res += 2 * min(v, 100LL);
        v -= 100LL;
    }
    if (v > 0) {
        res += 3 * min(v, 9900LL);
        v -= 9900LL;
    }
    if (v > 0) {
        res += 5 * min(v, 990000LL);
        v -= 990000LL;
    }
    if (v > 0) {
        res += 7 * v;
    }

    return res;
}

bool solve() {
    long long A, B;
    cin >> A >> B;

    if (A == 0 && B == 0) {
        return false;
    }

    long long totalLeft = 0, totalRight = 1e9;
    while (totalLeft < totalRight) {
        long long mid = totalLeft + totalRight >> 1;
        if (getCost(mid) >= A) {
            totalRight = mid;
        } else {
            totalLeft = mid + 1;
        }
    }

    long long total = totalRight;

    long long left = 0, right = total;
    while (left < right) {
        long long mid = left + right >> 1;
        if (getCost(total - mid) - getCost(mid) <= B) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    long long ans = getCost(right);
    cout << ans << endl;

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