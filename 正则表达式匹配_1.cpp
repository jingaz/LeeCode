#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    if (p.empty()) {
        return s.empty();
    }
    bool first_match =
        s.front() && (s.front() == p.front() || p.front() == '.');
    if (p[1] == '*') {
        return isMatch(s, p.substr(2, p.size() - 2)) ||
               (first_match && isMatch(s.substr(1, s.size() - 1), p));
    } else {
        return (first_match &&
                isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1)));
    }
}
struct testdata {
    string s1;
    string s2;
};
int main() {

    vector<testdata> data = {
        {"aab", "c*a*b"}, {"aa", "b**aa"}, {"aa", "a"},
        {"aa", "a*"},     {"ab", ".*"},    {"mississippi", "mis*is*p*."},
    };
    for (auto it : data) {
        cout << it.s1 << " " << it.s2 << " " << isMatch(it.s1, it.s2) << endl;
    }
}