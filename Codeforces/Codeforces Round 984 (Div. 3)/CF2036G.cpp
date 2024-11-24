//
// Created by Luminous on 2024/11/5.
// https://codeforces.com/contest/2036/problem/G
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

long long ask(long long l, long long r) {
    cout << "xor " << l << " " << r << endl;
    cout.flush();

    long long res;
    cin >> res;

    return res;
}

void printAns(vector<long long> ans) {
    cout << "ans " << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    cout.flush();
}

vector<long long> find(long long l, long long r, long long xorValue, long long cnt) {
    if (cnt == 1) return {xorValue};
    if (cnt == 2) {
        if (l + 1 == r) return {l, r};

        long long mid = l + (r - l) / 2;
        long long value = ask(l, mid);
        if (value == xorValue) return find(l, mid, xorValue, cnt);
        if (value == 0) return find(mid + 1, r, xorValue, cnt);
        return {value, value ^ xorValue};
    }

    // cnt = 3
    if (l + r == 2) return {l, l + 1, l + 2};
    long long mid = l + (r - l) / 2;
    long long value = ask(l, mid);
    if (value == xorValue) return find(l, mid, xorValue, cnt);
    if (value == 0) return find(mid + 1, r, xorValue, cnt);
    if (l <= value && value <= mid) {
        if (ask(value, value) > 0) {
            vector<long long> res = find(mid + 1, r, value ^ xorValue, 2);
            return {value, res[0], res[1]};
        }
    }

    vector<long long> res = find(l, mid, value, 2);
    return {value ^ xorValue, res[0], res[1]};
}

vector<long long> find(long long l, long long r) {
    if (l + 2 == r) return {l, l + 1, l + 2};

    for (int i = 0; i < 100; i++) {
        long long mid = l >> i << i;
        mid += (1LL << i) - 1;

        long long leftValue = ask(l, mid);
        if (leftValue != 0) {
            vector<long long> res;
            if (leftValue > mid) {
                res = find(l, mid, leftValue, 2);
            } else {
                res = find(mid + 1, r, leftValue, 2);
            }

            return {leftValue, res[0], res[1]};
        }
    }

    return {0, 0, 0};
}

void solve() {
    long long n;
    cin >> n;

    if (n == 3) {
        printAns({1, 2, 3});
        return;
    }

    long long value = ask(1, n);
    if (value != 0) {
        printAns(find(1LL, n, value, 3));
    } else {
        printAns(find(1L, n));
    }
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