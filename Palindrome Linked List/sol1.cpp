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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        std::vector<int> first = {};
        std::vector<int> second = {};
        if (fast->next==nullptr){//linked list has a length of 1
            return true;
        }
        first.push_back(slow->val);
        while(fast->next!=nullptr){
            if (fast->next->next!=nullptr){
                slow = slow->next;
                fast = fast->next->next;
                first.push_back(slow->val);
            }else{
                break;//second last node break 
            }
        }
        while(slow->next!=nullptr){
            slow=slow->next;
            second.push_back(slow->val);
        }
        int len_1 = first.size();
        int len_2 = second.size();
        if((len_1+len_2)%2==1){//linked list has an odd length
            first.pop_back();
            for(int i = 0; i<len_2; i++){
                if(first[len_2-1-i]!=second[i]){
                    return false;
                }
            }
        }else{
            for(int i = 0; i<len_1; i++){
                if(first[len_1-1-i]!=second[i]){
                    return false;
                }
            }   
        }
       return true; 
    }
};