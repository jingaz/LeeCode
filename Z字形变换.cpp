
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct testdata {
    string str;
    int numRows;
};

string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    
    vector<string> rows(min(numRows, int(s.size())));
    int cur_row = 0;
    bool going_down = false;
    for (char ch : s) {
        rows[cur_row] += ch;
        if(cur_row==0||cur_row==numRows-1){
          going_down = !going_down;
        }
        cur_row += going_down ? 1 : -1;
    }

    string result = "";
    for(string row: rows){
      result += row;
    }
    return result;
}

int main() {
    vector<testdata> s = {{"LEETCODEISHIRING", 3}, {"LEETCODEISHIRING", 4}};
    for (auto it : s) {
        cout << convert(it.str, it.numRows) << endl;
    }
}