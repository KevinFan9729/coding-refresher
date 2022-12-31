/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=nullptr){
            slow=slow->next;
            if (fast->next->next!=nullptr){
                fast = fast->next->next;
            }else{
                fast = fast->next;
            }
        }
        return slow;
    }
};
