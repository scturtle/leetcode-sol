# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return "None"
        return "({},{},{})".format(
            root.val,
            self.serialize(root.left),
            self.serialize(root.right))

    @staticmethod
    def _d(s, i):
        if s[i] == 'N':
            return None, i+4
        else:
            j = s.index(',', i)
            t = TreeNode(int(s[i+1:j]))
            t.left, j = Codec._d(s, j+1)
            t.right, j = Codec._d(s, j+1)
            return t, j+1

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        return self._d(data, 0)[0]
