#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
struct tree_node {
    char val;  //结点存 '(' 或  ')'
    int left;  //根节点至当前结点中 '('的数目
    int right; //根节点至当前结点中 ')'的数目
    tree_node *l_child; //两个分支结点表示后续有 '(' 和 ')' 两种可能情况
    tree_node *r_child;
    tree_node *father; //保存父节点指针是为了便于回溯正确结果
    tree_node(char ch, int l, int r, tree_node *father_node)
        : val(ch), left(l), right(r), l_child(nullptr), r_child(nullptr),
          father(father_node) {}
    ~tree_node() {
        if (l_child != nullptr) {
            delete l_child;
        }
        if (r_child != nullptr) {
            delete r_child;
        }
        delete this;
    }
};

vector<string> generateParenthesis(int n) {
    vector<string> ret;
    if (n <= 0) {
        return ret;
    }
    tree_node *root = new tree_node('(', 1, 0, nullptr);
    stack<tree_node *> node_stack;
    node_stack.push(root);
    stack<tree_node *> ans_stack;
        while (!node_stack.empty()) {
      tree_node *node = node_stack.top();
      node_stack.pop();
      if (node->left >= node->right) {
        if (node->left < n) {
          node->l_child = new tree_node('(', node->left + 1, node->right, node);
          node_stack.push(node->l_child);
        }
        if (node->right < n && node->right < node->left) {
          node->r_child = new tree_node(')', node->left, node->right + 1, node);
          node_stack.push(node->r_child);
        }
        if (node->left == n && node->right == n) {
          ans_stack.push(node);
        }
      }
    }
    while (!ans_stack.empty()) {
        string s;
        tree_node *tmp = ans_stack.top();
        ans_stack.pop();
        do {
            s.push_back(tmp->val);
            tmp = tmp->father;
        } while (tmp != nullptr);
        reverse(s.begin(), s.end());
        ret.push_back(s);
    }
    return ret;
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