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

void print_tree(TreeNode *tree) {
    if (!tree) {
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
        cout << i << ", ";
    }
    cout << "\b\b  ]" << endl;
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    if (!root) {
        return ret;
    }
    stack<TreeNode *> st;
    stack<TreeNode *> cache;
    st.push(root->right);
    TreeNode *cache_tmp = new TreeNode(root->val);
    cache.push(cache_tmp);
    st.push(cache_tmp);
    st.push(root->left);
    while (!st.empty()) {
        TreeNode *tmp = st.top();
        st.pop();
        if (!tmp) {
            continue;
        }
        if (!(tmp->left) && !(tmp->right)) {
            ret.emplace_back(tmp->val);
            continue;
        }
        st.push(tmp->right);
        TreeNode *cache_tmp = new TreeNode(tmp->val);
        cache.push(cache_tmp);
        st.push(cache_tmp);
        st.push(tmp->left);
    }
    while(!cache.empty()){
        TreeNode *cache_tmp = cache.top();
        cache.pop();
        delete cache_tmp;
    }
    return ret;
}
struct testdata {
    vector<int> trees;
    vector<int> ans;
};

int main() {
    vector<testdata> data = {
        {{1, -1, 2, 3}, {1, 3, 2}},
    };
    for (auto it : data) {
        TreeNode *tree = create_tree(it.trees);
        print_tree_format(tree);
        print_ret(inorderTraversal(tree));
        destroy_tree(tree);
    }
}