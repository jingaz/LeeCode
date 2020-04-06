#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
struct node {
    friend bool operator<(node n1, node n2) {
        return n1.priority > n2.priority;
    }
    int priority;
    int value;
};
int main() {
    const int len = 5;
    int i;
    int a[len] = {3, 5, 9, 6, 2};
    //示例1：从大到小输出
    priority_queue<int> qi;
    for (i = 0; i < len; i++)
        qi.push(a[i]);
    for (i = 0; i < len; i++) {
        cout << qi.top() << " ";
        qi.pop();
    }
    cout << endl;
    //示例2：从小到大输出
    priority_queue<int, vector<int>, greater<int>> qi2;
    for (i = 0; i < len; i++)
        qi2.push(a[i]);
    for (i = 0; i < len; i++) {
        cout << qi2.top() << " ";
        qi2.pop();
    }
    cout << endl;
    //示例3：按优先级输出
    priority_queue<node> qn;
    node b[len];
    b[0].priority = 1;
    b[0].value = 1;
    b[1].priority = 1;
    b[1].value = 2;
    b[2].priority = 1;
    b[2].value = 3;
    b[3].priority = 1;
    b[3].value = 4;
    b[4].priority = 1;
    b[4].value = 5;

    for (i = 0; i < len; i++)
        qn.push(b[i]);
    cout << "优先级" << '\t' << "值" << endl;
    for (i = 0; i < len; i++) {
        cout << qn.top().priority << '\t' << qn.top().value << endl;
        qn.pop();
    }
    for (int i = 0;i<9;i++){
      cout << "i = " << i << " i/3 = " << i / 3 << endl;
    }
    return 0;
}