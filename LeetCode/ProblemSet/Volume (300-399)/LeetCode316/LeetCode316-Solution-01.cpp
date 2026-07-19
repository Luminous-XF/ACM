#include <bits/stdc++.h>

class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::vector<std::vector<int>> book(26);

        for (int i = 0; i < s.length(); i++) {
            int c = s[i] - 'a';
            book[c].emplace_back(i);
        }

        int len = 0;
        for (auto v : book) {
            if (!v.empty()) {
                len++;
            }
        }

        int pre = -1;
        std::string ans;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 26; j++) {
                if (book[j].empty()) {
                    continue;
                }

                int idx = *std::upper_bound(book[j].begin(), book[j].end(), pre);
                bool ok = true;
                for (int k = 0; k < 26; k++) {
                    if (book[k].empty() || j == k) {
                        continue;
                    }

                    if (book[k].back() < idx) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    ans.push_back((char) ('a' + j));
                    pre = idx;
                    book[j].clear();
                    break;
                }
            }
        }

        return ans;
    }
};