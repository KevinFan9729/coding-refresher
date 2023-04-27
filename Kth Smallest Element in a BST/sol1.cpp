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
    int process_count=0;
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        stack<TreeNode*> st;//axillary stack
        while(true){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                root=st.top();
                ans=root->val;
                process_count++;
                if(process_count==k){
                    break;
                }
                st.pop();
                root=root->right;
            }
        }
        return ans;
    }
};