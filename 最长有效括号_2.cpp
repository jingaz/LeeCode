#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool modify(string &s) {
    bool flag = false;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == '(') {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == '(') {
                    break;
                }
                if (s[j] == ')') {
                    s[i] = ' ';
                    s[j] = ' ';

                    while (i - 1 >= 0 && j + 1 <= s.size() - 1) {
                        if (s[i - 1] == '(' && s[j + 1] == ')') {
                            s[--i] = ' ';
                            s[++j] = ' ';
                            flag = true;
                        }
                        else{
                          break;
                        }
                    };
                    i = j + 1;
                    flag = true;
                    break;
                }
            }
        }
    }
    return flag;
}

int longestValidParentheses(string s) {
    if (s.size() < 2)
        return 0;
    while (modify(s))
        ;
    int max_length = 0;
    int length_sub = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            length_sub++;
            max_length = max(length_sub, max_length);
        } else {
            length_sub = 0;
        }
    }
    return max_length;
}

int main() {
    vector<string> testdata = {
        "))))())()()()()(((()",
        "()(((((((())(()",
    };
    for (string s : testdata) {
        cout << longestValidParentheses(s) << endl;
    }
}