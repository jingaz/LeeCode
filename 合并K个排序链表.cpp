#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *head = nullptr;
    if (lists.empty()) {
        return head;
    }
    head = new ListNode(0);
    ListNode *tmp = head;
    while (true) {
        long small_num = INT64_MAX;
        int small_index = -1;
        for (int i = 0; i < lists.size(); i++) {

            if (lists[i] != nullptr) {
                if (small_num > lists[i]->val) {
                    small_num = lists[i]->val;
                    small_index = i;
                };
            }
        }
        if (small_index == -1) {
            break;
        } else {
            tmp->next = lists[small_index];
            tmp = tmp->next;
            lists[small_index] = tmp->next;
        }
    }
    tmp = head;
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
        ;
    } else {
        cout << head->val << " -> ";
        return print_list(head->next);
    }
}

int main() {

    vector<vector<int>> num_array = {
        {1, 2, 3}, {1, 3, 4}, {2, 6}, {0}, {1}, {1},
    };
    vector<ListNode *> Lists;
    for (auto it : num_array) {
        Lists.push_back(creat_list(it));
    }
    ListNode *merge_list = mergeKLists(Lists);
    print_list(merge_list);
    destroy_list(merge_list);
}