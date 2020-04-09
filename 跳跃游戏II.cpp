#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> &nums) {
    if (nums.size()==1)
        return 0;
    int max_index = nums[0], count = 1,left=0;
    for (int i = 0; i < nums.size(); i = left) {
        if (max_index >= nums.size() - 1) {
            return count;
        }
        int tmp = max_index;
        
        for (int j=i; j <= tmp; j++) {
            if(j+nums[j]>=max_index){
              max_index = j + nums[j];
              left = j;
            }
        }
        count++;
    }
    return count;
}

int main() {
    vector<vector<int>> testdata = {
        {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0},
    };
    for (auto it : testdata) {
        cout << jump(it) << endl;
    }
}