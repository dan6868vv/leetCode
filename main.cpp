#include <algorithm>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        if (list1 == nullptr || list2 == nullptr) return list1 == nullptr ? list2 : list1;
        // Return and set the next pointer of the smaller node
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    void coutListNode(ListNode *list) {
        while (list != nullptr) {
            std::cout << list->val << " ";
            list = list->next;
        }
    }
};

int main() {
    Solution sol;
    ListNode node3(4);
    ListNode node2(2, &node3);
    ListNode node1(1, &node2);
    ListNode node6(4);
    ListNode node5(3, &node6);
    ListNode node4(1, &node5);
    sol.coutListNode(&node1);
    std::cout << '\n';
    sol.coutListNode(&node4);
    std::cout << '\n';
    sol.coutListNode(sol.mergeTwoLists(&node1, &node4));
    return 1;
}
