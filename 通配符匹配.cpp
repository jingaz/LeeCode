#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    if (p.empty() && s.empty())
        return true;
    if (p.empty()) {
        return false;
    }
    if (s.empty()) {
        for (char c : p) {
            if (c != '*') {
                return false;
            }
        }
    }
    int s_size = s.size();
    int p_size = p.size();
    vector<vector<bool>> dp(s_size + 1, vector<bool>(p_size + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= p_size; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = true;
        } else {
            break;
        }
    }
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= p.size(); j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
            } else if (p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
            }
        }
    }
    return dp[s_size][p_size];
}

int main() {
    vector<vector<string>> testdata = {
        {"efff", "eff*f"},
    };
    for (auto it : testdata) {
        cout << isMatch(it[0], it[1]) << endl;
    }
}