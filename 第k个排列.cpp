#include <algorithm>
#include <cmath> //pow的头文件
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getPermutation(int n, int k) {
    //康托展开逆运算
    static const int FAC[] = {1,   1,   2,    6,     24,
                              120, 720, 5040, 40320, 362880}; // 阶乘
    k--;
    vector<int> v; // 存放当前可选数
    string a; // 所求排列组合
    for (int i = 1; i <= n; i++)
        v.push_back(i);
    for (int i = n; i >= 1; i--) {
        int r = k % FAC[i - 1];
        int t = k / FAC[i - 1];
        k = r;
        sort(v.begin(), v.end());    // 从小到大排序
        a.push_back(v[t] - 1 + '1'); // 剩余数里第t+1个数为当前位
        v.erase(v.begin() + t);      // 移除选做当前位的数
    }
    return a;
}

int main() {
    vector<vector<int>> testdata = {
        {5, 96}, {3, 3},
        {1,1},
    };
    for (auto it : testdata) {
        cout << getPermutation(it[0], it[1]) << endl;
    }
}