#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> char_stack;
    int LONGEST = 0;

    for (char c : s) {
        if (c == '(') {
            char_stack.push(0);
        }
        if (c == ')') {
            if (char_stack.empty()) {
                continue;
            }

            // 0 代表栈顶为 '('
            else if (char_stack.top() == 0) {
                char_stack.pop();
                // 栈顶为空或 '(' 则 2 入栈
                if (char_stack.empty() || char_stack.top() == 0) {
                    char_stack.push(2);
                }
                // 栈顶也是一个子串，则长度 +2
                else {
                    char_stack.top() += 2;
                }
            }
            // 栈顶是一个子串
            else {
                int longest_sub = char_stack.top();
                char_stack.pop();
                // 空栈和 ')', 不匹配 子串长度不能增加了
                if (char_stack.empty()) {
                    LONGEST = max(LONGEST, longest_sub);
                } else {
                    longest_sub += 2;
                    char_stack.pop();
                    if (char_stack.empty() || char_stack.top() == 0) {
                        char_stack.push(longest_sub);
                    } else {
                        char_stack.top() += longest_sub;
                    }
                }
            }
        }
    }
    while (!char_stack.empty()) {
        LONGEST = max(char_stack.top(), LONGEST);
        char_stack.pop();
    }
    return LONGEST;
}

int main() {
    vector<string> testdata = {"((()))())"};
    for (string s : testdata) {
        cout << longestValidParentheses(s) << endl;
    }
}