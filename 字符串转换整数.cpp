#include <iostream>
#include <vector>

using namespace std;

int myAtoi(string str) {
    char sig = ' ';
    for (int i = 0; i < str.size(); i++) {
        char it = str[i];
        if (it >= '0' && it <= '9') {
            if (sig == ' ' || sig == '+') {
                int ret = 0;
                for (; str[i] >= '0' && str[i] <= '9' && i < str.size(); i++) {
                    if ((INT32_MAX - (str[i] - '0'))/10 < ret) {
                        return INT32_MAX;
                    }
                    ret = 10 * ret + (str[i] - '0');
                }
                return ret;
            } else {
                int ret = 0;
                for (; str[i] >= '0' && str[i] <= '9' && i < str.size(); i++) {
                    if((INT32_MIN+(str[i] - '0'))/10 > ret){
                        return INT32_MIN;
                    }
                    ret = ret * 10 - (str[i] - '0');
                }
                return ret;
            }

        } else if (it == ' ') {
            if (sig != ' ') {
                return 0;
            }
            continue;
        } else if (it == '-') {
            if (sig == ' ') {
                sig = '-';
            } else {
                return 0;
            }
        } else if (it == '+') {
            if (sig == ' ') {
                sig = '+';
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 0;
}

int main() {
    vector<string> testdata = {"42", "   -42", "4193 with words",
                               "words and 987"};
    for (string it : testdata) {
        cout << myAtoi(it) << endl;
    }
}