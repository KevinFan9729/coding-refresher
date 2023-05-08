
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> treeQueue;
        vector<vector<int>> ans;
        vector<int> levelVec;
        if(root ==NULL){
            return ans;
        }
        //depth 0
        treeQueue.push(root);
        levelVec.push_back(root->val);
        ans.push_back(levelVec);
        levelVec.clear();
        
        while(!treeQueue.empty()){
            int qSize=treeQueue.size();
            for(int i=0; i<qSize;i++){//every node in the current level, important for level order traversal 
                TreeNode* temp = treeQueue.front();
                treeQueue.pop();
                if(temp->left!=NULL){
                    treeQueue.push(temp->left);
                    levelVec.push_back(temp->left->val);
                }
                if(temp->right!=NULL){
                    treeQueue.push(temp->right);
                    levelVec.push_back(temp->right->val);
                }
            }
            if(!levelVec.empty()){
                ans.push_back(levelVec);
                levelVec.clear();
            }
        }
        return ans;
    }
};
