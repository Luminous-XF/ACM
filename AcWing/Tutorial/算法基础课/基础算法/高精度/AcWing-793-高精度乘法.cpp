//
// Created by Luminous on 2024/11/30 17:58.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

vector<int> mul(vector<int> &a, int b) {
    const int aLen = (int) a.size();

    int t = 0;
    vector<int> res;
    for (int i = 0; i < aLen || t > 0; i++) {
        if (i < aLen) t += a[i] * b;
        res.push_back(t % 10);
        t /= 10;
    }

    while (res.size() > 1 && res.back() == 0) res.pop_back();

    return res;
}

void solve() {
    string s;
    int b;
    cin >> s >> b;

    vector<int> a;
    for (int i = (int) s.size() - 1; i >= 0; i--) {
        a.push_back(s[i] - '0');
    }

    auto ans = mul(a, b);
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