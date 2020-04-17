#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string simplifyPath(string path) {
    int i = 0, j = 0;
    if (path.empty()) {
        return path;
    }
    if (path.back() != '/') {
        path.push_back('/');
    }
    deque<string> que;
    while (j < path.size()) {
        if (i == j) {
            j++;
            while (j < path.size() && path[j] != '/') {
                j++;
            }
        }
        string word = path.substr(i + 1, j - i - 1);
        if (word == "..") {
            if (!que.empty()) {
                que.pop_back();
            }
        } else if (!word.empty() && word != ".") {
            que.push_back(word);
        }
        i = j;
    }
    string ret = "/";
    while (!que.empty()) {
        ret += que.front();
        que.pop_front();
        if (!que.empty()) {
            ret.push_back('/');
        }
    }
    return ret;
}

struct testdata {
    string path;
    string simplify_path;
};

int main() {
    vector<testdata> testdata = {
        {"/home/", "/home"},
        {"/../", "/"},
        {"/home//foo/", "/home/foo"},
        {"/a/./b/../../c/", "/c"},
        {"/a/../../b/../c//.//", "/c"},
        {"/a//b////c/d//././/..", "/a/b/c"},
        {"/./././.", "/"},
        {"/...", "/..."},
        {"/", "/"},
    };
    for (auto it : testdata) {
        cout << it.path << "  ";
        string ret = simplifyPath(it.path);
        if (ret != it.simplify_path) {
            cout << ret << "  ans= " << it.simplify_path << endl;
        }
        cout << endl;
    }
}