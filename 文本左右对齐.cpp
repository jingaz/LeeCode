#include <iostream>
#include <string>
#include <vector>

using namespace std;

void justify(string &str, int space, int maxWidth) {
    int need_space = maxWidth - str.size();
    if (space == 0) {
        str += string(maxWidth - str.size(), ' ');
        return;
    }
    int add_space = need_space / space;
    int rest_space = need_space % space;
    int index = 0;
    for (int count = 0; count < space;) {
        if (index < str.size() && str[index++] == ' ') {
            if (count < rest_space) {
                str.insert(index, string(add_space + 1, ' '));
                index += add_space + 1;
            } else {
                str.insert(index, string(add_space, ' '));
                index += add_space;
            }
            count++;
        }
    }
}

vector<string> fullJustify(vector<string> &words, int maxWidth) {
    string s = "";
    int space = 0;
    for (int i = 0; i < words.size(); i++) {
        string tmp;
        if (!s.empty()) {
            tmp = s + " " + words[i];
            space++;
        } else {
            tmp = words[i];
            s = tmp;
            space = 0;
        }

        if (tmp.size() == maxWidth) {
            words[i] = tmp;
            s.clear();
        } else if (tmp.size() > maxWidth) {
            swap(words[i], s);
            justify(words[i], space - 1, maxWidth);
            space = 0;
        } else {
            s = tmp;
            words.erase(words.begin() + i);
            i--;
        }
    }
    if (!s.empty()) {
        s += string(maxWidth - s.size(), ' ');
        words.push_back(s);
    }    
    return words;
}

struct testdata {
    vector<string> words;
    int maxWidth;
};

void print_ret(vector<string> ret) {
    cout << "[" << endl;
    for (string str : ret) {
        cout << "  \"" << str << "\"," << endl;
    }
    cout << "]" << endl;
}

int main() {
    vector<testdata> data = {
        {{"a"},1},
        {{"This", "is", "an", "example", "of", "text", "justification."}, 16},
        {{"What", "must", "be", "acknowledgment", "shall", "be"}, 16},
        {{"Science", "is", "what", "we", "understand", "well", "enough", "to",
          "explain", "to", "a", "computer.", "Art", "is", "everything", "else",
          "we", "do"},
         20},
         
    };
    for (auto it : data) {
        print_ret(fullJustify(it.words, it.maxWidth));
    }
}