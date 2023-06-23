
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
    vector<int> path;
    int maxPath = INT_MIN;
    int path_count=1;
    int maxDepth(TreeNode* root) {
        if(root ==NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){//we are at the left node now
            if(maxPath<=path_count){
                maxPath = path_count;
            }
            path_count --;
            return maxPath;
        }
        if(root->left!=NULL){
            path_count++;
            maxDepth(root->left);
        }
        if(root->right!=NULL){
            path_count++;
            maxDepth(root->right);
        }
        path_count --;
        return maxPath;
    }
};
