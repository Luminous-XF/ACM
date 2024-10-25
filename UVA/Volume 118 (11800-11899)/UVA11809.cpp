//
// Created by Luminous on 2024/10/25.
// https://onlinejudge.org/external/118/11809.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

long long E[10][31];
double M[10][31];

void init() {
    for (int i = 0; i <= 9; i++) {
        for (int j = 1; j <= 30; j++) {
            double m = 1.0 - 1.0 / (1 << (i + 1));
            double e = (1 << j) - 1;
            double v = log10(m) + e * log10(2);
            E[i][j] = v;
            M[i][j] = pow(10, v - E[i][j]);
        }
    }
}

bool solve() {
    string line;
    cin >> line;

    if (line == "0e0") {
        return false;
    }

    double m = stod(line.substr(0, 17));
    long long e = stoll(line.substr(18));
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= 30; j++) {
            if (E[i][j] == e && fabs(m - M[i][j]) < 1e-6) {
                cout << i << " " << j << endl;
                return true;
            }
        }
    }


    return true;
}

int main() {

    ios::sync_with_stdio(false);

    init();
    while (solve());

    return 0;
}