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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode *res = nullptr;
        ListNode *curr_res = nullptr;
        while(curr1 && curr2){
            ListNode *newNode = nullptr;
            if(curr1->val <= curr2->val){
                newNode = curr1;
                curr1 = curr1->next;
            }
            else{
                newNode = curr2;
                curr2 = curr2->next;
            }
            if (res == nullptr) {
                res = newNode;
                curr_res = newNode;
            } else {
                curr_res->next = newNode;
                curr_res = newNode;
            }
        }
        if(curr1){
            if (res == nullptr) {
                res = curr1;
            }
            else
                curr_res->next = curr1;
        }
        if(curr2){
            if (res == nullptr) {
                res = curr2;
            }
            else
                curr_res->next = curr2;
        }
        return res;
    }
};

int main() {
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    while (mergedList) {
        std::cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    std::cout << std::endl;

    return 0;
}