
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        #level order, breath first search
        count = 0
        if root == None:
            return count
        queue = deque()
        
        queue.append(root)
        while(len(queue)>0):
            for i in range(len(queue)):#snapshot of the level, if this loop ends, it means that one level is fully traversed 
                node = queue.popleft()
                if(node.left != None):
                    queue.append(node.left)
                if(node.right != None):
                    queue.append(node.right)
            count +=1
        return count
