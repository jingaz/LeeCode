#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void print_tree(TreeNode *&tree) {
    if (!tree) {
        cout << "null, ";
        return;
    }
    cout << tree->val << ", ";
    print_tree(tree->left);
    print_tree(tree->right);
}
void print_tree_format(TreeNode *&tree) {
    cout << "[  ";
    print_tree(tree);
    cout << "\b\b  ]" << endl;
}
TreeNode *create_tree(vector<int> nums) {
    if (nums.empty()) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(nums[0]);
    nums.erase(nums.begin());
    queue<TreeNode *> que;
    root->left = new TreeNode(-1);
    que.push(root->left);
    root->right = new TreeNode(-1);
    que.push(root->right);
    while (!nums.empty()) {
        TreeNode *tmp = que.front();
        que.pop();
        tmp->val = nums.front();
        nums.erase(nums.begin());
        if (tmp->val != -1) {
            tmp->left = new TreeNode(-1);
            que.push(tmp->left);
            tmp->right = new TreeNode(-1);
            que.push(tmp->right);
        }
    }
    return root;
}
void destroy_tree(TreeNode *&tree) {
    if (!tree) {
        return;
    }
    destroy_tree(tree->left);
    destroy_tree(tree->right);
    delete tree;
    tree = nullptr;
}
bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p) {
        return !q;
    }
    if (!q) {
        return !p;
    }
    if(p->val != q->val){
      return false;
    }
    if(!isSameTree(p->left, q->left)){
      return false;
    }
    if (!isSameTree(p->right, q->right)) {
        return false;
    }
    return true;
}
struct testdata {
    vector<int> p;
    vector<int> q;
};
int main() {
    vector<testdata> testdata = {
        {{1, 2, 3}, {1, 2, 3}},
        {{1, 2}, {1, -1, 2}},
        {{1, 2, 1}, {1, 1, 2}},
    };
    for (auto it : testdata) {
        TreeNode *p = create_tree(it.p);
        TreeNode *q = create_tree(it.q);
        cout << boolalpha << isSameTree(p, q) << endl;
        destroy_tree(p);
        destroy_tree(q);
    }
}