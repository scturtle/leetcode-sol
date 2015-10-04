class Solution(object):
    def buildTree(self, inorder, postorder, il=0, ir=None, pl=0, pr=None):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        pr = len(postorder) if pr is None else pr
        ir = len(inorder) if ir is None else ir
        if pl == pr:
            return None
        rt = postorder[pr-1]
        i = inorder.index(rt, il) - il
        root = TreeNode(rt)
        root.left = self.buildTree(inorder, postorder, il, il+i, pl, pl+i)
        root.right = self.buildTree(inorder, postorder, il+i+1, ir, pl+i, pr-1)
        return root
