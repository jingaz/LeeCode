#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int longestValidParentheses(string s) {
    if (s.size() < 2)
        return 0;
    int max_length = 0;
    vector<int> dp(s.size());

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
              int tmp = i - 2 >= 0 ? dp[i - 2] : 0;
              dp[i] = 2 + tmp;
              max_length = max(max_length, dp[i]);
              //cout << " dp[" << i << "] = " << dp[i];
            }
            if(s[i-1]==')'){
              if(i>dp[i-1]){
                int tmp = i - 1 - dp[i - 1];
                if(tmp>=0&&s[tmp]=='('){
                  int tmp2 = tmp - 1 >= 0 ? tmp - 1 : 0;
                  dp[i] = 2 + dp[i - 1] + dp[tmp2];
                  max_length = max(max_length, dp[i]);
                  //cout << " dp[" << i << "] = " << dp[i];
                }
              }
            }
        }
    }
    return max_length;
}

int main() {
    vector<string> testdata = {
        "()(())",
    };
    for (string s : testdata) {
        cout << longestValidParentheses(s) << endl;
    }
}