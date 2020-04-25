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
int *min_ptr = nullptr;
bool isValidBST(TreeNode *root) {
    if (!root) {
        return true;
    }
    if (!isValidBST(root->left)) {
        return false;
    }
    if (min_ptr && *min_ptr >= root->val) {
        return false;
    }
    min_ptr = &root->val;
    return isValidBST(root->right);
}

int main() {
    vector<vector<int>> testdata = {
        {5, 1, 4, -1, -1, 3, 6},
        {2, 1, 3},
    };
    for (auto it : testdata) {
        TreeNode *root = create_tree(it);
        print_tree_format(root);
        cout << boolalpha << isValidBST(root) << endl;
        destroy_tree(root);
    }
}