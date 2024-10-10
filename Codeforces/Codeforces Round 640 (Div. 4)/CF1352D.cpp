//
// Created by Luminous on 2024/10/2.
// https://codeforces.com/contest/1352/problem/D
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

deque<int> q;

void solve() {
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        q.push_back(x);
    }

    int time = 0, a = 0, b = 0, preSize = 0;
    while (!q.empty()) {
        time++;
        int size = 0;
        if ((time & 1) == 1) {
            while (!q.empty() && size <= preSize) {
                size += q.front();
                q.pop_front();
            }
            a += size;
        } else {
            while (!q.empty() && size <= preSize) {
                size += q.back();
                q.pop_back();
            }
            b += size;
        }
        preSize = size;
    }

    cout << time << " " << a << " " << b << endl;
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
