# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solution(self,root,ans):
        if(root == None):
            return 0;
        ans = (ans*10)+root.val
        if(root.left==None and root.right==None):
            return ans
        return self.solution(root.left,ans)+self.solution(root.right,ans)

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        ans=self.solution(root,0)
        return ans
        