//
// Created by Luminous on 2024/12/3 14:08
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 2e5 + 10;

int TB[20];

void init() {
    TB[0] = 1;
    TB[1] = 1;
    for (int i = 2; i <= 10; i++) {
        TB[i] = TB[i - 1] * i;
    }
}

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::string ans;
    int minCnt = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::string ss = s;
            ss[i] = ss[j];

            int temp = TB[n];
            for (char c = 'a'; c <= 'z'; c++) {
                int cnt = (int) std::count(ss.begin(), ss.end(), c);
                temp /= TB[cnt];
            }

            if (temp < minCnt) {
                minCnt = temp;
                ans = ss;
            }
        }
    }

    std::cout << ans << endl;
}

int main() {

    std::ios::sync_with_stdio(false);

    init();

    int T = 1;
    std::cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}