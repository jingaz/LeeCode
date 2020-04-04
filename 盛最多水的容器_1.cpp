#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height) {
    if (height.size() == 2) {
        return min(height[0], height[1]);
    }

    int i = 0, j = height.size() - 1;
    int max_area = min(height[i], height[j]) * (j - i);

    while (i < j) {
        if(height[i]<height[j]){
            i++;
            int new_area = min(height[i], height[j]) * (j - i);
            max_area = max(new_area, max_area);
        }
        else{
            j--;
            int new_area = min(height[i], height[j]) * (j - i);
            max_area = max(new_area, max_area);
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