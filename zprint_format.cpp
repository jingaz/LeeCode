#include <iostream>
#include <vector>
using namespace std;

void print_ret(vector<int> ret) {
    cout << "  [";
    for (auto i : ret) {
        cout << i << ", ";
    }
    cout << "\b\b]" << endl;
}

void print_ret(vector<vector<int>> ret) {
    cout << "[" << endl;
    for (auto it : ret) {
        cout << "  [";
        for (auto i : it) {
            cout << i << ", ";
        }
        cout << "\b\b]" << endl;
    }
    cout << "]" << endl;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct ListNode *creat_list(vector<int> num_array) {
    if (num_array.empty()) {
        return nullptr;
    }
    ListNode *head = new ListNode(num_array[0]);
    ListNode *tmp = head;
    for (int i = 1; i < num_array.size(); i++) {
        tmp->next = new ListNode(num_array[i]);
        tmp = tmp->next;
    }
    return head;
}
void destroy_list(ListNode *head) {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        delete head;
    } else {
        destroy_list(head->next);
        delete head;
    }
}

void print_list(struct ListNode *head) {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        cout << head->val << endl;
    } else {
        cout << head->val << " -> ";
        return print_list(head->next);
    }
}