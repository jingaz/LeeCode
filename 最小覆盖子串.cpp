#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> hashmap;
    for (auto c : t) {
        hashmap[c]++;
    }
    int cnt = hashmap.size();
    string res;
    for (int i = 0, j = 0, c = 0;i<s.size();i++){
        if(hashmap[s[i]]==1){
            c++;
        }
        hashmap[s[i]]--;
        while(hashmap[s[j]]<0){
           hashmap[s[j++]]++;
        }
        if(c==cnt){
            if(res.empty()|| res.size()>i-j+1){
              res = s.substr(j, i - j + 1);
            }
        }
    }
    return res;
}

int main() {
    vector<vector<string>> testdata = {
        {"ADOBECODEBANC", "ABC"},
        {"a", "aa"},
        {"bbaa", "aba"},
    };
    for (auto it : testdata) {
        cout << minWindow(it[0], it[1]) << endl;
    }
}