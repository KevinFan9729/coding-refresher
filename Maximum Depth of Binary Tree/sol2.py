
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    max_height = 0
    curr = 0
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if(root==None):
            return self.max_height
        self.curr+=1
        if(self.curr>self.max_height):
            self.max_height = self.curr
        self.maxDepth(root.left)
        self.maxDepth(root.right)
        self.curr-=1
        
        return self.max_height
