#include <iostream>
#include <stack>
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
        cout << "0, ";
        return;
    }
    print_tree(tree->left);
    cout << tree->val << ", ";
    print_tree(tree->right);
}
void print_tree_format(TreeNode *&tree) {
    cout << "[  ";
    print_tree(tree);
    cout << "\b\b  ]" << endl;
}
TreeNode *create_tree(vector<int> nums) {
    if (nums.empty() || nums.front() == -1) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(nums[0]);
    nums.erase(nums.begin());
    if (nums.empty()) {
        return root;
    }
    root->left = create_tree(nums);
    nums.erase(nums.begin());
    if (nums.empty()) {
        return root;
    }
    root->right = create_tree(nums);
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

TreeNode *copy_tree(TreeNode *tree) {
    TreeNode *root = nullptr;
    if (!tree) {
        return root;
    }
    root = new TreeNode(tree->val);
    root->left = copy_tree(tree->left);
    root->right = copy_tree(tree->right);
    return root;
}

vector<TreeNode *> generate(int left, int right) {
    vector<TreeNode *> ans;
    if (left > right) {
        ans.push_back(nullptr);
        return ans;
    }
    for (int i = left; i <= right; i++) {
        vector<TreeNode *> left_nodes = generate(left, i - 1);
        vector<TreeNode *> right_nodes = generate(i + 1, right);
        for (TreeNode *left_node : left_nodes) {
            for (TreeNode *right_node : right_nodes) {
                TreeNode *t = new TreeNode(i);
                t->left = left_node;
                t->right = right_node;
                ans.push_back(t);
            }
        }
    }
    return ans;
}
vector<TreeNode *> generateTrees(int n) {
    if (n)
        return generate(1, n);
    else
        return vector<TreeNode *>{};
}
struct testdata {
    vector<int> trees;
    vector<int> ans;
};

int main() {
    vector<int> data = {
        //2,
        1, 2, 3, 4, 
        5,
    };
    for (auto it : data) {
        auto ret = generateTrees(it);
        for (auto &tree : ret) {
            print_tree_format(tree);
        }        
        ret.clear();
    }
}