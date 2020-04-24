#include <iostream>
#include <vector>
using namespace std;
int numDecodings(string s) {
    int N = s.size();
    if (s.front() == '0') {
        return 0;
    }
    int pre1 = 1, pre2 = 1, cur = 1;
    for (int i = 1; i < N; i++) {
        if (s[i] == '0') {
            if (s[i - 1] != '1' && s[i - 1] != '2') {
                return 0;
            }
            cur = pre1;
        } else {
            int tmp = (s[i - 1] - '1' + 1) * 10 + (s[i] - '1' + 1);
            if (tmp <= 26 && tmp > 10) {
                cur = pre1 + pre2;

            } else if (tmp > 26) {
                cur = pre2;
            }
        }
        pre1 = pre2;
        pre2 = cur;
    }
    return cur;
}
int main() {
    vector<string> testdata = {
        "26",
        "226",
        "110",
        "1",
        "0",

    };
    for (auto it : testdata) {
        cout << numDecodings(it) << endl;
    }
}