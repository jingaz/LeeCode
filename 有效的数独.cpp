#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;


bool isValidSudoku(vector<vector<char>> &board) {
    unordered_map<char, int> dict;
    for (int i = 0; i < 9; i++) {
        dict.clear();
        for (int j = 0; j < 9; j++) {
            if (dict.find(board[i][j]) != dict.end()) {
                if (board[i][j] == '.') {
                    continue;
                } else {
                    return false;
                }
            } else {
                dict[board[i][j]] = 1;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        dict.clear();
        for (int j = 0; j < 9; j++) {
            if (dict.find(board[j][i]) != dict.end()) {
                if (board[j][i] == '.') {
                    continue;
                } else {
                    return false;
                }
            } else {
                dict[board[j][i]] = 1;
            }
        }
    }
    for (int x = 0; x < 9; x += 3) {
        for (int y = 0; y < 9; y += 3) {
            dict.clear();
            for (int i = 0; i < 9; i++) {
                if (dict.find(board[x + i / 3][y + i % 3]) != dict.end()) {
                    if (board[x + i / 3][y + i % 3] == '.') {
                        continue;
                    } else {
                        return false;
                    }
                } else {
                    dict[board[x + i / 3][y + i % 3]] = 1;
                }
            }
        }
    }

    return true;
}
int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << isValidSudoku(board) << endl;
    vector<vector<char>> board1 = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << isValidSudoku(board1) << endl;
}