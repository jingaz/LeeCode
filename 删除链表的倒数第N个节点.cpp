#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (n == 0 || head == nullptr) {
        return head;
    }

    ListNode *left = head, *right = head;
    bool del_tail = (n == 1) ? true : false;

    if (del_tail) {
        //只有一个结点
        if (right->next == nullptr) {
            delete right;
            return nullptr;
        }
        //只有两个结点
        if (right->next->next == nullptr) {
            delete right->next;
            right->next = nullptr;
            return right;
        }
        //超过两个结点
        do {
            right = right->next;
        } while (right->next->next!= nullptr);

        delete right->next;
        right->next = nullptr;
        return head;
    }
    ListNode *new_head = new ListNode(0);
    new_head->next = head;
    head = new_head;
    left = head;
    right = head;
    for (int i = 1; i <= n; i++) {
      if (right == nullptr) {
        return head;
      }
      right = right->next;
    }
    while (right != nullptr && right->next != nullptr) {
        right = right->next;
        left = left->next;
    }

    ListNode *tmp = left->next;
    left->next = tmp->next;
    delete tmp;

    head = head->next;
    delete new_head;

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
        ;
    } else {
        cout << head->val << " -> ";
        return print_list(head->next);
    }
}

int main() {
    ListNode *head = nullptr;
    vector<int> num_array = {1,2,3};
    head = creat_list(num_array);
    cout << "before:" << endl;
    print_list(head);
    head = removeNthFromEnd(head, 2);
    cout << "after:" << endl;
    print_list(head);
    destroy_list(head);
}