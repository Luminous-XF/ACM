//
// Created by Luminous on 2024/12/6 17:02
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>

class Solution {
public:
    const int N = 8;

    int numRookCaptures(std::vector<std::vector<char>>& board) {
        int x = -1, y = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != 'R') continue;
                x = i, y = j;
            }
        }

        int ans = 0;
        for (int nx = x - 1; nx >= 0; nx--) {
            if (board[nx][y] == '.') continue;
            if (board[nx][y] == 'B') break;
            if (board[nx][y] == 'p') {
                ans++;
                break;
            }
        }

        for (int nx = x + 1; nx <= N; nx++) {
            if (board[nx][y] == '.') continue;
            if (board[nx][y] == 'B') break;
            if (board[nx][y] == 'p') {
                ans++;
                break;
            }
        }

        for (int ny = y - 1; ny >= 0; ny--) {
            if (board[x][ny] == '.') continue;
            if (board[x][ny] == 'B') break;
            if (board[x][ny] == 'p') {
                ans++;
                break;
            }
        }

        for (int ny = y + 1; ny <= N; ny++) {
            if (board[x][ny] == '.') continue;
            if (board[x][ny] == 'B') break;
            if (board[x][ny] == 'p') {
                ans++;
                break;
            }
        }

        return ans;
    }
};