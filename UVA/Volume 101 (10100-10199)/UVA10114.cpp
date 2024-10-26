//
// Created by Luminous on 2024/10/26.
// https://onlinejudge.org/external/101/10114.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

bool solve() {
    int n, m;
    double downPayment, loanAmount;
    cin >> n >> downPayment >> loanAmount >> m;

    if (n < 0) return false;

    double rates[n + 1];
    for (int i = 0; i < m; i++) {
        int k;
        double rate;
        cin >> k >> rate;

        for (int j = k; j <= n; j++) {
            rates[j] = rate;
        }
    }

    int mouth = 0;
    double carAmount = downPayment + loanAmount;
    double repaymentAmount = loanAmount / n;
    for (mouth = 0; mouth < n; mouth++) {
        carAmount = carAmount - carAmount * rates[mouth];
        if (loanAmount < carAmount) break;
        loanAmount -= repaymentAmount;
    }

    cout << mouth << " " << (mouth == 1 ? "month" : "months") << endl;

    return true;
}

int main() {

    ios::sync_with_stdio(false);

    while (solve());

    return 0;
}