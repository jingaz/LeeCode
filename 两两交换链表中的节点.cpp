#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        return head;
    }
    ListNode *first = head;
    ListNode *second = head->next;
    second->next = swapPairs(second->next);
    first->next = second->next;
    second->next = first;
    head = second;
    return head;
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
    } else {
        cout << head->val << " -> ";
        return print_list(head->next);
    }
}

int main() {

    vector<vector<int>> num_array = {
        {1, 2, 3}, {1, 3, 4, 6, 8, 9}, {2, 5, 6, 8}, {0}, {}, {5, 7, 8},
    };
    for (auto it : num_array) {
        ListNode *tmp = creat_list(it);
        print_list(tmp);
        ListNode *lists = swapPairs(tmp);
        print_list(lists);
        destroy_list(lists);
    }
}