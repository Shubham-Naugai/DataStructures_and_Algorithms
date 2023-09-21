class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        mat = [[None for i in range(n)] for _ in range(n)]
        
        left, right = 0, n
        top, bottom = 0, n
        val = 1
        while left < right and top < bottom:
            # put value in the top row
            for i in range(left, right):
                mat[top][i] = val
                val += 1
            top += 1
            
            # put value in the right col
            for i in range(top, bottom):
                mat[i][right-1] = val
                val += 1
            right -= 1
            
            # if not (left < right and top < bottom):
            #     break
            # put value in the bottom row
            for i in range(right-1, left-1, -1):
                mat[bottom-1][i] = val
                val += 1
            bottom -= 1
            
            # put value in the left col
            for i in range(bottom-1, top-1, -1):
                mat[i][left] = val
                val += 1
            left += 1
        return mat