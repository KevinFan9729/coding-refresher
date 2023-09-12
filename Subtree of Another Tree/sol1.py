# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if root == None:
            return False
        check = self.isSameTree(root, subRoot)
        if check == True:
            return True
        left_sub = self.isSubtree(root.left, subRoot)
        right_sub = self.isSubtree(root.right, subRoot)
        return left_sub or right_sub
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p == None or q==None:
            if p == q:
                return True
            else:
                return False
        if p.val == q.val:
            left_check = self.isSameTree(p.left, q.left)
            right_check = self.isSameTree(p.right, q.right)
            return left_check and right_check
        else:
            return False
