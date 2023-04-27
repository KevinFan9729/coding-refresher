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
    int ans = 0;
    int process_count = 0;
    void inorder(TreeNode* root, int k){
        int temp;
        if(root ==NULL){
            return;
        }
        inorder(root->left, k);
        temp = root->val;
        process_count++;
        if(process_count==k){
            ans=temp;
            return;
        }
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};