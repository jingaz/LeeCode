#include <iostream>
#include <vector>

using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    if (n == 0) {
        return false;
    }
    int m = matrix.back().size();
    int left = 0, right = n * m - 1;
    while (left <= right) {
        if (matrix[left / m][left % m] == target) {
            return true;
        }
        if (matrix[right / m][right % m] == target) {
            return true;
        }
        int mid = (left + right) / 2;
        if (matrix[mid / m][mid % m] == target) {
            return true;
        }
        if (matrix[mid / m][mid % m] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}
struct testdata {
    vector<vector<int>> matrix;
    int target;
};
int main() {
    vector<testdata> data = {
        {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}}, 3},
        {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}}, 13},
        {{}, 1}};
    for (auto it : data) {
        cout << boolalpha << searchMatrix(it.matrix, it.target) << endl;
    }
}