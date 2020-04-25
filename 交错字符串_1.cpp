#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int l1 = s1.size();
    int l2 = s2.size();
    int l3 = s3.size();
    if (l3 != l1 + l2) {
        return false;
    }
    vector<bool> dp(l2 + 1, false);
    dp[0] = true;
    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            if (i > 0 && s1[i - 1] != s3[i + j - 1]) {
                dp[j] = false;
            }
            if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                dp[j] = dp[j - 1]||dp[j];
            }
        }
    }
    return dp[l2];
}

int main() {
    vector<vector<string>> testdata = {
        {"aabcc", "dbbca", "aadbbcbcac"},
        {"aabcc", "dbbca", "aadbbbaccc"},
    };
    for (auto it : testdata) {
        cout << boolalpha << isInterleave(it[0], it[1], it[2]) << endl;
    }
}