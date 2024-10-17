//
// Created by Luminous on 2024/10/16.
// https://onlinejudge.org/external/1/123.pdf
//

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


const int MAX_N = 2e5 + 10;

struct Title {
    string keyWord;
    string title;
    int index;

    bool operator<(const Title &rhs) const {
        if (keyWord < rhs.keyWord) return true;
        if (keyWord > rhs.keyWord) return false;
        if (index < rhs.index) return true;
        if (index > rhs.index) return false;
        return title < rhs.title;
    }
};

unordered_map<string, bool> ignoreWords;
vector<Title> titles;


string toLower(string word, int start, int end) {
    transform(word.begin() + start, word.begin() + end, word.begin() + start, ::tolower);
    return word;
}

string toUpper(string word, int start, int end) {
    transform(word.begin() + start, word.begin() + end, word.begin()  + start, ::toupper);
    return word;
}


void solve() {
    string ignoreWord;
    while (cin >> ignoreWord && ignoreWord != "::") {
        ignoreWord = toUpper(ignoreWord, 0, ignoreWord.size());
        ignoreWords[ignoreWord] = true;
    }

    cin.ignore();

    int index = 0;
    string title;
    while (getline(cin, title)) {
        if (title == "-1") break;

        title = toLower(title, 0, title.size());
        for (int i = 0; i < title.size(); i++) {
            if (title[i] == ' ') continue;

            int j = i;
            while (j < title.size() && title[j] != ' ') j++;

            string word = title.substr(i, j - i);
            word = toUpper(word, 0, word.size());
            if (!ignoreWords[word]) {
                titles.push_back({
                    word,
                    toUpper(title, i, j),
                    index++,
                });
            }

            i = j;
        }
    }

    sort(titles.begin(), titles.end());

    for (auto &item : titles) {
        cout << item.title << endl;
    }
}

int main() {

    ios::sync_with_stdio(false);

    int T = 1;
    //cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}