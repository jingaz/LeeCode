#include <iostream>
#include <regex>
#include <string>

using namespace std;
bool isNumber(string s) {
    int count = 0;
    int dig = 0;
    for (char a : s) {
        if (a == 'e') {
            if (dig == 0) {
                return false;
            }
            count++;
        }
        if (a >= '0' && a <= '9') {
            dig++;
        }
    }
    if (count >= 2 || dig == 0) {
        return false;
    }
    if (count == 1) {
        regex re("^\\s*(\\+|\\-)?\\d*\\.?\\d*e(\\+|\\-)?\\d+\\s*$");
        return regex_match(s, re);
    } else {
        regex re("^\\s*(\\+|\\-)?\\d*\\.?\\d*\\s*$");
        return regex_match(s, re);
    }
}
struct testdata {
    string str;
    bool ret;
};

int main() {
    vector<testdata> testdata = {
        {"0", true},         {" 0.1 ", true},     {"abc", false},
        {"1 a", false},      {"2e10", true},      {" -90e3   ", true},
        {" 1e", false},      {"e3", false},       {" 6e-1", true},
        {" 99e2.5 ", false}, {"53.5e93", true},   {" --6 ", false},
        {"-+3", false},      {"95a54e53", false}, {".1", true},
        {".", false},        {"0.01822091", true}};
    for (auto it : testdata) {
        if (it.ret != isNumber(it.str)) {
            cout << it.str << "  " << boolalpha << it.ret << endl;
        }
    }
}