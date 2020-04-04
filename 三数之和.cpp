#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct KEY {
    int first;
    int second;
    int third;
    KEY(int f, int s, int t) : first(f), second(s), third(t) {}
};
struct HashFunc  
{  
    std::size_t operator()(const KEY &key) const   
    {  
        using std::size_t;  
        using std::hash;  
  
        return ((hash<int>()(key.first)  
            ^ (hash<int>()(key.second) << 1)) >> 1)  
            ^ (hash<int>()(key.third) << 1);  
    }  
};  
struct EqualKey {
    bool operator()(const KEY &lhs, const KEY &rhs) const {
        return lhs.first == rhs.first && lhs.second == rhs.second &&
               lhs.third == rhs.third;
    }
};

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ret;
    if (nums.size() < 3) {
        return ret;
    }

    // 将nums信息存入dict
    unordered_map<int, int> dict;
    for (int item : nums) {
        if (dict.find(item)!=dict.end()) {
            dict[item]++;
        } else {
            dict[item] = 0;
        }
    }
    unordered_map<KEY, bool, HashFunc, EqualKey> hash_ret;
    // 2次遍历dict
    unordered_map<int, int>::iterator iter1, iter2, iter3;
    for (iter1 = dict.begin(); iter1 != dict.end(); iter1++) {
        int a = iter1->first;
        iter1->second--;
        for (iter2 = iter1; iter2 != dict.end(); iter2++) {
            if (iter2->second < 0) {
                continue;
            }
            int b = iter2->first;
            iter2->second--;
            int c = -a - b;
            iter3 = dict.find(c);
            if (iter3 != dict.end()) {
                if (iter3->second >= 0) {
                    int i = min(min(a, b), c);
                    int k = max(max(a, b), c);
                    int j = a + b + c - i - k;
                    KEY key(i, j, k);
                    if (hash_ret.find(key) == hash_ret.end()) {
                        hash_ret[key] = true;
                        ret.push_back(vector<int>{i, j, k});
                    }
                }
            }
            iter2->second++;
        }
        iter1->second++;
    }

    return ret;
}

void myprint(vector<vector<int>> ans) {
    cout << "\n\n";
    for (auto it : ans) {
        cout << "[ ";
        for (int i : it) {
            cout << i << ", ";
        }
        cout << "\b\b ]" << endl;
    }
}
int main() {
    vector<vector<int>> testdata = {
        {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0},
        {-1, 0, 1, 2, -1, -4},
        {-4, -2, 0, 2, 4}};
    for (auto it : testdata) {
        myprint(threeSum(it));
    }
}