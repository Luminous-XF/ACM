//
// Created by Luminous on 2024/10/19.
// https://onlinejudge.org/external/119/11935.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

bool solve() {
    string event;
    int before, flow;
    cin >> before >> event >> event >> flow;

    if (before == 0 && flow == 0) {
        return false;
    }

    double cap = 0, ans = INT_MAX;
    int cur, leak = 0;
    do {
        cin >> cur >> event;
        cap = cap - leak * (cur - before) - (double) flow / 100 * (cur - before);
        ans = min(ans, cap);
        before = cur;

        if (event == "Fuel") {
            cin >> event >> flow;
        } else if (event == "Leak") {
            leak++;
        } else if (event == "Gas") {
            cin >> event;
            cap = 0;
        } else if (event == "Mechanic") {
            leak = 0;
        } else if (event == "Goal") {
            break;
        }
    } while (true);

    cout << fixed << setprecision(3) << fabs(ans) << endl;

    return true;
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    //cin >> T;
    while (true) {
        if (!solve()) {
            break;
        }
    }

    return 0;
}