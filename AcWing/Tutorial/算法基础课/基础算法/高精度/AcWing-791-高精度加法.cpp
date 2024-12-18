//
// Created by Luminous on 2024/11/29 20:21.
// https://www.acwing.com/problem/content/793/
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 1e5 + 10;

vector<int> add(vector<int> &a, vector<int> &b) {
    vector<int> res;

    int t = 0;
    const int aLen = (int) a.size();
    const int bLen = (int) b.size();
    for (int i = 0; i < aLen || i < bLen; i++) {
        if (i < aLen) t += a[i];
        if (i < bLen) t += b[i];
        res.push_back(t % 10);
        t /= 10;
    }

    if (t > 0) res.push_back(t);

    return res;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    vector<int> a;
    for (int i = (int) s1.size() - 1; i >= 0; i--) {
        a.push_back(s1[i] - '0');
    }

    vector<int> b;
    for (int i = (int) s2.size() - 1; i >= 0; i--) {
        b.push_back(s2[i] - '0');
    }

    auto ans = add(a, b);
    for (int i = (int) ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
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