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
    ListNode *reverseList(ListNode *head) {
        if (head->next->next == nullptr) {
            head->next->next = head;
            head->next = nullptr;
        } else if (head->next == nullptr) {
            
        } else reverseList(head->next);
    }

    void printList(ListNode *head) {
        std::cout << head->val << " ";
        while (head->next != nullptr) {
            head = head->next;
            std::cout << head->val << " ";
        }
    }
};

int main() {
    ListNode node5(5);
    ListNode node4(4, &node5);
    ListNode node3(3, &node4);
    ListNode node2(2, &node3);
    ListNode head(1, &node2);
    Solution sol;
    sol.printList(&head);
    std::cout << std::endl;
    sol.printList(sol.reverseList(&head));
    return 0;
}
