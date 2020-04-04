#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isValid(string s) {
    if (s.empty()) {
        return true;
    }
    stack<char> char_stack;

    for (char ch : s) {
        switch (ch) {
        case ')':
            if (char_stack.empty()) {
                return false;
            }
            if (char_stack.top() == '(') {
                char_stack.pop();
            } else {
                return false;
            }
            break;
        case ']':
            if (char_stack.empty()) {
                return false;
            }
            if (char_stack.top() == '[') {
                char_stack.pop();
            } else {
                return false;
            }
            break;
        case '}':
            if (char_stack.empty()) {
                return false;
            }
            if (char_stack.top() == '{') {
                char_stack.pop();
            } else {
                return false;
            }
            break;
        default:
            char_stack.push(ch);
            break;
        }
    }

    return char_stack.empty();
}

int main() {
    vector<string> testdate = {
        "()", "()[]{}", "(]", "([)]", "{[]}",
    };
    for (string it : testdate) {
        cout << isValid(it) << endl;
    }
}