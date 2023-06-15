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
        unordered_map<ListNode *,int> count_map;
        while(head!=NULL){
            count_map[head]++;
            if (count_map[head]>=2){
                return true;
            }
            head=head->next;
        }
        return false;
    }
};