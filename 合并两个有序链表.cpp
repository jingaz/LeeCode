#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    ListNode *head = new ListNode(0);
    ListNode *mege_list = head;
    ListNode *tmp = mege_list;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            tmp->next = l1;
            tmp = tmp->next;
            l1 = l1->next;
        } else {
            tmp->next = l2;
            tmp = tmp->next;
            l2 = l2->next;
        }
    }
    if (l1 == nullptr && l2 != nullptr) {
        tmp->next = l2;
    }
    else if (l2 == nullptr && l1!=nullptr){
        tmp->next = l1;
    }

    mege_list = mege_list->next;
    delete head;
    return mege_list;
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
    ListNode *list1 = nullptr, *list2 = nullptr;
    vector<int> num_array1 = {1,2,3};
    vector<int> num_array2 = {3,3,3};
    list1 = creat_list(num_array1);
    list2 = creat_list(num_array2);
    print_list(list1);
    print_list(list2);
    ListNode *merge_list = mergeTwoLists(list1, list2);
    print_list(merge_list);
    destroy_list(merge_list);
    delete list1;
    delete list2;
}