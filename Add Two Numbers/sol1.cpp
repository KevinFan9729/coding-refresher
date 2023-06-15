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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int carrayout =0;
       ListNode* p3= new ListNode(0);
       int l1v;
       int l2v;
       int localAns;
       ListNode* ans = p3;
        while(l1!=NULL || l2!=NULL || carrayout==1){
            if(l1==NULL){
                l1v=0;
            }else{
                l1v = l1->val;
            }
            if(l2==NULL){
                l2v=0;
            }else{
                l2v = l2->val;
            }
            localAns = l1v+l2v+carrayout;
            
            if((localAns>=10 || (l1!=NULL && l1->next!=NULL) || (l2!=NULL && l2->next!=NULL))){
                p3->next = new ListNode(0);
            }
            carrayout= localAns/10;
            localAns = localAns%10;
            p3->val = localAns;
            p3=p3->next;
            if(l1!=NULL){
                l1=l1->next;
            }
            if(l2!=NULL){
                l2=l2->next;
            }
        }
        return ans;
    }
};
