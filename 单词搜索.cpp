#include <iostream>
#include <vector>
using namespace std;
int M, N;
bool dfs(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &used,
         string word) {
    if (word.empty()) {
        return true;
    }
    char a = word.front();
    word.erase(word.begin());
    if (i + 1 < M) {
        if (!used[i + 1][j] && board[i + 1][j] == a) {
            used[i + 1][j] = true;
            if (dfs(i + 1, j, board, used, word)) {
                return true;
            }
            used[i + 1][j] = false;
        }
    }
    if (i - 1 >= 0) {
        if (!used[i - 1][j] && board[i - 1][j] == a) {
            used[i - 1][j] = true;
            if (dfs(i - 1, j, board, used, word)) {
                return true;
            }
            used[i - 1][j] = false;
        }
    }
    if (j + 1 < N) {
        if (!used[i][j + 1] && board[i][j + 1] == a) {
            used[i][j + 1] = true;
            if (dfs(i, j + 1, board, used, word)) {
                return true;
            }
            used[i][j + 1] = false;
        }
    }
    if (j - 1 >= 0) {
        if (!used[i][j - 1] && board[i][j - 1] == a) {
            used[i][j - 1] = true;
            if (dfs(i, j - 1, board, used, word)) {
                return true;
            }
            used[i][j - 1] = false;
        }
    }
    return false;
}

bool exist(vector<vector<char>> &board, string word) {
    M = board.size();
    N = board.front().size();
    vector<vector<bool>> used(M, vector<bool>(N, false));
    if (word.empty()) {
        return true;
    }
    if (word.size() > M * N) {
        return false;
    }
    char a = word.front();
    word.erase(word.begin());
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!used[i][j] && board[i][j] == a) {
                used[i][j] = true;
                if (dfs(i, j, board, used, word)) {
                    return true;
                }
                used[i][j] = false;
            }
        }
    }
    return false;
}

struct testdata {
    vector<vector<char>> board;
    string word;
};
int main() {
    vector<testdata> data = {
        {{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
         "ABCCED"},
        {{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
         "SEE"},
        {{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
         "ABCB"},
        {{{'a', 'a'}}, "aaa"}};
    for (auto it : data) {
        cout << boolalpha << exist(it.board, it.word) << endl;
    }
}