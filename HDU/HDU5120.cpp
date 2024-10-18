//
// Created by Luminous on 2024/10/17.
// https://acm.hdu.edu.cn/showproblem.php?pid=5120
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;
const double PI = acos(-1);


struct Circle {
    double x, y;
    double r;
};

double getDis(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double getArea(Circle a, Circle b) {
    if (a.r < b.r) swap(a, b);

    double dis = getDis(a.x, a.y, b.x, b.y);

    if (dis >= a.r + b.r) return 0;

    if (dis <= a.r - b.r) return PI * b.r * b.r;

    double theta1 = 2 * acos((a.r * a.r + dis * dis - b.r * b.r) / (2 * a.r * dis));
    double theta2 = 2 * acos((b.r * b.r + dis * dis - a.r * a.r) / (2 * b.r * dis));
    double area1 = theta1 * a.r * a.r / 2;
    double area2 = theta2 * b.r * b.r / 2;
    double area3 = a.r * dis * sin(theta1 / 2);
    double area = area1 + area2 - area3;

    return area;
}

void solve(int testCase) {
    double r, R, x1, y1, x2, y2;
    cin >> r >> R >> x1 >> y1 >> x2 >> y2;

    Circle A = {x1, y1, R}, a = {x1, y1, r};
    Circle B = {x2, y2, R}, b = {x2, y2, r};

    double ans = getArea(A, B) - getArea(A, b) - getArea(a, B) + getArea(a, b);

    cout << "Case #" << testCase << ": ";
    cout << fixed << setprecision(6) << ans << endl;
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }

    return 0;
}
