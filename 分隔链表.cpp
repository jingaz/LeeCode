#include <iostream>
#include <queue>
#include <vector>
using namespace std;
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
ListNode *partition(ListNode *head, int x) {
    ListNode *left = nullptr, *left_head = nullptr;
    ListNode *right = nullptr, *right_head = nullptr;
    ListNode *tmp = head;
    ListNode *index = nullptr;
    while (tmp) {
        index = tmp->next;
        tmp->next = nullptr;
        if (tmp->val < x) {
            if (left) {
                left->next = tmp;
                left = left->next;
            } else {
                left = tmp;
                left_head = left;
            }
        } else {
            if (right) {
                right->next = tmp;
                right = right->next;
            } else {
                right = tmp;
                right_head = right;
            }
        }
        tmp = index;
    }
    if (left) {
        left->next = right_head;
    } else {
        return right_head;
    }
    return left_head;
}
struct testdata {
    vector<int> list;
    int target;
};
int main() {
    vector<testdata> data = {
        {{1, 4, 3, 2, 5, 2}, 3},
        {{1, 1, 1, 1}, 2},
        {{1, 1, 1, 1}, 1},
    };
    for (auto it : data) {
        ListNode *head = creat_list(it.list);
        print_list(head);
        print_list(partition(head, it.target));
        destroy_list(head);
    }
}