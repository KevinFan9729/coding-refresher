# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    diameter = 0
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.longestPath(root)
        return self.diameter
    def longestPath(self, root: Optional[TreeNode]):
        #dfs
        if root == None:
            return 0
        leftPath = self.longestPath(root.left)
        rightPath = self.longestPath(root.right)
        self.diameter = max(self.diameter, leftPath+rightPath)
        # return the longest one between left_path and right_path; 
        # remember to add 1 for the path connecting the node and its parent
        return 1+max(leftPath,rightPath)
        