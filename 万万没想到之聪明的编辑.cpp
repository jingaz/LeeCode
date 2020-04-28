#include <iostream>
#include <string>
#include <vector>

using namespace std;

string repire(string s) {
    if (s.size() < 3) {
        return s;
    }
    char a = s[0], b = s[1];
    int i = 2;
    while (i < s.size()) {
        char c = s[i];
        if (a == b && b == c) {
            s.erase(i, 1);
            continue;
        }
        i++;
    check_d:
        if (i < s.size()) {
            char d = s[i];
            if (a == b && c == d) {
                s.erase(i, 1);
                goto check_d;
            }
        }
        a = b;
        b = c;
    }
    return s;
}
int main() {
    int N;
    cin >> N;
    while (N-- > 0) {
        string s;
        cin >> s;
        cout << repire(s) << endl;
    }
}