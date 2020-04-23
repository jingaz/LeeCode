#include <iostream>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
    int ret = 0;
    heights.emplace_back(0);
    vector<int> index;
    for (int i = 0; i < heights.size(); i++) {
        while (!index.empty() && heights[index.back()] >= heights[i]) {
            int h = heights[index.back()];
            index.pop_back();
            int sidx = index.empty() ? -1 : index.back();
            ret = max(ret, h * (i - sidx - 1));
        }
        index.emplace_back(i);
    }
    return ret;
}
int maximalRectangle(vector<vector<char>> &matrix) {
    if(matrix.empty()){
      return 0;
    }
    int ret = 0;
    int M = matrix.size();
    int N = matrix.front().size();
    vector<int> tmp(N, 0);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == '1') {
              tmp[j] = tmp[j] + 1;
            }
            else{
              tmp[j] = 0;
            }
        }
        ret = max(ret, largestRectangleArea(tmp));
    }
    return ret;
}
int main() {
    vector<vector<char>> testdata = {{'1', '0', '1', '0', '0'},
                                     {'1', '0', '1', '1', '1'},
                                     {'1', '1', '1', '1', '1'},
                                     {'1', '0', '0', '1', '0'}};

    cout << maximalRectangle(testdata) << endl;
}