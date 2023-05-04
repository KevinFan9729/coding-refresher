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
    int pre_index = 0;// track the root node
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int i, int j) {
        if (i > j) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[pre_index]);
        int temp =inorder.size();
        int split = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[pre_index] == inorder[i]) {
                split = i;
                break;
            }
        }
        pre_index++;
        
        root->left = build(preorder, inorder, i, split - 1);
        root->right = build(preorder, inorder, split + 1, j);
        
        return root;
    }
};