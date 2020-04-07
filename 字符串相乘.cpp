#include <iostream>
#include <vector>
using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    int total_len = num1.size() + num2.size();
    vector<int> ret(total_len, 0);
    for (int i = 0; i < num1.size(); i++) {
        for (int j = 0; j < num2.size(); j++) {
            ret[i + j] += (num1[num1.size() - 1 - i] - '0') *
                          (num2[num2.size() - 1 - j] - '0');
        }
    }
    int carry = 0;
    for (int i = 0; i < total_len; i++) {
        ret[i] += carry;
        carry = ret[i] / 10;
        ret[i] %= 10;
    }
    if (ret.back() == 0) {
        ret.pop_back();
    }
    string s;
    for (int i : ret) {
        s = to_string(i)+s;
    }
    return s;
}

int main() {
    vector<vector<string>> testdata = {
        {"2", "3"},
        {"123", "456"},
    };
    for (auto it : testdata) {
        cout << multiply(it[0], it[1]) << endl;
    }
}