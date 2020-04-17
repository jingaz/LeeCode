#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) {
    if(word1.empty()){
      return word2.size();
    }
    if(word2.empty()){
      return word1.size();
    }
    if (word1.size() < word2.size()) {
        swap(word1, word2);
    }
    int n1 = word1.size(), n2 = word2.size();
    int *dp_old = new int[n2+1];
    int *dp_new = new int[n2+1];
    //dp[j]表示 word2前j个字符和分别和 word1 以第 0 ~ n1-1 个字符结尾的子串编辑距离
    for (int j = 0; j <= n2; j++) {
        dp_old[j] = j;
    }
    for (int i = 0; i < n1; i++) {
        dp_new[0] = i+1;
        for (int j = 0; j < n2; j++) {
            if (word1[i] == word2[j]) {
                dp_new[j+1] = dp_old[j];
            } else {
                dp_new[j+1] =
                    min(min(dp_new[j], dp_old[j+1]), dp_old[j]) + 1;
            }
        }
        swap(dp_old, dp_new);
    }
    int ret = dp_old[n2];
    delete[] dp_old;
    delete[] dp_new;
    dp_new = nullptr;
    dp_new = nullptr;
    return ret;
}

struct testdata {
    string word1;
    string word2;
    int ret;
};

int main() {
    vector<testdata> data = {
        {"horse", "ros", 3},
        {"intention", "execution", 5},
        {"a","a", 0},
    };
    for (auto it : data) {
        int ans = minDistance(it.word1, it.word2);
        if (ans != it.ret) {
            cout << it.word1 << " --> " << it.word2 << "ret = " << it.ret
                 << " ans = " << ans << endl;
        }
    }
}