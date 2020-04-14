#include <iostream>
#include <string>
#include <vector>

using namespace std;
int lengthOfLastWord(string s) {
    string::reverse_iterator iter = s.rbegin();
    int max_word_length = 0;
    while (iter != s.rend()) {
        if (*iter == ' ') {
            iter++;
            continue;
        }
        while (iter != s.rend() && *iter != ' ') {
            max_word_length++;
            iter++;
        }
        return max_word_length;
    }
    return max_word_length;
}

int main() {
    vector<string> testdata = {
        "hello helloworld w ",
    };
    for (string s : testdata) {
        cout << lengthOfLastWord(s) << endl;
    }
}