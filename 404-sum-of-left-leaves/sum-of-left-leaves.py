# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ans=0
    def solve(self,root,chk):
        if(root is None):
            return None
        if(root.left==None and root.right==None and chk==True):
            self.ans+=root.val
        self.solve(root.left,True)
        self.solve(root.right,False)
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if(root is None):
            return 0
        
        self.solve(root,False)
        return self.ans
    
        