#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> func(vector<string> &ret, string s, int l, int r, int n) {

    if (l > n || r > n || r > l) {
        vector<string> empty;
        return empty;
    }
    if (l == n && r == n) {
        ret.push_back(s);
        return ret;
    }
    if(l<n&&l>=r){
      ret = func(ret, s + "(", l + 1, r, n);
    }
    if(r<n&&r<l){
      return func(ret, s + ")", l, r + 1, n);
    }
    return ret;
}

vector<string> generateParenthesis(int n) {
    vector<string> ret;
    return func(ret, "", 0, 0, n);
}

int main() {
    for (int i = 0; i < 6; i++) {
        cout << "n=" << i << endl;
        for (string s : generateParenthesis(i)) {
            cout << s << "   ";
        }
        cout << endl;
    }
}