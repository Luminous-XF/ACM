//
// Created by Luminous on 2024/12/5 22:13
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 2e5 + 10;



void solve() {
    std::string s;
    std::cin >> s;

    int k = 0, cnt2 = 0, cnt3 = 0;
    for (char c : s) {
        k = (k * 10 + (c - '0')) % 9;
        if (c == '2') cnt2++;
        if (c == '3') cnt3++;
    }

    if (k == 0) {
        std::cout << "YES" << endl;
        return;
    }

//    std::cerr << k << " " << std::stoll(s) % 9 << endl;

    cnt2 = std::min(cnt2, 9);
    cnt3 = std::min(cnt3, 2);
    for (int i = 0; i <= cnt2; i++) {
        for (int j = 0; j <= cnt3; j++) {
            if ((i * 2 + j * 6) % 9 == 9 - k) {
                std::cout << "YES" << endl;
                return;
            }
        }
    }
    std::cout << "NO" << endl;
}

int main() {

    std::ios::sync_with_stdio(false);

    int T = 1;
    std::cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}