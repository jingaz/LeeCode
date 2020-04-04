#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    if (p.empty()) {
        return s.empty();
    }
    if (s.empty()) {
        if (p.empty()) {
            return true;
        } else if (p.size() == 1) {
            return false;
        } else if (p.back() == '*') {
            p.pop_back();
            p.pop_back();
            return isMatch(s, p);
        } else {
            return false;
        }
    }

    while (s.back() == p.back() || p.back() == '.') {
        if (!s.empty() && !p.empty()) {
            s.pop_back();
            p.pop_back();
        } else {
            return isMatch(s, p);
        }
    }
    if(p.back()!='*'){
        return false;
    }
    else {
        while (p.back() == '*') {
            p.pop_back();
            if (p.empty()) {
                return false;
            }
        }

        while (s.back() == p.back()||p.back()=='.') {
            if (!s.empty()) {
                s.pop_back();
            } else {
                p.pop_back();
                return isMatch(s, p);
            }
        }
        p.pop_back();
        return isMatch(s, p);
    }

    return true; //正常情况下不会到达这里
}
struct testdata {
    string s1;
    string s2;
};
int main() {

    vector<testdata> data = {
        {"aab", "c*a*b"},
        {"aa","b**aa"},
        {"aa", "a"},
        {"aa", "a*"},
        {"ab", ".*"},
        {"mississippi", "mis*is*p*."},
    };
    for (auto it : data) {
        cout << it.s1 << " " << it.s2 << " " << isMatch(it.s1, it.s2) << endl;
    }
}