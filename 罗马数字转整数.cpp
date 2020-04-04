#include <iostream>
#include <vector>

using namespace std;

int romanToInt(string s) {
    int ret = 0;
    while (!s.empty()) {
        char ch = s.back();
        s.pop_back();
        switch (ch) {
        case 'I':
            ret += 1;
            break;
        case 'V':
            if (!s.empty() && s.back() == 'I') {
                ret += 4;
                s.pop_back();
            } else {
                ret += 5;
            }
            break;
        case 'X':
            if (!s.empty() && s.back() == 'I') {
                ret += 9;
                s.pop_back();
            } else {
                ret += 10;
            }
            break;
        case 'L':
            if (!s.empty() && s.back() == 'X') {
                ret += 40;
                s.pop_back();
            } else {
                ret += 50;
            }
            break;
        case 'C':
            if (!s.empty() && s.back() == 'X') {
                ret += 90;
                s.pop_back();
            } else {
                ret += 100;
            }
            break;
        case 'D':
            if (!s.empty() && s.back() == 'C') {
                ret += 400;
                s.pop_back();
            } else {
                ret += 500;
            }
            break;
        case 'M':
            if (!s.empty() && s.back() == 'C') {
                ret += 900;
                s.pop_back();
            } else {
                ret += 1000;
            }
            break;
        default:
            break;
        }
    }

    return ret;
}

int main() {
    vector<string> testdata = {"III", "IV", "IX", "LVIII", "MCMXCIV"};
    for (string it : testdata) {
        cout << it << ":  " << romanToInt(it) << endl;
    }
}