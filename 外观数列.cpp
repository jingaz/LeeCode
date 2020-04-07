#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
    if (n == 1) {
        return "1";
    }
    string s = countAndSay(n - 1);
    string str;
    int count = 0;
    char ch = s[0];
    for (int i = 0; i < s.size(); i++) {
        if (ch == s[i]) {
            count++;
        } else {
            str = str + to_string(count) + ch;
            count = 1;
            ch = s[i];
        }
    }
    if (count > 0) {
        str += to_string(count) + s.back();
    }
    return str;
}

int main() {
    for (int i = 1; i <= 30; i++) {
        cout << "i = " << i << ",  " << countAndSay(i) << endl;
    }
}