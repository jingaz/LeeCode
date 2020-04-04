#include <iostream>
#include <string>
#include <vector>

using namespace std;

void push_ret(vector<string> &result, vector<string> str) {
    vector<string> ret;

    if (result.empty()) {
        for (string s : str) {
            result.push_back(s);
        }
        return;
    } else {
        vector<string> tmp = result;
        for (string s : str) {
            for (string str : tmp) {
                str += s;
                ret.push_back(str);
            }
        }
    }
    result = ret;
}
vector<string> letterCombinations(string digits) {
    vector<string> ret;
    vector<string> s2 = {"a", "b", "c"};
    vector<string> s3 = {"d", "e", "f"};
    vector<string> s4 = {"g", "h", "i"};
    vector<string> s5 = {"j", "k", "l"};
    vector<string> s6 = {"m", "n", "o"};
    vector<string> s7 = {"p", "q", "r", "s"};
    vector<string> s8 = {"t", "u", "v"};
    vector<string> s9 = {"w", "x", "y", "z"};
    for (char ch : digits) {
        switch (ch) {
        case '2':
            push_ret(ret, s2);
            break;
        case '3':
            push_ret(ret, s3);
            break;
        case '4':
            push_ret(ret, s4);
            break;
        case '5':
            push_ret(ret, s5);
            break;
        case '6':
            push_ret(ret, s6);
            break;
        case '7':
            push_ret(ret, s7);
            break;
        case '8':
            push_ret(ret, s8);
            break;
        case '9':
            push_ret(ret, s9);
            break;

        default:
            break;
        }
    }
    return ret;
}

int main() {
    vector<string> testdata = {
        "23",
        "95765",
        "863",
        "76",
    };
    for (string s : testdata) {
        cout << "[ ";
        for (string it : letterCombinations(s)) {
            cout << it << ", ";
        };
        cout << "\b\b ]";
        cout << endl;
    }
}
