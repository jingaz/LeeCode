#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isScramble(string s1, string s2) {
    if (s1 == s2) {
        return true;
    }
    int N = s1.size();
    int pos[26] = {0};
    for (int i = 0; i < N; i++) {
        ++pos[s1[i] - 'a'];
        --pos[s2[i] - 'a'];
    }
    for (int i : pos) {
        if (i) {
            return false;
        }
    }
    for (int i = 1; i < N; i++) {
        if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i))){
            return true;
        }
        if(isScramble(s1.substr(0,i), s2.substr(N-i)) && isScramble(s1.substr(i), s2.substr(0,N-i))){
            return true;
        }
    }
    return false;
}

struct testdata {
    string s1;
    string s2;
    bool ans;
};

int main() {
    vector<testdata> data = {
        {"greatgr", "rgeatrg", true}, {"great", "rgtae", true},
        {"abcde", "caebd", false},    {"eatgr", "rgeat", true},
        {"abcd", "cabd", true},
    };
    for (auto it : data) {
        if (it.ans != isScramble(it.s1, it.s2)) {
            cout << it.s1 << "  " << it.s2 << "   " << boolalpha << it.ans
                 << "   wrong_ans = " << boolalpha << !it.ans << endl;
        }
    }
}