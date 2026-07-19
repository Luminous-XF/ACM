#include <bits/stdc++.h>

class Solution {
public:
    std::string smallestSubsequence(std::string s) {
        std::unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }

        std::string ans;
        std::set<char> book;
        for (char c : s) {
            cnt[c]--;
            if (book.contains(c)) {
                continue;
            }
            
            while (!ans.empty() && c < ans.back() && cnt[ans.back()] > 0) {
                book.erase(ans.back());
                ans.pop_back();
            }

            book.insert(c);
            ans.push_back(c);
        }

        return ans;
    }
};