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
        stack<int> s;
        
        ListNode* b=head;
        ListNode* t=head;
        int n=1;
        
        
        s.push(b->val);
        while(b->next != nullptr){
            b=b->next;
            s.push(b->val);
            n++;
        }
        
        if(n==1){
            return true;
        }
        for(int i=1;i<=n/2;i++){//we only need to check half becasue palindrome linked list are inversely symmetrical 
            if(t->val != s.top()){
                return false;
            }
            
            t=t->next;
            s.pop();
        }
        
        return true;
    }
};
