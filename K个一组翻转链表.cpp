#include <iostream>
#include <vector>

using namespace std;
void print_list(struct ListNode *);

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
void reverseAB(ListNode *PRE_A, ListNode *A, ListNode *B) {
    if (A->next == B) {
        PRE_A->next = B;
        A->next = B->next;
        B->next = A;
        return;
    }
    // AB之间至少隔了一个结点
    ListNode *tmp_l = A;
    ListNode *tmp = A->next;
    ListNode *tmp_r = tmp->next;
    while (tmp != B) {
        tmp->next = tmp_l;
        tmp_l = tmp;
        tmp = tmp_r;
        tmp_r = tmp->next;
    }
    
    PRE_A->next = tmp;
    A->next = tmp->next;
    tmp->next = tmp_l;
}
ListNode *reverseKGroup(ListNode *head, int k) {
    if (k <= 1 || head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *new_head = new ListNode(0);
    new_head->next = head;
    head = new_head;
    ListNode *a = head->next, *b = head;
    for (int i = 0; i < k && b != nullptr; i++) {
        b = b->next;
    }
    if (b == nullptr) {
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
    ListNode *pre_a = head;
    do {
        reverseAB(pre_a, a, b);
         b = a;
         a = pre_a->next;
        for (int i = 0; i < k && b != nullptr; i++) {
            b = b->next;
            pre_a = a;
            a = a->next;
        }
    } while (b != nullptr);

    ListNode *tmp = head;
    head = head->next;
    delete tmp;
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
        ListNode *lists = reverseKGroup(tmp, 16);
        print_list(lists);
        destroy_list(lists);
    }
}