//
// Created by Luminous on 2024/10/23.
// https://onlinejudge.org/external/3/391.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    bool flag = false;
    string s;
    while (getline(cin, s)) {
        s.push_back('\n');
        for (int i = 0; i < s.length(); i++) {
            if (!flag) {
                if (s[i] == '\\') {
                    if (s[i + 1] == '\\') {
                        cout << '\\';
                        i++;
                    } else if (s[i + 1] == 'i' || s[i + 1] == 'b') {
                        i++;
                    } else if (s[i + 1] == 's') {
                        int j = i + 1;
                        while (j + 1 < s.length() && (s[j + 1] == '.' || isdigit(s[j + 1]))) {
                            j++;
                        }
                        i = j;
                    } else if (s[i + 1] == '*') {
                        flag = true;
                        i++;
                    }
                } else {
                    cout << s[i];
                }
            } else {
                if (s[i] == '\\' && s[i + 1] == '*') {
                    flag = false;
                    i++;
                } else {
                    cout << s[i];
                }
            }
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