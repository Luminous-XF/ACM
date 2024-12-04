//
// Created by Luminous on 2024/12/4 13:20
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    const int N = 8;
    const int dx[10] = {0, 1, 0, -1, 0, 1, -1, 1, -1, 0};
    const int dy[10] = {0, 0, 1, 0, -1, 1, -1, -1, 1, 0};

    int countCombinations(std::vector<std::string> &pieces, std::vector<std::vector<int>> &positions) {
        const int n = (int) pieces.size();
        std::vector<std::array<int, 2>> moves;
        int ans = dfs(0, n, moves, pieces, positions);
        return ans;
    }

    int dfs(int step, int n, std::vector<std::array<int, 2>> &moves, std::vector<std::string> &pieces, std::vector<std::vector<int>> &positions) {
        if (step == n) {
            return check(positions, moves) ? 1 : 0;
        }

        int res = 0;
        auto& piece = pieces[step];
        int x = positions[step][0];
        int y = positions[step][1];
        for (int i = 0; i < 10; i++) {
            if (piece == "rook" && i > 4) break;
            if (piece == "queen" && i > 8) break;
            if (piece == "bishop" && i < 5) continue;
            for (int t = 1; t <= N; t++) {
                int nx = x + dx[i] * t;
                int ny = y + dy[i] * t;
                if (nx < 1 || nx > N || ny < 1 || ny > N) break;
                moves.push_back({i, t});
                res += dfs(step + 1, n, moves, pieces, positions);
                moves.pop_back();
                if (i == 0 || i == 9) break;
            }
        }
        return res;
    }

    bool check(std::vector<std::vector<int>> &positions, std::vector<std::array<int, 2>> &moves) {
        const int n = (int) positions.size();
        for (int t = 1; t < N; t++) {
            std::unordered_map<int, bool> book;
            for (int i = 0; i < n; i++) {
                auto& [d, step] = moves[i];
                int x = positions[i][0] + std::min(t, step) * dx[d];
                int y = positions[i][1] + std::min(t, step) * dy[d];
                int hash = x * 10 + y;
                if (book[hash]) return false;
                book[hash] = true;
            }
        }
        return true;
    }
};