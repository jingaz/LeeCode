#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void destroy_list(ListNode *head) {
    if (head == nullptr) {
        return;
    }
    destroy_list(head->next);
    delete head;
    head = nullptr;
}
ListNode *deleteDuplicates(ListNode *head) {
    queue<ListNode *> que;
    ListNode *tmp = head;
    ListNode *index = tmp;
    bool flag = false;
    while (tmp) {
        index = tmp->next;
        tmp->next = nullptr;
        if (index && tmp->val == index->val) {
            delete tmp;
            flag = true;
        } else {
            if (!flag) {
                que.push(tmp);
            } else {
                delete tmp;
            }
            flag = false;
        }
        tmp = index;
    }
    if (que.empty()) {
        return nullptr;
    }
    head = que.front();
    que.pop();
    tmp = head;
    while (!que.empty()) {
        tmp->next = que.front();
        tmp = tmp->next;
        que.pop();
    }
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
    vector<int> num_array = {1,2,2,3,3,3,4};
    head = creat_list(num_array);
    cout << "before:" << endl;
    print_list(head);
    head = deleteDuplicates(head);
    cout << "after:" << endl;
    print_list(head);
    destroy_list(head);
}