#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool dfs(string s1, string s2, string s3) {
    if (s1.empty()) {
        return s2 == s3;
    }
    if (s2.empty()) {
        return s1 == s3;
    }
    char a = s3.back();
    s3.pop_back();
    if (s1.back() == a) {
        if (dfs(s1.substr(0, s1.size() - 1), s2, s3)) {
            return true;
        }
    }
    if (s2.back() == a) {
        if (dfs(s1, s2.substr(0, s2.size() - 1), s3)) {
            return true;
        }
    }
    return false;
}
bool isInterleave(string s1, string s2, string s3) {
    if (s3.size() != s1.size() + s2.size()) {
        return false;
    }
    return dfs(s1, s2, s3);
}

int main() {
    vector<vector<string>> testdata = {
        {"aabcc", "dbbca", "aadbbcbcac"},
        {"aabcc", "dbbca", "aadbbbaccc"},
    };
    for (auto it : testdata) {
        cout << boolalpha << isInterleave(it[0], it[1], it[2]) << endl;
    }
}