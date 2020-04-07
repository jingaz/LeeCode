#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &height) {
    if (height.size() < 2) {
        return 0;
    }
    vector<int> dp(height.size(), 0);
    int max_index = height[0] > height[1] ? 0 : 1;
    int max_height = max(height[0], height[1]);

    for (int i = 2; i < height.size(); i++) {
        if (height[i] <= height[i - 1]) {
            dp[i] = dp[i - 1];
            continue;
        } else if (height[i] < max_height) {
            int area = 0;
            int j;
            for (j = i - 1; height[i] > height[j]; j--) {
                area += height[i] - height[j];
            }
            dp[i] = dp[j] + area;
        } else {
            int area = 0;
            int j;
            for (j = max_index + 1; j < i; j++) {
                area += max_height - height[j];
            }
            dp[i] = dp[max_index] + area;
            max_index = i;
            max_height = height[i];
        }
    }
    return dp.back();
}

int main() {
    vector<vector<int>> testdata = {
        {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
    };
    for (auto it : testdata) {
        cout << trap(it) << endl;
    }
}