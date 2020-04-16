#include <iostream>
#include <vector>

using namespace std;
int climbStairs(int n) {
    int pre1 = 1;
    int pre2 = 2;
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    int pre3 = 0;
    for (int i = 3; i <= n; i++) {
      pre3 = pre1 + pre2;      
      pre1 = pre2;
      pre2 = pre3;
    }
    return pre3;
}

int main() {
    vector<int> testdata = {1, 2, 3, 4, 5, 10, 20, 30};
    for (int i : testdata) {
        cout << climbStairs(i) << endl;
    }
}