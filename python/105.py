class Solution(object):
    def buildTree(self, preorder, inorder, pl=0, pr=None, il=0, ir=None):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        pr = len(preorder) if pr is None else pr
        ir = len(inorder) if ir is None else ir
        if pl == pr:
            return None
        rt = preorder[pl]
        i = inorder.index(rt, il) - il
        root = TreeNode(rt)
        root.left = self.buildTree(preorder, inorder, pl+1, pl+1+i, il, il+i)
        root.right = self.buildTree(preorder, inorder, pl+1+i, pr, il+i+1, ir)
        return root
