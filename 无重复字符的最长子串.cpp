#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.size() < 2) {
        return s.size();
    }
    int strmap[256] = {0};
    int max_length = 0;
    for (int fore = 0, back = 0; back < s.size();) {
        if (strmap[s[back]] != 0) {
            int i = fore;
            fore = strmap[s[back]];
            for (; i < fore; i++) {
              strmap[s[i]] = 0;
            }
            strmap[s[back]] = 0;

        } else {
            strmap[s[back]] = back + 1;
            max_length =
                back - fore + 1 > max_length ? back - fore + 1 : max_length;
            back++;
        }
    }
    return max_length;
}

int main() {
    vector<string> s = {"fdawegwafsdafew", "fewffewfdsafd", "fewfdswefr",
                        "fewfewewf"};
    for (auto it : s) {
        cout << lengthOfLongestSubstring(it) << endl;
    }
}