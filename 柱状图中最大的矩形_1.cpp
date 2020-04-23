#include <iostream>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
    int ret=0;
    heights.emplace_back(0);
    vector<int> index;
    for (int i = 0;i<heights.size();i++){
        while(!index.empty() && heights[index.back()]>=heights[i]){
            int h = heights[index.back()];
            index.pop_back();
            int sidx = index.empty() ? -1 : index.back();
            ret = max(ret, h * (i - sidx - 1));
        }
        index.emplace_back(i);
    }
    return ret;
}

int main() {
    vector<vector<int>> testdata = {
        {2, 1, 5, 6, 2, 3}, {1, 1, 1, 1, 1}, {}, {1, 2, 3, 4, 5, 6}};
    for (auto it : testdata) {
        cout << largestRectangleArea(it) << endl;
    }
}