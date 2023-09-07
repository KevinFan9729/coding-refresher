# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    #O(n^2) solution
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root ==None:
            return True
        leftDepth = self.findHeight(root.left)
        rightDepth = self.findHeight(root.right)
        if(abs(leftDepth-rightDepth)>1):
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
    
    def findHeight(self, root: Optional[TreeNode]):
        if(root ==None):
            return 0
        return 1+ max(self.findHeight(root.left),self.findHeight(root.right))