//
// Created by Luminous on 2024/10/22.
// https://onlinejudge.org/external/100/10008.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

struct Pair {
    char ch;
    int cnt;

    bool operator<(const Pair &rhs) const {
        if (cnt > rhs.cnt) return true;
        if (cnt < rhs.cnt) return false;
        return ch < rhs.ch;
    }
};

void solve() {
    int n;
    cin >> n;

    cin.ignore();

    unordered_map<char, int> book;
    while (n-- > 0) {
        string line;
        getline(cin, line);

        for (char c : line) {
            if (isalpha(c)) {
                c = toupper(c);
                book[c]++;
            }
        }
    }

    vector<Pair> v;
    for (auto &[ch, cnt] : book) {
        v.push_back({ch, cnt});
    }

    sort(v.begin(), v.end());

    for (auto &item : v) {
        cout << item.ch << " " << item.cnt << endl;
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