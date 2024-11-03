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
        if (head == nullptr) return nullptr;
        if(head->next==nullptr) return head;
        if(head->next->next==nullptr) {
            ListNode *node = head->next;
            head->next->next=head;
            head->next=nullptr;
            return node;
        }
        ListNode *node1 = head;
        ListNode *node2 = head->next;
        ListNode *node3 = node2->next;
        while (node3->next != nullptr) {
            node2->next = node1;
            node1 = node2;
            node2 = node3;
            node3 = node3->next;
        }
        node2->next = node1;
        node3->next = node2;
        head->next = nullptr;
        return node3;

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
    ListNode node3(3,&node4);
    ListNode node2(2,&node3);
    ListNode head(1, &node2);
    Solution sol;
    sol.printList(&head);
    std::cout << std::endl;
    sol.printList(sol.reverseList(&head));
    return 0;
}
