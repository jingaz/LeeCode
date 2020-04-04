#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int reverse(int x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    if(x<0){
      s = "-" + s;
    }
    try {
      return stoi(s);
    } catch (...) {
      return 0;
    }
}
int main() {
    vector<int> testdata = {123, 23556, -89, 9876531,1534236469};
    for (int i : testdata) {
        cout << "before: " << i << "  after: " << reverse(i) << endl;
    }
}