#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ret;
    unordered_map<string, int> ret_map;
    if (strs.empty()) {
        return ret;
    }
    int index = 0;
    for (string str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      if (ret_map.count(key)) {
        ret[ret_map[key]].push_back(str);
      } else {
        ret_map[key] = index;
        ret.push_back(vector<string>(1, str));
        index++;
      }
    }
    return ret;
}

void print_ret(vector<vector<string>> ret) {
    cout << "[" << endl;
    for (auto it : ret) {
        cout << "  [ ";
        for (auto i : it) {
            cout << i << ", ";
        }
        cout << "\b\b ]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    vector<vector<string>> testdata = {
        {"eat", "tea", "tan", "ate", "nat", "bat"},

    };
    for (auto it : testdata) {
        print_ret(groupAnagrams(it));
    }
}