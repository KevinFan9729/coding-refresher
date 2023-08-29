
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if(root ==None):
            return 0
        #max depth is 1+ max of (left depth, right depth), the 1 means that the local root has a height of 1
        return 1+ max(self.maxDepth(root.left), self.maxDepth(root.right))
