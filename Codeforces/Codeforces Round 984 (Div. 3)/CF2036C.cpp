//
// Created by Luminous on 2024/11/5.
// https://codeforces.com/contest/2036/problem/C
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

int count1100(string &s, int left, int right) {
    int res = 0;
    for (int i = left; i <= right - 3; i++) {
        if (s[i + 0] == '1' && s[i + 1] == '1' &&
            s[i + 2] == '0' && s[i + 3] == '0') {
            res++;
        }
    }
    return res;
}

void solve() {
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.length() - 3; i++) {
        cnt += count1100(s, i, i + 3);
    }

    int q;
    cin >> q;
    while (q-- > 0) {
        int index;
        char c;
        cin >> index >> c;

        index -= 1;
        int left = max(0, index - 3), right = min((int) s.length(), index + 3);
        cnt -= count1100(s, left, right);
        s[index] = c;
        cnt += count1100(s, left, right);

        cout << (cnt > 0 ? "YES" : "NO") << endl;
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