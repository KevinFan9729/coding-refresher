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
        ListNode* temp = head;
        while(temp!=nullptr){
            temp=temp->next;
            len+=1;
        }
        int num_to_iter = len/2;
        while(num_to_iter!=0){
            head=head->next;
            num_to_iter--;
        }
        return head;
    }
};
