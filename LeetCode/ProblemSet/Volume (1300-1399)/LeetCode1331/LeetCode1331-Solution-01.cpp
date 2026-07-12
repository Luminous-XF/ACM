#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        std::vector<int> a(arr);
        std::ranges::sort(a);
        
        std::unordered_map<int, int> book;
        for (int v : a) {
            if (!book.contains(v)) {
                book[v] = book.size() + 1;
            }
        }

        std::vector<int> ans;
        for (int v : arr) {
            ans.emplace_back(book[v]);
        }

        return ans;
    }
};