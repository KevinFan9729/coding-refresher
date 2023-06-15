
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //we know that the number of the nodes in the list is in the range [0,10^4]
        for (int i=0; i<=10000;i++){
            if(head==NULL){
                return false;
            }
            head=head->next;
        }
        return true;//exceeding the max length, meaning there is a circle that casues infinte loop 
    }
};
