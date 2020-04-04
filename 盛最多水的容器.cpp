#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height) {
    int max_area = 0;
    int big_index = 0;
    for (int i = 0; i < height.size(); i++) {

        if (i > big_index) {
            vector<int>::iterator biggest =
                max_element(height.begin() + i + 1, height.end());
            big_index = distance(height.begin(), biggest);
        }

        for (int j = big_index; j < height.size(); j++) {
            int tmp_area = (j - i) * min(height[i], height[j]);
            max_area = max(max_area, tmp_area);
        }
    }
    return max_area;
}

int main() {
    vector<vector<int>> testdata = {{1, 8, 6, 2, 5, 4, 8, 3, 7},
                                    {1, 3, 7, 5, 9, 4},
                                    {3, 5, 7, 4, 5},
                                    {2, 6, 8, 4, 1}};
    for (auto it : testdata) {
        cout << maxArea(it) << endl;
    }
}