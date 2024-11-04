#include <algorithm>
#include <iostream>
#include <vector>


struct ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head->next==nullptr) return false;
        std::vector<std::reference_wrapper<ListNode>> refList;
        int i=0;
        while(head->next!=nullptr) {
            if(i>10000) return true;
            i++;
            head=head->next;

        }
        return false;
    }
};

int main() {
    Solution sol;

    ListNode node2(2);
    ListNode node0(0);
    ListNode node4(4);
    ListNode node3(3);
    node2.next=&node0;
    node0.next=&node4;
    node4.next=&node3;
    node3.next=&node2;
    // std::cout << sol.hasCycle(&node3) ? "True" : "Flase";
    if(sol.hasCycle(&node3)) std::cout << "TRUE" << std::endl;
    else std::cout << "FALSE" << std::endl;
    return 1;
}
