#include <iostream>
#include <vector>
using namespace std;
int largest(vector<int> &heights, int left, int right) {
    if (right < left) {
        return 0;
    }
    if (right == left) {
        return heights[left];
    }
    int min_height = heights[left];
    int min_index = left;
    for (int i = left; i <= right; i++) {
        if (min_height > heights[i]) {
            min_index = i;
            min_height = heights[i];
        }
    }
    return max(max(largest(heights, left, min_index - 1),
                   largest(heights, min_index + 1, right)),
               (right - left + 1) * min_height);
}
int largestRectangleArea(vector<int> &heights) {
    if (heights.empty()) {
        return 0;
    }
    return largest(heights, 0, heights.size() - 1);
}

int main() {
    vector<vector<int>> testdata = {
        {2, 1, 5, 6, 2, 3}, {1, 1, 1, 1, 1}, {}, {1, 2, 3, 4, 5, 6}};
    for (auto it : testdata) {
        cout << largestRectangleArea(it) << endl;
    }
}