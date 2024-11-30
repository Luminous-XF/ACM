//
// Created by Luminous on 2024/11/30 18:22.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

tuple<vector<int>, int> div(vector<int> &a, int b) {
    const int aLen = (int) a.size();

    int t = 0;
    vector<int> res;
    for (int i = aLen - 1; i >= 0; i--) {
        t = t * 10 + a[i];
        res.push_back(t / b);
        t %= b;
    }

    reverse(res.begin(), res.end());

    while (res.size() > 1 && res.back() == 0) res.pop_back();

    return {res, t};
}

void solve() {
    string s;
    int b;
    cin >> s >> b;

    vector<int> a;
    for (int i = (int) s.size() - 1; i >= 0; i--) {
        a.push_back(s[i] - '0');
    }

    auto [ans, r] = div(a, b);
    for (int i = (int) ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    cout << r << endl;
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