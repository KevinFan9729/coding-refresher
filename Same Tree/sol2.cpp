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
    bool check(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL){
            return true;
        }
        if(q==NULL || p==NULL){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        return true;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if(!check(p,q)){
            return false;
        }
        queue<TreeNode*> nodeQueueP;
        queue<TreeNode*> nodeQueueQ;
        nodeQueueP.push(p);
        nodeQueueQ.push(q);
        while(!nodeQueueP.empty()){
            p=nodeQueueP.front();
            q=nodeQueueQ.front();
            nodeQueueP.pop();
            nodeQueueQ.pop();

            if(!(check(p,q))){
                return false;
            }
            if(p!=NULL){
                if(!check(p->left,q->left)){
                    return false;
                }
                if(p->left!=NULL){
                    nodeQueueP.push(p->left);
                    nodeQueueQ.push(q->left);
                }

                if(!check(p->right,q->right)){
                    return false;
                }
                if(p->right!=NULL){
                    nodeQueueP.push(p->right);
                    nodeQueueQ.push(q->right);
                }

            }

        }
        return true;
    }
};