#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addBinary(string a, string b) {
    string long_str = a.size() > b.size() ? a : b;
    string short_str = a.size() > b.size() ? b : a;
    int i = long_str.size() - 1;
    int j = short_str.size() - 1;
    int ca = 0;
    for (; i >= 0; i--) {
        if (j >= 0) {
            int num = long_str[i] - '0' + short_str[j--] - '0' + ca;
            ca = num / 2;
            long_str[i] = num % 2 + '0';
            if (i == 0) {
                if (ca == 1) {
                    long_str.insert(long_str.begin(), '1');
                }
            }
        } else {
            if (ca == 0) {
                return long_str;
            }
            int num = long_str[i] - '0' + ca;
            ca = num / 2;
            long_str[i] = num % 2 + '0';
            if (i == 0) {
                if (ca == 1) {
                    long_str.insert(long_str.begin(), '1');
                }
            }
        }
    }
    return long_str;
}

struct testdata {
    string a;
    string b;
};
int main() {
    vector<testdata> data = {
        {"11", "1"},
        {"1010", "1011"},
    };
    for (auto it : data) {
        cout << addBinary(it.a, it.b) << endl;
    }
}