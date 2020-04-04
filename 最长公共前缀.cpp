#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) {
        return "";
    }
    string s = strs.front();
    for (string it : strs) {
        if (it.empty()) {
            return "";
        }
        int min_length = min(it.size(), s.size());
        for (int i = 0; i < min_length; i++) {
            if (it[i] != s[i]) {
                s = s.substr(0, i);
                break;
            }
            if(i==min_length-1){
              s = s.substr(0, min_length);
            }
        }
    }
    return s;
}
int main() {
    vector<vector<string>> testdata = {
        {"flower", "flow", "flight"},
        {"aa", "a"},
        {"deafew", "deafgwef", "deafugr", "deabfe", "dea"},
    };
    for (auto it : testdata) {
        cout << longestCommonPrefix(it) << endl;
    }
}