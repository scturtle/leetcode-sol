class MaxQuadTree(object):
    def __init__(self, matrix):
        """
        initialize your data structure here.
        :type matrix: List[List[int]]
        """
        xl = len(matrix)
        if not xl:
            return
        yl = len(matrix[0])
        if not yl:
            return
        self.s = [[0] * yl for i in range(xl)]
        c = [0] * yl
        for i in range(xl):
            for j in range(yl):
                c[j] += matrix[i][j]
                self.s[i][j] = (self.s[i][j-1] if j else 0) + c[j]

    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1,col1)..(row2,col2)], inclusive.
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        ans = self.s[row2][col2]
        if row1:
            ans -= self.s[row1-1][col2]
        if col1:
            ans -= self.s[row2][col1-1]
        if row1 and col1:
            ans += self.s[row1-1][col1-1]
        return ans
