#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int numTrees(int n) {
    if(n==1)return 1;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp.back();
}

struct testdata {
    int n;
    int ans;
};

int main() {
    vector<testdata> data = {
        {3, 5},
    };
    for (auto it : data) {
        if (it.ans != numTrees(it.n)) {
            cout << it.n << " " << it.ans << "  wrong_ans = " << numTrees(it.n)
                 << endl;
        }
    }
}