//
// Created by Luminous on 2024/12/3 14:08
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define endl "\n"


const int MAX_N = 5e3 + 10;

int a[MAX_N];
int b[MAX_N];
long long preSum[MAX_N];
long long sufSum[MAX_N];

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }

    preSum[0] = sufSum[n + 1] = 0;
    for (int i = 1, j = n; i <= n && j >= 1; i++, j--) {
        preSum[i] = preSum[i - 1] + std::max(a[i], b[i]);
        sufSum[j] = sufSum[j + 1] + std::max(a[j], b[j]);
    }

//    for (int i = 1; i <= n; i++) {
//        std::cerr<< a[i] << "\t";
//    }
//    std::cerr << endl;
//    for (int i = 1; i <= n; i++) {
//        std::cerr<< b[i] << "\t";
//    }
//    std::cerr << endl;
//    for (int i = 1; i <= n; i++) {
//        std::cerr << preSum[i] << "\t";
//    }
//    std::cerr << endl;
//    for (int i = 1; i <= n; i++) {
//        std::cerr<< sufSum[i] << "\t";
//    }
//    std::cerr << endl;
//    std::cerr << endl;


    long long ans = LONG_LONG_MIN;
    for (int i = 1; i <= n; i++) {
        long long temp = a[i] + b[i] + preSum[i - 1] + sufSum[i + 1];
        ans = std::max(ans, temp);
    }

    std::cout << ans << endl;
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