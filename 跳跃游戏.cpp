#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums) {
    if (nums.size() == 1)
        return true;
    int max_index = nums[0], index = 0;
    while (index < nums.size()-1) {
        int j = index;
        for (; j <= max_index; j++) {
            if (j + nums[j] >= max_index) {
                max_index = j + nums[j];
                index = j;
                if (j >= nums.size() - 1) {
                    return true;
                }
                if(j==max_index){
                  return false;
                }
            }
        }
    }
    return true;
}
int main() {
    vector<vector<int>> testdata = {{2,0}};
    for (auto it : testdata) {
        cout << canJump(it) << endl;
    }
}