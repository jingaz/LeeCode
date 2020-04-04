#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool check(int start, int len_sub, const int len_word, string s,
           unordered_map<string, int> dict) {
    cout << "check for : " << s.substr(start, len_sub) << endl;
    for (int i = 0; i < len_sub; i += len_word) {

      string sub_s_word = s.substr(start + i, len_word);
      if (dict.find(sub_s_word) != dict.end() && dict[sub_s_word] > 0) {
        dict[sub_s_word]--;
      } else {
        return false;
        }
    }
    cout << "true for : " << s.substr(start, len_sub) << endl;
    return true;
}

vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> ret;
    if (s.empty() || words.empty() || words.front().empty()) {
        return ret;
    }
    const int len_word = words.front().size();
    int len_worlds = words.size();
    int len_s = s.size();
    int len_sub = len_word * len_worlds;
    if (len_s < len_sub) {
        return ret;
    }

    unordered_map<string, int> dict;
    for (string word : words) {
        if (dict.find(word) != dict.end()) {
            dict[word]++;
        } else {
            dict[word] = 1;
        }
    }
    for (int i = 0; i <= len_s - len_sub; i++) {
        if (check(i, len_sub, len_word, s, dict)) {
            ret.push_back(i);
        }
    }

    return ret;
}

void print_ans(vector<int> ans) {
    for (int i : ans) {
        cout << i << ", ";
    }
}
struct test_data {
    string s;
    vector<string> str;
};

template <typename T> void ans_print(T ans) {
    for (auto it : ans) {
        cout << it << ", ";
    }
}

int main() {
    vector<test_data> testdata = {
        {"wordgoodgoodgoodbestword", {"word", "good", "best", "good"}},
    };
    for (auto it : testdata) {
        cout << "[  ";
        print_ans(findSubstring(it.s, it.str));
        cout << "\b\b  ]" << endl;
    }
}