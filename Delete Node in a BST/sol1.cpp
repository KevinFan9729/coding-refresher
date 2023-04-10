
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
    TreeNode* findmin(TreeNode * root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    // Remove a node and return the root of the tree.
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL) {
            return NULL;
        }
        if (key > root->val) { 
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {//key==root->val
            if (root->left == NULL) {//one child
                return root->right;
            } else if (root->right == NULL) {//one child
                return root->left;
            } else {//two children
                TreeNode* minNode = findmin(root->right);
                root->val = minNode->val;
                root->right = deleteNode(root->right, minNode->val);
            }
        }
        return root;
    }
};
