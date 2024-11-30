//
// Created by Luminous on 2024/11/12 13:54.
// https://codeforces.com/contest/977/problem/D
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int MAX_N = 1e2 + 10;

unordered_map<long long, bool> book;

void dfs(long long x, vector<long long> &ans, int n) {
    if (ans.size() == n) {
        for (auto v : ans) {
            cout << v << " ";
        }
        cout << endl;
    }

    if (x % 3 == 0 && book[x / 3]) {
        ans.push_back(x / 3);
        dfs(x / 3, ans, n);
        ans.pop_back();
    }

    if (book[x * 2]) {
        ans.push_back(x * 2);
        dfs(x * 2, ans, n);
        ans.pop_back();
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        book[x] = true;
    }

    cout << book.size() << endl;

    for (auto [key,  value] : book) {
        if (!value) continue;
        vector<long long> ans;
        ans.push_back(key);
        dfs(key, ans, n);
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