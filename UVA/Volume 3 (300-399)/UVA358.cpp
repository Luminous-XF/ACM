//
// Created by Luminous on 2024/10/17.
// https://onlinejudge.org/external/3/358.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;
const double PI = acos(-1);

bool check(double R, double P, double r) {
    double theta1 = 2 * acos((R * R * 2 - r * r) / (2 * R * R));
    double theta2 = 2 * acos(r / (2 * R));
    double area1 = theta1 * R * R / 2;
    double area2 = theta2 * r * r / 2;
    double area3 = R * R * sin(theta1 / 2);
    double area = area1 + area2 - area3;

    return area / (PI * R * R) > P;
}

void solve(int testCase) {
    double R, P;
    cin >> R >> P;

    double left = 0, right = 2 * R;
    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        if (check(R, P, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << fixed << setprecision(0) << "R = " << R << setprecision(2) << ", P = " << P << ", Rope = " << right << endl;
    if (testCase > 0) cout << endl;
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;
    while (T-- > 0) {
        solve(T);
    }

    return 0;
}