#include <iostream>
#include <string>
#include <vector>

using namespace std;
string longestPalindrome(string s) {
    int max_length = 0, pos = 0;
    for (int i = 0; i < s.size(); i++) {
        int sub_length3 = 0, pos3 = 0, sub_length2 = 0, pos2 = 0;
        int j = 0;

        while (s[i - j] == s[i + j]) {
            sub_length3++;
            if (i - j > 0 && i + j < s.size() - 1) {
                j++;
            } else {
                break;
            }
        }
        pos3 = i - sub_length3 + 1;
        sub_length3 = 2 * sub_length3 - 1;

        j = 0;
        while (s[i - j] == s[i + 1 + j]) {
            sub_length2++;
            if (i - j > 0 && i + 1 + j < s.size() - 1) {
                j++;
            } else {
                break;
            }
        }
        if (sub_length2 > 0) {
            pos2 = i - sub_length2 + 1;
            sub_length2 = 2 * sub_length2;
        }

        if (sub_length2 > sub_length3) {
            if (max_length < sub_length2) {
                max_length = sub_length2;
                pos = pos2;
            }
        } else {
            if (max_length < sub_length3) {
                max_length = sub_length3;
                pos = pos3;
            }
        };
    }
    return s.substr(pos, max_length);
}

int main() {
    vector<string> s = {"babad", "cbbd", "ugyrngydfnjthiuyttyuifds", "a"};
    for (auto it : s) {
        cout << longestPalindrome(it) << endl;
    }
}