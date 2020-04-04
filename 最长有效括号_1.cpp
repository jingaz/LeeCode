#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int longestValidParentheses(string s) {
    if(s.size()<2){
        return 0;
    }
    if(s.back()=='('){
        s.pop_back();
        return longestValidParentheses(s);
    }
    int LONGEST = 0, left = 0, right = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left > right) {
            s.pop_back();
            LONGEST =  max(LONGEST, longestValidParentheses(s));
        } else if (left == right) {
            LONGEST = left * 2;
        }
    }
    s.pop_back();
    return max(LONGEST, longestValidParentheses(s));
}

int main() {
    vector<string> testdata = {"((()))())"};
    for (string s : testdata) {
        cout << longestValidParentheses(s) << endl;
    }
}