#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr) {
        return head;
    }
    ListNode *left = head, *right = head;
    int i = 0;
    while (i < k) {
        if (nullptr == right->next) {
            right = head;
            i++;
            k;
            k %= i;
            i = 0;
            continue;
        }
        right = right->next;
        i++;
    }
    if (left == right) {
        return head;
    }
    while (right->next != nullptr) {
        left = left->next;
        right = right->next;
    }
    ListNode *new_head = left->next;
    left->next = nullptr;
    right->next = head;
    return new_head;
}

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
        ;
    } else {
        cout << head->val << " -> ";
        return print_list(head->next);
    }
}
struct testdata {
    vector<int> num_array;
    int k;
};
int main() {
    vector<testdata> data = {
        {{1, 2, 3, 4, 5}, 2}, {{1, 2, 3, 4}, 4}, {{1, 2, 3}, 2000000000}};
    for (auto it : data) {
        ListNode *list = creat_list(it.num_array);
        print_list(list);
        ListNode *rotate_list = rotateRight(list, it.k);
        print_list(rotate_list);
        destroy_list(rotate_list);
    }
}