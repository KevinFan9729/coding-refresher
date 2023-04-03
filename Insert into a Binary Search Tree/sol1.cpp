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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* nav = root;
        TreeNode* node = new TreeNode(val);
        if (root ==NULL){
            root = node;
            return root;
        }
        while (nav!=NULL){
            // prev = nav;
            if(val>nav->val){
                if(nav->right==NULL){
                    nav->right = node;
                    break;
                }
                nav = nav->right;
            }else if(val<nav->val){
                if(nav->left==NULL){
                    nav->left = node;
                    break;
                }
                nav = nav->left;
            }
        }
        return root;
    }
};