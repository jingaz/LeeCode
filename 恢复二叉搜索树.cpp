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

// 中序序遍历
void print_tree(TreeNode *tree) {
    if (!tree || tree->val == -1) {
        cout << "null, ";
        return;
    }
    print_tree(tree->left);
    cout << tree->val << ", ";
    print_tree(tree->right);
}
void print_tree_format(TreeNode *tree) {
    cout << "[  ";
    print_tree(tree);
    cout << "\b\b  ]" << endl;
}
void destroy_tree(TreeNode *tree) {
    if (!tree) {
        return;
    }
    destroy_tree(tree->left);
    destroy_tree(tree->right);
    delete tree;
    tree = nullptr;
}
void print_ret(vector<int> ret) {
    cout << "[  ";
    for (auto i : ret) {
        if (i != -1) {
            cout << i << ", ";
        } else {
            cout << "null, ";
        }
    }
    cout << "\b\b  ]" << endl;
}
TreeNode *min_ptr = nullptr, *ptr1 = nullptr, *ptr2 = nullptr;
void help(TreeNode *root) {
    if (!root) {
        return;
    }
    help(root->left);
    if (min_ptr && min_ptr->val > root->val) {
        if (!ptr1) {
            ptr1 = min_ptr;
        }
        ptr2 = root;
    }
    min_ptr = root;
    help(root->right);
}
void recoverTree(TreeNode *root) {
    help(root);
    int tmp = ptr1->val;
    ptr1->val = ptr2->val;
    ptr2->val = tmp;
}

int main() {
    vector<vector<int>> data = {
        {1, 3, -1, -1, 2},
    };
    for (auto it : data) {
        TreeNode *tree = create_tree(it);
        print_tree_format(tree);
        recoverTree(tree);
        print_tree_format(tree);
        destroy_tree(tree);
    }
}