#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

namespace counting_sort {
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<int> cnt(1e4 * 2 + 5);
    for (auto list_node : lists) {
      ListNode *node = list_node;
      while (node != nullptr) {
        cnt[node->val + 1e4]++;
        node = node->next;
      }
    }

    ListNode *node = nullptr;
    for (int i = cnt.size() - 1; i >= 0; i--) {
      for (int j = 0; j < cnt[i]; j++) {
        ListNode *temp = node;
        node = new ListNode(i - 1e4);
        node->next = temp;
      }
    }

    return node;
  }
};
} // namespace counting_sort

namespace min_heap {
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

    for (auto head : lists) {
      if (head)
        pq.push(head);
    }

    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (!pq.empty()) {
      ListNode *node = pq.top();
      pq.pop();

      tail->next = node;
      tail = tail->next;

      if (node->next)
        pq.push(node->next);
    }

    return dummy.next;
  }
};
} // namespace min_heap

void print_list(ListNode *node) {
  while (node != nullptr) {
    print("{}, ", node->val);
    node = node->next;
  }
}

int main() {
}