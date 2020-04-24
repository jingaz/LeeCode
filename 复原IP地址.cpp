#include <iostream>
#include <vector>
using namespace std;

vector<string> ret;

void dfs(string s, int cnt, string ip) {
    if (cnt == 4) {
        if (s.empty()) {
            ret.emplace_back(ip);
        }
        return;
    }
    for (int k = 1; k < 4; k++) {
        if (s.size() < k)
            break;
        int val = stoi(s.substr(0, k));
        if (val > 255 || k != to_string(val).size())
            continue;
        dfs(s.substr(k), cnt + 1, ip + s.substr(0, k) + (cnt == 3 ? "" : "."));
    }    
}

vector<string> restoreIpAddresses(string s) {
    string ip;
    dfs(s, 0, ip);
    return ret;
}
void print_ret(vector<string> ret) {
    cout << "  [  ";
    for (auto i : ret) {
        cout << i << ", ";
    }
    cout << "\b\b  ]" << endl;
}
int main() {
    vector<string> testdata = {
        "25525511135",
    };
    for (auto &i : testdata) {
        ret.clear();
        print_ret(restoreIpAddresses(i));
    }
}