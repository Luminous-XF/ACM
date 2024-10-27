//
// Created by Luminous on 2024/10/27.
// https://onlinejudge.org/external/4/465.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

bool isZero(string s) {
    return count(s.begin(), s.end(), '0') == s.length();
}

bool check(string s) {
    reverse(s.begin(), s.end());
    while (s.size() > 1 && s.back() == '0') s.pop_back();
    reverse(s.begin(), s.end());
    long long num = stoll(s.substr(max(0, (int) (s.length() - 10))));
    return num > INT_MAX || s.length() > 10;
}

void solve() {
    string first, second, op;
    while (cin >> first >> op >> second) {
        cout << first << " " << op << " " << second << endl;

        if (check(first)) {
            cout << "first number too big" << endl;
        }

        if (check(second)) {
            cout << "second number too big" << endl;
        }

        if (check(first) || check(second)) {
            if (!isZero(first) && !isZero(second)) {
                cout << "result too big" << endl;
            }
            continue;
        }

        if (op == "+" && stoll(first) + stoll(second) > INT_MAX) {
            cout << "result too big" << endl;
        }

        if (op == "*" && stoll(first) * stoll(second) > INT_MAX) {
            cout << "result too big" << endl;
        }
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