
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
    ListNode* reverseList(ListNode* head) {
        vector<int> temp_vec;
        ListNode* temp = head;//temp pointer that points to the singly linked list
        while(temp!=nullptr){
            temp_vec.push_back(temp->val);
            temp=temp->next;
        }
        temp = head;
        for(int i=temp_vec.size()-1;i>=0;i--){
            temp->val=temp_vec[i];
            temp=temp->next;
        }
        return head;
    }
};
