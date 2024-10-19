//
// Created by Luminous on 2024/10/19.
// https://acm.hdu.edu.cn/showproblem.php?pid=2072
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

void solve() {
    string line;
    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }

        stringstream ss(line);

        unordered_map<string, bool> book;
        string s;
        while (ss >> s) {
            book[s] = true;
        }

        cout << book.size() << endl;
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