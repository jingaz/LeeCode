#include <iostream>
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
    head = nullptr;
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
ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m==n){
      return head;
    }
    ListNode *root = new ListNode(0);
    ListNode *pre = root, *flag1 = nullptr, *flag2 = nullptr;
    pre->next = head;
    ListNode *tmp = head;
    int cnt = 1;
    while (cnt <= m) {
        if (cnt == m) {
            flag1 = pre;
            flag2 = tmp;
            break;
        }
        tmp = tmp->next;
        pre = pre->next;
        cnt++;
    }
    while (cnt <= n) {
        if (cnt == n) {
            flag2->next = tmp->next;
            tmp->next = pre;
            flag1->next = tmp;
            break;
        }
        auto *re_head = tmp->next;
        tmp->next = pre;
        pre = tmp;
        tmp = re_head;
        cnt++;
    }
    head = root->next;
    delete root;
    return head;
}
struct testdata {
    vector<int> nums;
    int m;
    int n;
};
int main() {
    vector<testdata> data = {
        {{1, 2, 3, 4, 5}, 2, 4},
        {{1, 2, 3, 4, 5}, 1, 1},
        {{1,2}, 1, 2},
    };
    for (auto it : data) {
        ListNode *tmp = creat_list(it.nums);
        print_list(tmp);
        tmp = reverseBetween(tmp, it.m, it.n);
        print_list(tmp);
        destroy_list(tmp);
    }
}