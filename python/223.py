class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        total = (C-A)*(D-B) + (G-E)*(H-F)
        w = min(C, G) - max(A, E)
        if w < 0:
            w = 0
        h = min(H, D) - max(B, F)
        if h < 0:
            h = 0
        return total - h*w
