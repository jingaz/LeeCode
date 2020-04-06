#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;
void print_Sudoku(vector<vector<char>> &);

struct statue {
    vector<unordered_set<char>> row;
    vector<unordered_set<char>> col;
    vector<unordered_set<char>> block;
    vector<vector<char>> board;

    statue(vector<unordered_set<char>> r, vector<unordered_set<char>> c,
           vector<unordered_set<char>> b, vector<vector<char>> bo)
        : row(r), col(c), block(b), board(bo) {}
};

bool resolve(stack<statue> &status) {

    statue current = status.top();
    status.pop();

scanning:
    vector<statue> tmp_status;
    bool ans = true;
    int min_option = 10;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (current.board[i][j] == '.') {
                vector<char> val;
                for (char c = '1'; c <= '9'; c++) {
                    if (!(current.row[i].count(c) || current.col[j].count(c) ||
                          current.block[i / 3 * 3 + j / 3].count(c))) {
                        val.push_back(c);
                    }
                }
                if (val.size() == 1) {
                    char val_elem = val.back();
                    current.board[i][j] = val_elem;
                    current.row[i].insert(val_elem);
                    current.col[j].insert(val_elem);
                    current.block[i / 3 * 3 + j / 3].insert(val_elem);
                    goto scanning;
                    // 一个无效状态
                } else if (val.empty()) {
                    return false;
                } else {
                    if (val.size() < min_option) {
                        min_option = val.size();
                        tmp_status.clear();
                        for (char it : val) {
                            statue new_statu = current;
                            new_statu.row[i].insert(it);
                            new_statu.col[j].insert(it);
                            new_statu.block[i / 3 * 3 + j / 3].insert(it);
                            new_statu.board[i][j] = it;
                            tmp_status.push_back(new_statu);
                        }
                    }

                    ans = false;
                }
            }
        }
    }

    if (ans) {
        status.push(current);
        return true;
    }
    
    while (!tmp_status.empty()) {
        statue sta = tmp_status.back();
        tmp_status.pop_back();
        status.push(sta);
        if (resolve(status)) {
            return true;
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board) {

    vector<unordered_set<char>> row(9);
    vector<unordered_set<char>> col(9);
    vector<unordered_set<char>> block(9);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                // set(pos) 把在pos处的二进制位置为1
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                block[i / 3 * 3 + j / 3].insert(board[i][j]);
            }
        }
    }
    stack<statue> status;
    status.push(statue(row, col, block, board));
    if (resolve(status)) {
        board = status.top().board;
    }
}

void print_Sudoku(vector<vector<char>> &board) {
    cout << "_____________________________________" << endl;
    for (auto it : board) {
        cout << "|";
        for (char i : it) {
            cout << " " << i << " |";
        }
        cout << endl;
    }
    cout << "-------------------------------------" << endl;
}

int main() {
    vector<vector<char>> board = {
        {'.', '.', '.', '2', '.', '.', '.', '6', '3'},
        {'3', '.', '.', '.', '.', '5', '4', '.', '1'},
        {'.', '.', '1', '.', '.', '3', '9', '8', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '9', '.'},
        {'.', '.', '.', '5', '3', '8', '.', '.', '.'},
        {'.', '3', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '2', '6', '3', '.', '.', '5', '.', '.'},
        {'5', '.', '3', '7', '.', '.', '.', '.', '8'},
        {'4', '7', '.', '.', '.', '1', '.', '.', '.'}};

    print_Sudoku(board);
    solveSudoku(board);
    print_Sudoku(board);
}