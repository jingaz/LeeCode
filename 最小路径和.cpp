#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid) {
    if (grid.empty()) {
        return 0;
    }
    const int x = grid.size(), y = grid.front().size();
    for (int j = 1; j < y; j++) {
        grid[0][j] += grid[0][j - 1];
    }
    for (int i = 1; i < x; i++) {
        grid[i][0] += grid[i - 1][0];
    }
    for (int i = 1; i < x; i++) {
        for (int j = 1; j < y; j++) {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[x - 1][y - 1];
}

int main() {
    vector<vector<vector<int>>> testdata = {
        {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}},
    };
    for (auto it : testdata) {
        cout << minPathSum(it) << endl;
    }
}