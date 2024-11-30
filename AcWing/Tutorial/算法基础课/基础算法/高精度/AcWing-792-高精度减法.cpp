//
// Created by Luminous on 2024/11/30 17:19.
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

bool cmp(vector<int> &a, vector<int> &b) {
    const int aLen = (int) a.size();
    const int bLen = (int) b.size();

    if (aLen != bLen) return aLen > bLen;

    for (int i = aLen - 1; i >= 0; i--) {
        if (a[i] == b[i]) continue;
        return a[i] > b[i];
    }

    return true;
}

vector<int> sub(vector<int> &a, vector<int> &b) {
    const int aLen = (int) a.size();
    const int bLen = (int) b.size();

    int t = 0;
    vector<int> res;
    for (int i = 0; i < aLen; i++) {
        t = a[i] - t;
        if (i < bLen) t -= b[i];
        res.push_back((t + 10) % 10);
        t = (t < 0 ? 1 : 0);
    }

    while (res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }

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

    if (cmp(a, b)) {
        auto ans = sub(a, b);
        for (int i = (int) ans.size() - 1; i >= 0; i--) {
            cout << ans[i];
        }
    } else {
        auto ans = sub(b, a);
        cout << "-";
        for (int i = (int) ans.size() - 1; i >= 0; i--) {
            cout << ans[i];
        }
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