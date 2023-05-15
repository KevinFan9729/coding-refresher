/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans = true;
    void helper(TreeNode* p, TreeNode* q){
        // if (p->val==q->val){
        //     return;
        // }
        if (p==NULL && q!=NULL){
            ans=false;
            return;
        }
        if (p!=NULL && q==NULL){
            ans=false;
            return;
        }
        if (p==NULL && q==NULL){
            return;
        }
        
        if (p->val!=q->val){
            ans=false;
            return;
        }

        helper(p->left,q->left);
        helper(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        helper(p,q);
        return  ans;
    }
};
