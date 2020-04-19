#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string minWindow(string s, string t) {
    int count[256] = {0};
    for (auto c : t)
        ++count[c];
    int len = 0, minLength = s.length();
    string res;
    // 一边吃一边吐，吃-- 吐++
    for (int l = 0, r = 0; r < s.length(); ++r) {
        if (--count[s[r]] >= 0)
            ++len;
        while (len == t.length()) {
            if (r - l + 1 <= minLength) {
                minLength = r - l + 1;
                res = s.substr(l, r - l + 1);
            }
            if (++count[s[l++]] > 0)
                --len;
        }
    }
    return res;
}

int main() {
    vector<vector<string>> testdata = {
        {"ADOBECODEBANC", "ABC"},
        {"a", "aa"},
        {"bbaa", "aba"},
    };
    for (auto it : testdata) {
        cout << minWindow(it[0], it[1]) << endl;
    }
}