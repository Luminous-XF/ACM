#include <bits/stdc++.h>

#define endl "\n"

void solve() {
    int n;
    std::cin >> n;

    int v, ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> v;
        if (cnt == 0) {
            ans = v;
        }

         ans == v ? cnt++ : cnt--;
    }

    std::cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}