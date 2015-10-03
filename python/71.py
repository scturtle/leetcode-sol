class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        for p in path.strip('/').split('/'):
            if p == '.' or p == '':
                continue
            if p == '..':
                if stack:
                    stack.pop()
            else:
                stack.append(p)
        return '/' + '/'.join(stack)
