#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid.empty()) {
        return 0;
    }
    
    int i = 0, j = 0;
    if (obstacleGrid[0][0] == 0) {
        obstacleGrid[i][j] = 1;
    } else {
        return 0;
    }
    const int x = obstacleGrid.size(), y = obstacleGrid.front().size();
    vector<vector<int64_t>> obs(x, vector<int64_t>(y, 1));

    bool flag = true;
    for (int j = 1; j < y; j++) {
        if (obstacleGrid[0][j] == 0 && flag) {
            obs[0][j] = 1;
        } else {
            obs[0][j] = 0;
            flag = false;
        }
    }
    flag = true;
    for (int i = 1; i < x; i++) {
        if (obstacleGrid[i][0] == 0 && flag) {
            obs[i][0] = 1;
        } else {
            obs[i][0] = 0;
            flag = false;
        }
    }
    for (int i = 1; i < x; i++) {
        for (int j = 1; j < y; j++) {
            if (obstacleGrid[i][j] == 0) {
                obs[i][j] =
                    obs[i - 1][j] + obs[i][j - 1];
            } else {
                obs[i][j] = 0;
            }
        }
    }
    return obs[x - 1][y - 1];
}

int main() {
    vector<vector<vector<int>>> testdata = {
        {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
    };
    for (auto it : testdata) {
        cout << uniquePathsWithObstacles(it) << endl;
    }
}