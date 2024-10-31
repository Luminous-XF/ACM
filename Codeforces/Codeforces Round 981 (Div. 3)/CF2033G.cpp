//
// Created by Luminous on 2024/10/31.
// https://codeforces.com/contest/2033/problem/G
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

struct Query {
    int k;
    int id;
};

struct SegmentTree {
    int n;
    int *C;

    explicit SegmentTree(int n) {
        this->n = (n + 10) << 2;
        C = (int *) malloc(sizeof(int) * this->n);
    }

    void pushUp(int root) {
        C[root] = max(C[root << 1], C[root << 1 | 1]);
    }

    void build(int l, int r, int root) {
        if (l == r) {
            C[root] = INT_MIN;
        } else {
            int mid = l + r >> 1;
            build(l, mid, root << 1);
            build(mid + 1, r, root << 1 | 1);
            pushUp(root);
        }
    }

    void update(int k, int v, int l, int r, int root) {
        if (l == r) {
            C[root] = v;
            return;
        }

        int mid = l + r >> 1;
        if (k <= mid) {
            update(k, v, l, mid, root << 1);
        } else {
            update(k, v, mid + 1, r, root << 1 | 1);
        }

        pushUp(root);
    }

    int query(int L, int R, int l, int r, int root) {
        if (L <= l && r <= R) {
            return C[root];
        }

        int res = INT_MIN;
        int mid = l + r >> 1;
        if (L <= mid) {
            res = max(res, query(L, R, l, mid, root << 1));
        }
        if (mid < R) {
            res = max(res, query(L, R, mid + 1, r, root << 1 | 1));
        }

        return res;
    }
};

vector<int> edge[MAX_N];
int depth[MAX_N];
int maxDepth[MAX_N];
vector<Query> query[MAX_N];
int ans[MAX_N];

void init(int n) {
    for (int i = 0; i < n + 10; i++) {
        edge[i].clear();
        depth[i] = 0;
        maxDepth[i] = 0;
        query[i].clear();
    }
}

void getDepth(int u, int fa) {
    for (int v: edge[u]) {
        if (v == fa) continue;
        depth[v] = depth[u] + 1;
        getDepth(v, u);
        maxDepth[u] = max(maxDepth[u], maxDepth[v] + 1);
    }
}

void dfs(int u, int fa, int n, SegmentTree &segTree) {
    for (auto &[k, id]: query[u]) {
        int dis = segTree.query(max(0, depth[u] - k), depth[u], 0, n - 1, 1) + depth[u];
        ans[id] = max(maxDepth[u], dis);
    }

    int max1 = 0, max2 = 0;
    for (int v : edge[u]) {
        if (v == fa) continue;

        if (maxDepth[v] + 1 > max1) {
            max2 = max1;
            max1 = maxDepth[v] + 1;
        } else if (maxDepth[v] + 1 > max2) {
            max2 = maxDepth[v] + 1;
        }
    }

    for (int v: edge[u]) {
        if (v == fa) continue;

        int d = maxDepth[v] + 1 == max1 ? max2 : max1;
        segTree.update(depth[u], d - depth[u], 0, n - 1, 1);

        dfs(v, u, n, segTree);
        segTree.update(depth[u], INT_MIN, 0, n - 1, 1);
    }
}

void solve() {
    int n;
    cin >> n;

    init(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;
        query[v].push_back({k, i});
    }

    getDepth(1, 0);

    SegmentTree segTree(n);
    segTree.build(0, n - 1, 1);

    dfs(1, 0, n, segTree);

    for (int i = 0; i < q; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}