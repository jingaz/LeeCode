#include <iostream>
#include <vector>
using namespace std;
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    string str = to_string(x);
    for (int i = 0, j = str.size() - 1; i <= j; i++, j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> testdata = {121, -121, 10, +101};
    for (int i : testdata) {
        cout << i << "  " << isPalindrome(i) << endl;
    }
}