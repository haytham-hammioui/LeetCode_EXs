#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rest = 0;
        ListNode *res = nullptr;
        ListNode *curr_res = nullptr;
        ListNode *curr_1 = l1;
        ListNode *curr_2 = l2;
        int a = 0, b = 0;
        while(curr_1 || curr_2 || rest){
            if(curr_1)
                a = curr_1->val;
            else
                a = 0;
            if(curr_2)
                b = curr_2->val;
            else
                b = 0;
            int sum = a + b + rest;
            ListNode *newNode = new ListNode(sum % 10);
            if (res == nullptr) {
                res = newNode;
                curr_res = newNode;
            } else {
                curr_res->next = newNode;
                curr_res = curr_res->next;
            }
            rest = sum / 10;
            if(curr_1)
                curr_1 = curr_1->next;
            if(curr_2)
                curr_2 = curr_2->next;
        }
        return res;
    }
};

int main() {
    Solution solution;

    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = solution.addTwoNumbers(l1, l2);

    std::cout << "Resultant linked list: ";
    while (result) {
        std::cout << result->val;
        if (result->next) std::cout << " -> ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}